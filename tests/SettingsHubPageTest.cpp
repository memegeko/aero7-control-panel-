#include "SettingsHubPage.h"

#include <QApplication>
#include <QPushButton>
#include <QSet>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    const QList<SettingsSection> sections = {
        SettingsSection::Appearance, SettingsSection::Display,
        SettingsSection::TaskbarStartMenu, SettingsSection::WindowBehavior,
        SettingsSection::InputDevices, SettingsSection::Sound,
        SettingsSection::Network, SettingsSection::Power,
        SettingsSection::Accounts, SettingsSection::RegionLanguage,
        SettingsSection::Applications, SettingsSection::SearchHistory,
        SettingsSection::Accessibility, SettingsSection::StartupShutdown,
        SettingsSection::SecurityMaintenance,
        SettingsSection::StorageAdministration, SettingsSection::System,
    };

    int rows = 0;
    QSet<QString> renderedKeys;
    for (SettingsSection section : sections) {
        SettingsHubPage page(section, nullptr);
        page.resize(1000, 720);
        page.show();
        app.processEvents();

        const auto buttons = page.findChildren<QPushButton *>();
        for (QPushButton *button : buttons) {
            if (!button->objectName().startsWith(QStringLiteral("setting-action-")))
                continue;
            if (!button->isEnabled()
                || button->property("settingKey").toString().isEmpty()
                || button->property("originalKdeName").toString().isEmpty())
                return 1;
            renderedKeys.insert(button->property("settingKey").toString());
            ++rows;
        }
        if (buttons.isEmpty())
            return 2;
    }

    if (rows != SettingsCatalog::all().size()
        || renderedKeys.size() != SettingsCatalog::all().size())
        return 3;
    return 0;
}
