#include "GettingStartedPage.h"

#include "IconHelper.h"
#include "LinkLabel.h"
#include "Win7Ui.h"

#include <QApplication>
#include <QDesktopServices>
#include <QEnterEvent>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QLinearGradient>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QStandardPaths>
#include <QStyle>
#include <QUrl>
#include <QVBoxLayout>

#include <functional>
#include <initializer_list>

namespace {

const QUrl kOfficialWebsite(QStringLiteral("https://aero7.miku-dayo.com/"));

QIcon taskIcon(std::initializer_list<const char *> names)
{
    const QIcon icon = themeIcon(names);
    if (!icon.isNull())
        return icon;
    return QApplication::style()->standardIcon(QStyle::SP_ComputerIcon);
}

QPixmap bannerLogoPixmap(int size)
{
    // Aero7 installs a project-owned logo at the start of its SDDM branding
    // strip. Resolve it through the standard data locations so this works with
    // both /usr and staged prefixes. Never fall back to a desktop-theme
    // distributor/start icon: Aero-style icon themes may map those names to a
    // third-party operating-system logo.
    const QString path = QStandardPaths::locate(
        QStandardPaths::GenericDataLocation,
        QStringLiteral("aero7/branding/aero7-sddm-branding.png"));
    const QPixmap branding(path);
    if (!branding.isNull() && branding.height() > 0) {
        const int side = qMin(branding.width(), branding.height());
        return branding.copy(0, 0, side, side)
            .scaled(size, size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    return taskIcon({"computer", "preferences-system"}).pixmap(size, size);
}

// Compact Control Panel task row: icon, blue link title, and one short line of
// explanation. It deliberately avoids card shadows and large corner radii.
class TaskWidget final : public QFrame {
public:
    TaskWidget(const QIcon &icon, const QString &title,
               const QString &description, std::function<void()> action,
               QWidget *parent = nullptr)
        : QFrame(parent)
        , m_action(std::move(action))
    {
        setCursor(Qt::PointingHandCursor);
        setFocusPolicy(Qt::StrongFocus);
        setAccessibleName(title);
        setMinimumHeight(76);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        auto *row = new QHBoxLayout(this);
        row->setContentsMargins(8, 7, 8, 7);
        row->setSpacing(10);

        auto *iconLabel = new QLabel;
        iconLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
        iconLabel->setStyleSheet("background: transparent;");
        iconLabel->setFixedSize(48, 48);
        iconLabel->setAlignment(Qt::AlignCenter);
        iconLabel->setPixmap(icon.pixmap(48, 48));
        row->addWidget(iconLabel, 0, Qt::AlignTop);

        auto *copy = new QVBoxLayout;
        copy->setContentsMargins(0, 0, 0, 0);
        copy->setSpacing(2);

        m_title = Win7::label(title, 9, "#1F4E99");
        m_title->setAttribute(Qt::WA_TransparentForMouseEvents);
        copy->addWidget(m_title);

        auto *descriptionLabel = Win7::label(description, 8, "#333333");
        descriptionLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
        descriptionLabel->setWordWrap(true);
        copy->addWidget(descriptionLabel);
        copy->addStretch(1);

        row->addLayout(copy, 1);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        if (m_hovered || hasFocus()) {
            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing, true);
            const QRectF area = QRectF(rect()).adjusted(1.0, 1.0, -1.0, -1.0);
            QLinearGradient fill(area.topLeft(), area.bottomLeft());
            fill.setColorAt(0.0, QColor(244, 251, 255));
            fill.setColorAt(1.0, QColor(220, 239, 252));
            painter.setBrush(fill);
            painter.setPen(QPen(QColor(158, 201, 233), 1.0));
            painter.drawRoundedRect(area, 2.0, 2.0);
        }
        QFrame::paintEvent(event);
    }

    void enterEvent(QEnterEvent *event) override
    {
        setHovered(true);
        QFrame::enterEvent(event);
    }

    void leaveEvent(QEvent *event) override
    {
        setHovered(false);
        m_pressed = false;
        QFrame::leaveEvent(event);
    }

    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton) {
            m_pressed = true;
            event->accept();
            return;
        }
        QFrame::mousePressEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override
    {
        const bool activate = m_pressed && event->button() == Qt::LeftButton
                           && rect().contains(event->position().toPoint());
        m_pressed = false;
        if (activate && m_action)
            m_action();
        event->accept();
    }

    void keyPressEvent(QKeyEvent *event) override
    {
        if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter
             || event->key() == Qt::Key_Space) && m_action) {
            m_action();
            event->accept();
            return;
        }
        QFrame::keyPressEvent(event);
    }

    void focusInEvent(QFocusEvent *event) override
    {
        update();
        QFrame::focusInEvent(event);
    }

    void focusOutEvent(QFocusEvent *event) override
    {
        update();
        QFrame::focusOutEvent(event);
    }

private:
    void setHovered(bool hovered)
    {
        if (m_hovered == hovered)
            return;
        m_hovered = hovered;
        QFont font = m_title->font();
        font.setUnderline(hovered);
        m_title->setFont(font);
        update();
    }

    std::function<void()> m_action;
    QLabel *m_title = nullptr;
    bool m_hovered = false;
    bool m_pressed = false;
};

// The large welcome strip is painted from gradients and text, so it adds no
// third-party image or font asset to the repository.
class WelcomeBanner final : public QFrame {
public:
    explicit WelcomeBanner(std::function<void()> learnMore,
                           QWidget *parent = nullptr)
        : QFrame(parent)
    {
        setMinimumHeight(205);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        auto *row = new QHBoxLayout(this);
        row->setContentsMargins(26, 18, 24, 18);
        row->setSpacing(18);

        auto *logo = new QLabel;
        logo->setStyleSheet("background: transparent;");
        logo->setFixedSize(92, 92);
        logo->setAlignment(Qt::AlignCenter);
        logo->setPixmap(bannerLogoPixmap(88));
        row->addWidget(logo, 0, Qt::AlignVCenter);

        auto *copy = new QVBoxLayout;
        copy->setContentsMargins(0, 16, 0, 0);
        copy->setSpacing(4);

        auto *title = Win7::label(QStringLiteral("Welcome to Aero7"), 18,
                                  "#1D355D");
        QFont titleFont = title->font();
        titleFont.setWeight(QFont::DemiBold);
        title->setFont(titleFont);
        copy->addWidget(title);
        copy->addSpacing(3);
        copy->addWidget(Win7::label(
            QStringLiteral("\u2022 Discover what Aero7 can do"), 10, "#263C5A"));
        copy->addWidget(Win7::label(
            QStringLiteral("\u2022 Set up and personalize your computer"), 10,
            "#263C5A"));
        copy->addStretch(1);
        row->addLayout(copy, 1);

        auto *actionRow = new QHBoxLayout;
        actionRow->setContentsMargins(0, 0, 0, 0);
        actionRow->setSpacing(7);
        auto *arrow = new QLabel;
        arrow->setStyleSheet("background: transparent;");
        QIcon arrowIcon = themeIcon({"go-next", "arrow-right"});
        if (arrowIcon.isNull())
            arrowIcon = QApplication::style()->standardIcon(QStyle::SP_ArrowRight);
        arrow->setPixmap(arrowIcon.pixmap(22, 22));
        actionRow->addWidget(arrow, 0, Qt::AlignVCenter);
        auto *action = new LinkLabel(QStringLiteral("Learn more about Aero7"));
        Win7::setPointSize(action, 11);
        QObject::connect(action, &LinkLabel::clicked, action,
                         [learnMore = std::move(learnMore)]() {
                             if (learnMore)
                                 learnMore();
                         });
        actionRow->addWidget(action, 0, Qt::AlignVCenter);
        row->addLayout(actionRow);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        QPainter painter(this);
        QLinearGradient background(rect().topLeft(), rect().bottomRight());
        background.setColorAt(0.0, QColor(230, 245, 255));
        background.setColorAt(0.52, QColor(184, 220, 250));
        background.setColorAt(1.0, QColor(211, 234, 255));
        painter.fillRect(rect(), background);

        QLinearGradient highlight(0, 0, 0, height() / 2.0);
        highlight.setColorAt(0.0, QColor(255, 255, 255, 185));
        highlight.setColorAt(1.0, QColor(255, 255, 255, 0));
        painter.fillRect(QRect(0, 0, width(), height() / 2), highlight);

        painter.setPen(QColor(123, 171, 215));
        painter.drawRect(rect().adjusted(0, 0, -1, -1));

        QFont watermark = font();
        watermark.setPointSize(54);
        watermark.setWeight(QFont::Light);
        painter.setFont(watermark);
        painter.setPen(QColor(54, 96, 151, 45));
        painter.drawText(rect().adjusted(0, 0, -18, -5),
                         Qt::AlignRight | Qt::AlignBottom,
                         QStringLiteral("aero7"));
        QFrame::paintEvent(event);
    }
};

} // namespace

GettingStartedPage::GettingStartedPage(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QStringLiteral("gettingStartedPage"));
    setStyleSheet(QStringLiteral("#gettingStartedPage { background: #FFFFFF; }"));

    auto *content = new QVBoxLayout(this);
    content->setContentsMargins(20, 16, 20, 18);
    content->setSpacing(14);

    content->addWidget(new WelcomeBanner(
        [this]() { openOfficialWebsite(); }, this));

    auto *grid = new QGridLayout;
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setHorizontalSpacing(10);
    grid->setVerticalSpacing(4);
    grid->setColumnStretch(0, 1);
    grid->setColumnStretch(1, 1);
    grid->setColumnStretch(2, 1);

    auto addTask = [this, grid](int row, int column, const QIcon &icon,
                                const QString &title, const QString &description,
                                std::function<void()> action) {
        grid->addWidget(new TaskWidget(icon, title, description,
                                       std::move(action), this), row, column);
    };

    addTask(0, 0,
            taskIcon({"help-about", "distributor-logo", "preferences-system"}),
            QStringLiteral("Learn about Aero7"),
            QStringLiteral("Discover Aero7 features and learn how your system works."),
            [this]() { openOfficialWebsite(); });
    addTask(0, 1,
            taskIcon({"preferences-desktop-theme", "preferences-desktop"}),
            QStringLiteral("Personalize Aero7"),
            QStringLiteral("Change your desktop, theme, colors, icons and appearance."),
            [this]() { emit navigateRequested(PageId::Personalization); });
    addTask(0, 2,
            taskIcon({"system-software-install", "package-x-generic"}),
            QStringLiteral("Install applications"),
            QStringLiteral("Find and manage software installed on your computer."),
            [this]() { emit navigateRequested(PageId::ProgramsFeatures); });
    addTask(1, 0,
            taskIcon({"preferences-system-network", "network-wired"}),
            QStringLiteral("Connect to a network"),
            QStringLiteral("Configure Wi-Fi, Ethernet, VPN and other network connections."),
            [this]() { emit navigateRequested(PageId::NetworkSharing); });
    addTask(1, 1,
            taskIcon({"system-software-update", "software-update-available"}),
            QStringLiteral("System & Updates"),
            QStringLiteral("Check system information and keep Aero7 up to date."),
            [this]() { emit navigateRequested(PageId::LinuxUpdate); });
    addTask(1, 2,
            taskIcon({"wine", "application-x-executable", "applications-system"}),
            QStringLiteral("Application Compatibility"),
            QStringLiteral("Choose default programs, file associations and compatibility tools."),
            [this]() { emit navigateRequested(PageId::DefaultPrograms); });
    addTask(2, 0,
            taskIcon({"preferences-system-backup", "document-save-all"}),
            QStringLiteral("Back up your files"),
            QStringLiteral("Review storage options and backup availability."),
            [this]() { emit navigateRequested(PageId::BackupRestore); });
    addTask(2, 1,
            taskIcon({"system-users", "preferences-system-users"}),
            QStringLiteral("User Accounts"),
            QStringLiteral("Add, remove and configure users and account settings."),
            [this]() { emit navigateRequested(PageId::UserAccounts); });
    addTask(2, 2,
            taskIcon({"preferences-desktop-display", "video-display"}),
            QStringLiteral("Display Settings"),
            QStringLiteral("Configure displays, resolution, scaling and screen layout."),
            [this]() { emit navigateRequested(PageId::DisplaySettings); });

    content->addLayout(grid);
    content->addStretch(1);
}

void GettingStartedPage::openOfficialWebsite()
{
    if (!QDesktopServices::openUrl(kOfficialWebsite)) {
        QMessageBox::warning(
            this, tr("Getting Started"),
            tr("Aero7 could not open the official website.\n\n%1")
                .arg(kOfficialWebsite.toString()));
    }
}
