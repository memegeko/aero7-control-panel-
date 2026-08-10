#include "GettingStartedPage.h"

#include <QApplication>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QSet>
#include <QStringList>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QIcon::setThemeName(QStringLiteral("breeze"));
    GettingStartedPage page;
    page.resize(1120, 720);
    page.show();
    app.processEvents();

    const QPixmap renderedPage = page.grab();
    if (renderedPage.isNull())
        return 1;
    const QString screenshotPath = qEnvironmentVariable("AERO7_TEST_SCREENSHOT");
    if (!screenshotPath.isEmpty() && !renderedPage.save(screenshotPath))
        return 2;

    QSet<QString> visibleText;
    const auto labels = page.findChildren<QLabel *>();
    for (const QLabel *label : labels) {
        if (!label->text().isEmpty())
            visibleText.insert(label->text());
    }

    const QStringList requiredText = {
        QStringLiteral("Welcome to Aero7"),
        QStringLiteral("Learn more about Aero7"),
        QStringLiteral("Learn about Aero7"),
        QStringLiteral("Personalize Aero7"),
        QStringLiteral("Install applications"),
        QStringLiteral("Connect to a network"),
        QStringLiteral("System & Updates"),
        QStringLiteral("Application Compatibility"),
        QStringLiteral("Back up your files"),
        QStringLiteral("User Accounts"),
        QStringLiteral("Display Settings"),
    };

    for (const QString &text : requiredText) {
        if (!visibleText.contains(text))
            return 3;
    }

    if (page.metaObject()->indexOfSignal("navigateRequested(PageId)") < 0)
        return 4;

    bool queuedNavigationDelivered = false;
    QObject::connect(&page, &GettingStartedPage::navigateRequested, &page,
                     [&queuedNavigationDelivered](PageId pageId) {
                         queuedNavigationDelivered = pageId == PageId::Personalization;
                     }, Qt::QueuedConnection);
    page.navigateRequested(PageId::Personalization);
    app.processEvents();

    return queuedNavigationDelivered ? 0 : 5;
}
