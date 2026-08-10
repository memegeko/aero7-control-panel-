#pragma once

#include <QWidget>

#include "PageId.h"

// Aero7's internal first-steps hub. The page itself contains no privileged
// operations: working tasks ask MainWindow to navigate to existing pages,
// while unfinished tasks explain that their native module is still planned.
class GettingStartedPage : public QWidget {
    Q_OBJECT

public:
    explicit GettingStartedPage(QWidget *parent = nullptr);

signals:
    void navigateRequested(PageId page);

private:
    void openOfficialWebsite();
};
