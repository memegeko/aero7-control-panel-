#include "PageRegistry.h"
#include "SettingsCatalog.h"

#include <QSet>

int main()
{
    const auto &settings = SettingsCatalog::all();
    if (settings.size() < 50)
        return 1;

    QSet<QString> keys;
    const QSet<QString> nativeReplacementKeys = {
        QStringLiteral("personalization"), QStringLiteral("sound"),
        QStringLiteral("network-status"), QStringLiteral("power"),
        QStringLiteral("accounts"),
    };
    QSet<QString> nativeReplacementsFound;
    bool foundNetworkManagement = false;
    bool foundSpelling = false;
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
            // Plasma 6 has both kcm_* ids and ids such as
            // kcmspellchecking, so require the stable kcm prefix rather than
            // the old underscore convention.
            if (!setting.kdeModule.startsWith(QStringLiteral("kcm"))
                || setting.command.size() != 2
                || setting.command.at(0) != QStringLiteral("kcmshell6")
                || setting.command.at(1) != setting.kdeModule)
                return 5;
        }
        if (setting.kdeModule == QStringLiteral("kcm_networkmanagement"))
            foundNetworkManagement = true;
        if (setting.kdeModule == QStringLiteral("kcmspellchecking"))
            foundSpelling = true;
        if (setting.kdeModule.contains(QStringLiteral("kwallet"),
                                       Qt::CaseInsensitive))
            return 9;
        if (nativeReplacementKeys.contains(setting.key)) {
            if (setting.status != ReplacementStatus::Native)
                return 11;
            nativeReplacementsFound.insert(setting.key);
        }
        if (setting.backend == SettingsBackend::Aero7Page
            && PageRegistry::pathFor(setting.page).isEmpty())
            return 6;
        if (setting.backend == SettingsBackend::Aero7Applet
            && setting.applet.isEmpty())
            return 7;
    }

    if (!foundNetworkManagement || !foundSpelling)
        return 10;
    if (nativeReplacementsFound != nativeReplacementKeys)
        return 12;

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
