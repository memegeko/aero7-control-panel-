#include "PageRegistry.h"
#include "SettingsCatalog.h"

#include <QSet>

int main()
{
    const auto &settings = SettingsCatalog::all();
    if (settings.size() < 50)
        return 1;

    QSet<QString> keys;
    for (const SettingDefinition &setting : settings) {
        if (setting.key.isEmpty() || setting.aeroName.isEmpty()
            || setting.kdeName.isEmpty() || setting.description.isEmpty())
            return 2;
        if (keys.contains(setting.key))
            return 3;
        keys.insert(setting.key);

        const LinkTarget target = SettingsCatalog::targetForSetting(setting);
        if (target.kind == LinkTarget::None || target.kind == LinkTarget::Disabled)
            return 4;

        if (setting.backend == SettingsBackend::KdeModule) {
            if (!setting.kdeModule.startsWith(QStringLiteral("kcm_"))
                || setting.command.size() != 2
                || setting.command.at(0) != QStringLiteral("kcmshell6")
                || setting.command.at(1) != setting.kdeModule)
                return 5;
        }
        if (setting.backend == SettingsBackend::Aero7Page
            && PageRegistry::pathFor(setting.page).isEmpty())
            return 6;
        if (setting.backend == SettingsBackend::Aero7Applet
            && setting.applet.isEmpty())
            return 7;
    }

    const QList<PageId> hubs = {
        PageId::DisplaySettings, PageId::NetworkSettings,
        PageId::RegionLanguage, PageId::TaskbarStartMenu,
        PageId::DefaultPrograms, PageId::InputDevices,
        PageId::StartupShutdown, PageId::WindowBehavior,
        PageId::SecurityMaintenance, PageId::StorageAdministration,
        PageId::InternetOptions, PageId::FolderOptions,
        PageId::AutoPlay, PageId::BackupRestore,
    };
    for (PageId page : hubs) {
        const QString path = PageRegistry::pathFor(page);
        if (path.isEmpty() || PageRegistry::idForPath(path) != page)
            return 8;
    }

    return 0;
}
