#include "SettingsHubPage.h"
#include "IconHelper.h"
#include "LinkLabel.h"
#include "Win7Ui.h"

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

namespace {

QString statusColor(ReplacementStatus status)
{
    switch (status) {
    case ReplacementStatus::Native:              return "#2E7D32";
    case ReplacementStatus::Partial:             return "#9A6700";
    case ReplacementStatus::CompatibilityBridge: return "#555555";
    }
    return "#555555";
}

} // namespace

SettingsHubPage::SettingsHubPage(SettingsSection section, QScrollArea *sidebar,
                                 const QString &titleOverride,
                                 const QString &descriptionOverride,
                                 QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("settingsHubPage"));
    setProperty("settingsSection", static_cast<int>(section));

    auto *content = Win7::pageScaffold(this, sidebar, 20, 760, 16);
    const QString title = titleOverride.isEmpty()
        ? SettingsCatalog::sectionTitle(section) : titleOverride;
    const QString pageDescription = descriptionOverride.isEmpty()
        ? SettingsCatalog::sectionDescription(section) : descriptionOverride;
    content->addWidget(Win7::pageTitle(title, 13, "#1A5DAB"));
    auto *intro = Win7::label(pageDescription, 9, "#333333");
    intro->setWordWrap(true);
    content->addWidget(intro);
    content->addSpacing(14);

    const auto settings = SettingsCatalog::forSection(section);
    for (const SettingDefinition &setting : settings) {
        auto *row = new QFrame;
        row->setObjectName(QStringLiteral("settingRow"));
        row->setProperty("settingKey", setting.key);
        row->setStyleSheet(
            "QFrame#settingRow { background: #FFFFFF; border: 1px solid #D4DCE7; }"
            "QFrame#settingRow:hover { background: #F4F8FD; border-color: #9CB7D5; }");

        auto *h = new QHBoxLayout(row);
        h->setContentsMargins(10, 8, 10, 8);
        h->setSpacing(12);

        auto *icon = new QLabel;
        icon->setFixedSize(32, 32);
        icon->setPixmap(resolveIcon(setting.iconName).pixmap(32, 32));
        icon->setStyleSheet("background: transparent; border: none;");
        h->addWidget(icon, 0, Qt::AlignTop);

        auto *text = new QVBoxLayout;
        text->setContentsMargins(0, 0, 0, 0);
        text->setSpacing(1);

        auto *name = new LinkLabel(setting.aeroName);
        name->setObjectName(QStringLiteral("setting-link-") + setting.key);
        name->setProperty("originalKdeName", setting.kdeName);
        name->setProperty("kdeModule", setting.kdeModule);
        Win7::setPointSize(name, 10);
        connect(name, &LinkLabel::clicked, this,
                [this, setting]() { activate(setting); });
        text->addWidget(name);

        auto *description = Win7::label(setting.description, 9, "#222222");
        description->setWordWrap(true);
        text->addWidget(description);

        const QString original = setting.kdeName.isEmpty()
            ? QStringLiteral("Original KDE name: not applicable")
            : QStringLiteral("Original KDE name: %1%2")
                  .arg(setting.kdeName,
                       setting.kdeModule.isEmpty()
                           ? QString()
                           : QStringLiteral("  ·  Module: %1").arg(setting.kdeModule));
        auto *origin = Win7::label(original, 8, "#666666");
        origin->setTextInteractionFlags(Qt::TextSelectableByMouse);
        text->addWidget(origin);
        h->addLayout(text, 1);

        auto *right = new QVBoxLayout;
        right->setContentsMargins(0, 0, 0, 0);
        right->setSpacing(4);
        auto *status = Win7::label(SettingsCatalog::statusLabel(setting.status),
                                   8, statusColor(setting.status).toUtf8().constData());
        status->setAlignment(Qt::AlignRight);
        right->addWidget(status);
        auto *button = new QPushButton(
            setting.status == ReplacementStatus::CompatibilityBridge
                ? QStringLiteral("Open setting") : QStringLiteral("Change settings"));
        button->setObjectName(QStringLiteral("setting-action-") + setting.key);
        button->setProperty("settingKey", setting.key);
        button->setProperty("originalKdeName", setting.kdeName);
        button->setProperty("kdeModule", setting.kdeModule);
        button->setCursor(Qt::PointingHandCursor);
        connect(button, &QPushButton::clicked, this,
                [this, setting]() { activate(setting); });
        right->addWidget(button);
        h->addLayout(right, 0);

        content->addWidget(row);
        content->addSpacing(6);
    }

    content->addStretch(1);
}

void SettingsHubPage::activate(const SettingDefinition &setting)
{
    switch (setting.backend) {
    case SettingsBackend::Aero7Page:
        emit navigateRequested(setting.page);
        break;
    case SettingsBackend::Aero7Applet:
        emit appletRequested(setting.applet);
        break;
    case SettingsBackend::KdeModule:
    case SettingsBackend::ExternalCommand:
        launchDetached(this, setting.command);
        break;
    }
}
