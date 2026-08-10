#pragma once

#include "SettingsCatalog.h"

#include <QWidget>

class QScrollArea;

// Aero7's replacement landing page for groups that previously opened the KDE
// System Settings application.  It owns the public wording, visibly records
// the original KDE setting name, and can progressively swap each KCM bridge
// for a native implementation without changing navigation or documentation.
class SettingsHubPage : public QWidget {
    Q_OBJECT

public:
    explicit SettingsHubPage(SettingsSection section, QScrollArea *sidebar,
                             const QString &titleOverride = {},
                             const QString &descriptionOverride = {},
                             QWidget *parent = nullptr);

signals:
    void navigateRequested(PageId page);
    void appletRequested(const QString &id);

private:
    void activate(const SettingDefinition &setting);
};
