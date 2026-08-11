#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QEvent>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>
#include <QRegularExpression>
#include <QStringList>
#include <QTextStream>
#include <QTimer>
#include "MainWindow.h"
#include "IconHelper.h"
#include "SettingsCatalog.h"
#include <Aero7Qt/stylesheet.h>

// Aero7Qt's application stylesheet skins QScrollBar with the Aero look. We want
// the desktop theme's native scroll bars instead, and they cannot be rescued
// per-widget: while an app-wide stylesheet is active, Qt wraps even an
// explicitly setStyle()'d widget back into the stylesheet engine. The only
// real bypass is to remove the QScrollBar rules from the application sheet
// itself, with no rules matching, the stylesheet engine delegates scroll-bar
// rendering to the real Qt style (Breeze on KDE).
static QString withoutScrollBarRules(QString qss)
{
    // Drop comments first so a brace inside one can't derail the block scan.
    static const QRegularExpression comment(
        QStringLiteral(R"(/\*.*?\*/)"),
        QRegularExpression::DotMatchesEverythingOption);
    qss.remove(comment);

    // QSS has no nested braces: walk "selectors { body }" blocks and drop the
    // selectors mentioning QScrollBar, keeping any others sharing the block.
    QString out;
    out.reserve(qss.size());
    int pos = 0;
    while (pos < qss.size()) {
        const int open = qss.indexOf(QLatin1Char('{'), pos);
        const int close = open < 0 ? -1 : qss.indexOf(QLatin1Char('}'), open);
        if (close < 0) {                       // trailing non-block text
            out += QStringView(qss).mid(pos);
            break;
        }

        QStringList kept;
        const QStringList selectors = qss.mid(pos, open - pos).split(QLatin1Char(','));
        for (const QString &sel : selectors) {
            if (!sel.contains(QLatin1String("QScrollBar")))
                kept << sel;
        }
        if (!kept.isEmpty())
            out += kept.join(QLatin1Char(',')) + qss.mid(open, close - open + 1);
        pos = close + 1;
    }
    return out;
}

// Strips the QScrollBar rules now and again whenever they reappear: Aero7Qt
// re-applies its sheet when the desktop theme flips between Aero and
// non-Aero, which reaches us as StyleChange events. The re-strip is deferred
// with a queued single-shot: mutating the application stylesheet while a
// StyleChange is still being delivered would re-enter the style engine, and
// is a no-op once the rules are gone, so it cannot loop.
class ScrollBarUnstyler : public QObject {
public:
    explicit ScrollBarUnstyler(QApplication *app) : QObject(app), m_app(app)
    {
        strip();
        app->installEventFilter(this);
    }

    bool eventFilter(QObject *watched, QEvent *event) override
    {
        if (event->type() == QEvent::StyleChange && !m_pending
            && m_app->styleSheet().contains(QLatin1String("QScrollBar"))) {
            m_pending = true;
            QTimer::singleShot(0, this, [this]() {
                m_pending = false;
                strip();
            });
        }
        return QObject::eventFilter(watched, event);
    }

private:
    void strip()
    {
        const QString qss = m_app->styleSheet();
        const QString filtered = withoutScrollBarRules(qss);
        if (filtered != qss)
            m_app->setStyleSheet(filtered);
    }

    QApplication *m_app;
    bool m_pending = false;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setOrganizationName("controlpanel");
    app.setApplicationName("controlpanel");
    // No setApplicationDisplayName: Qt appends it to every window/dialog title.
    app.setWindowIcon(themeIcon({"preferences-system"}));

    QCommandLineParser parser;
    parser.setApplicationDescription(
        QStringLiteral("Aero7 Control Panel"));
    parser.addHelpOption();
    QCommandLineOption pageOption(
        QStringList{QStringLiteral("p"), QStringLiteral("page")},
        QStringLiteral("Open a Control Panel page directly."),
        QStringLiteral("page"));
    parser.addOption(pageOption);
    QCommandLineOption settingOption(
        QStringList{QStringLiteral("s"), QStringLiteral("setting")},
        QStringLiteral("Open a setting by its stable Aero7 catalog key."),
        QStringLiteral("key"));
    parser.addOption(settingOption);
    QCommandLineOption listSettingsOption(
        QStringLiteral("list-settings-json"),
        QStringLiteral("Print the searchable settings catalog as JSON and exit."));
    parser.addOption(listSettingsOption);
    parser.process(app);

    if (parser.isSet(listSettingsOption)) {
        QJsonArray catalog;
        for (const SettingDefinition &setting : SettingsCatalog::all()) {
            catalog.append(QJsonObject{
                {QStringLiteral("key"), setting.key},
                {QStringLiteral("name"), setting.aeroName},
                {QStringLiteral("description"), setting.description},
                {QStringLiteral("icon"), setting.iconName},
                {QStringLiteral("section"),
                 SettingsCatalog::sectionTitle(setting.section)},
                {QStringLiteral("keywords"),
                 QStringList{setting.kdeName, setting.kdeModule, setting.key}
                     .join(QLatin1Char(' '))},
            });
        }
        QTextStream(stdout) << QJsonDocument(catalog).toJson(QJsonDocument::Compact)
                            << Qt::endl;
        return 0;
    }

    const QString requestedSetting = parser.value(settingOption);
    const SettingDefinition *setting = requestedSetting.isEmpty()
        ? nullptr : SettingsCatalog::findByKey(requestedSetting);
    if (!requestedSetting.isEmpty() && !setting) {
        QTextStream(stderr) << "Unknown Aero7 setting: " << requestedSetting
                            << Qt::endl;
        return 2;
    }

    if (setting) {
        const LinkTarget target = SettingsCatalog::targetForSetting(*setting);
        if (target.kind == LinkTarget::Command && !target.command.isEmpty()) {
            const bool started = QProcess::startDetached(
                target.command.first(), target.command.mid(1));
            return started ? 0 : 3;
        }
    }

    Aero7::applyApplicationStyle(&app);
    new ScrollBarUnstyler(&app);   // native scroll bars; owned by the app

    MainWindow w;
    const QString requestedPage = parser.value(pageOption);
    if (requestedPage.compare(QStringLiteral("getting-started"),
                              Qt::CaseInsensitive) == 0) {
        w.openPage(PageId::GettingStarted);
    }
    w.show();
    if (setting) {
        const QString settingKey = setting->key;
        QTimer::singleShot(0, &w, [&w, settingKey]() {
            w.openSetting(settingKey);
        });
    }
    return app.exec();
}
