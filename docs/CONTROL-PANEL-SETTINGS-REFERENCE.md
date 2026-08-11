# Control Panel Settings Reference

This is the complete, searchable reference for every setting exposed by the
Aero7 Control Panel catalog. Use your browser's **Find** command (Ctrl+F) to
look up a setting by its Aero7 name, its original KDE name, or its KDE Control
Module (KCM) identifier.

The tables are generated from the same authoritative catalog that drives
Control Panel search, group pages, routing, and the Start menu's **Settings**
search results. There are **69 settings** across 17 sections.

## Status and backend meanings

- **Aero7 native** — the main workflow is implemented inside Aero7 Control
  Panel and talks directly to the relevant Linux service or configuration.
- **Aero7 partial** — Aero7 provides the main workflow but uses a separate
  Linux or KDE component for advanced functions.
- **KDE bridge** — Aero7 opens one specific KDE Control Module with
  kcmshell6. It does not open the general System Settings home page.
- **Original KDE name** — the upstream Plasma name retained for documentation,
  troubleshooting, and searching.
- If a hardware-specific or optional KCM is unavailable, Control Panel reports
  that clearly instead of silently ignoring the click.

See [Control Panel Guide](Control-Panel.md) for native button behavior,
permissions, unavailable features, and troubleshooting.

## Appearance and themes (10)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Personalization** | Choose the Aero7 theme and desktop appearance. | Global Theme; Aero7 Control Panel page; original KDE module <code>kcm_lookandfeel</code> | Aero7 native |
| **Window Color** | Choose window and application colors. | Colors; <code>kcm_colors</code> | KDE bridge |
| **Application Appearance** | Change the appearance and behavior of application controls. | Application Style; <code>kcm_style</code> | KDE bridge |
| **Desktop Style** | Change the desktop shell style. | Plasma Style; <code>kcm_desktoptheme</code> | KDE bridge |
| **Icons** | Choose the icon theme used by applications and the desktop. | Icons; <code>kcm_icons</code> | KDE bridge |
| **Mouse Pointers** | Choose the pointer design and size. | Pointers; <code>kcm_cursortheme</code> | KDE bridge |
| **Desktop Background** | Choose the desktop background image. | Wallpaper; <code>kcm_wallpaper</code> | KDE bridge |
| **Fonts** | Change interface fonts and font rendering. | Fonts; <code>kcm_fonts</code> | KDE bridge |
| **Font Management** | Install, remove and preview fonts. | Font Management; <code>kcm_fontinst</code> | KDE bridge |
| **Welcome Animation** | Choose the desktop-session loading animation. | Splash Screen; <code>kcm_splashscreen</code> | KDE bridge |

## Display (3)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Screen Resolution** | Arrange displays and change resolution, scale and refresh rate. | Display Configuration; <code>kcm_kscreen</code> | KDE bridge |
| **Night Light** | Reduce blue light according to a schedule. | Night Light; <code>kcm_nightlight</code> | KDE bridge |
| **Day and Night Schedule** | Set the times used by automatic light and dark behavior. | Day-Night Cycle; <code>kcm_nighttime</code> | KDE bridge |

## Taskbar and Start menu (4)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Desktop Behavior** | Choose click behavior, selection markers and desktop navigation. | General Behavior; <code>kcm_workspace</code> | KDE bridge |
| **Start Menu Search** | Choose which search providers appear in the Start menu. | Plasma Search; <code>kcm_plasmasearch</code> | KDE bridge |
| **Keyboard Shortcuts** | Review and change desktop keyboard shortcuts. | Shortcuts; <code>kcm_keys</code> | KDE bridge |
| **Notification Area** | Choose notification behavior and application alerts. | Notifications; <code>kcm_notifications</code> | KDE bridge |

## Window behavior (11)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Window Borders** | Choose title bars, borders and window buttons. | Window Decorations; <code>kcm_kwindecoration</code> | KDE bridge |
| **Window Behavior** | Configure focus, movement and title-bar actions. | Window Behavior; <code>kcm_kwinoptions</code> | KDE bridge |
| **Program Window Rules** | Remember or force settings for individual program windows. | Window Rules; <code>kcm_kwinrules</code> | KDE bridge |
| **Switch Between Windows** | Configure the Alt+Tab window switcher. | Task Switcher; <code>kcm_kwintabbox</code> | KDE bridge |
| **Visual Effects** | Enable and configure desktop visual effects. | Desktop Effects; <code>kcm_kwin_effects</code> | KDE bridge |
| **Animations** | Change animation speed and style. | Animations; <code>kcm_animations</code> | KDE bridge |
| **Screen Edges** | Assign actions to screen corners and edges. | Screen Edges; <code>kcm_kwinscreenedges</code> | KDE bridge |
| **Multiple Desktops** | Configure the number and layout of virtual desktops. | Virtual Desktops; <code>kcm_kwin_virtualdesktops</code> | KDE bridge |
| **Activities** | Keep separate groups of windows and desktop state. | Activities; <code>kcm_activities</code> | KDE bridge |
| **Window Manager Add-ons** | Manage scripts that extend window behavior. | KWin Scripts; <code>kcm_kwin_scripts</code> | KDE bridge |
| **Legacy App Keyboard Access** | Choose which keys legacy X11 programs may receive. | Legacy X11 App Support; <code>kcm_kwinxwayland</code> | KDE bridge |

## Input devices (8)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Mouse** | Configure buttons, speed and scrolling. | Mouse; <code>kcm_mouse</code> | KDE bridge |
| **Keyboard** | Configure keyboard hardware and layouts. | Keyboard; <code>kcm_keyboard</code> | KDE bridge |
| **Touchpad** | Configure touchpad taps, gestures and scrolling. | Touchpad; <code>kcm_touchpad</code> | KDE bridge |
| **Touchscreen** | Map and configure touchscreen input. | Touchscreen; <code>kcm_touchscreen</code> | KDE bridge |
| **Touchscreen Gestures** | Configure touchscreen gestures handled by the window manager. | Touchscreen Gestures; <code>kcm_kwintouchscreen</code> | KDE bridge |
| **Pen and Drawing Tablet** | Configure drawing tablets and pens. | Drawing Tablet; <code>kcm_tablet</code> | KDE bridge |
| **Game Controller** | Test and configure game controllers. | Game Controller; <code>kcm_gamecontroller</code> | KDE bridge |
| **On-Screen Keyboard** | Choose the virtual keyboard used on screen. | Virtual Keyboard; <code>kcm_virtualkeyboard</code> | KDE bridge |

## Sound (2)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Sound** | Manage playback, recording, sound schemes and communications. | Sound; Aero7 <code>sound</code> dialog; original KDE module <code>kcm_pulseaudio</code> | Aero7 native |
| **System Sounds** | Choose the notification sound theme. | System Sounds; <code>kcm_soundtheme</code> | KDE bridge |

## Network (4)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Network and Sharing Center** | View active connections and network information. | Connections; Aero7 Control Panel page; original KDE module <code>kcm_networkmanagement</code> | Aero7 native |
| **Change Adapter Settings** | Create and edit wired, wireless and VPN connections. | Connections; <code>kcm_networkmanagement</code> | KDE bridge |
| **Proxy Settings** | Configure proxy servers used by applications. | Proxy; <code>kcm_proxy</code> | KDE bridge |
| **Connection Preferences** | Configure generic connection behavior and timeouts. | Connection Preferences; <code>kcm_netpref</code> | KDE bridge |

## Power (3)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Power Options** | Choose a power plan and energy profile. | Power Management; Aero7 Control Panel page; original KDE module <code>kcm_powerdevilprofilesconfig</code> | Aero7 native |
| **Advanced Power Settings** | Configure sleep, screen energy, lid and power-button behavior. | Power Management; <code>kcm_powerdevilprofilesconfig</code> | KDE bridge |
| **Battery and Energy** | Configure energy settings on mobile devices. | Energy; <code>kcm_mobile_power</code> | KDE bridge |

## User accounts (2)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **User Accounts** | View and manage local user accounts. | Users; Aero7 Control Panel page; original KDE module <code>kcm_users</code> | Aero7 native |
| **Online Accounts** | Connect supported online services to the desktop. | Online Accounts; <code>kcm_kaccounts</code> | KDE bridge |

## Region and language (3)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Date and Time** | Set the clock, time zone, additional clocks and Internet time. | Date & Time; Aero7 <code>datetime</code> dialog; original KDE module <code>kcm_clock</code> | Aero7 partial |
| **Region and Language** | Set language, number, currency and time formats. | Region & Language; <code>kcm_regionandlang</code> | KDE bridge |
| **Spelling** | Choose spell-check dictionaries and options. | Spell Check; <code>kcmspellchecking</code> | KDE bridge |

## Default programs and files (4)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Default Programs** | Choose the default browser, mail, terminal and other programs. | Default Applications; <code>kcm_componentchooser</code> | KDE bridge |
| **File Type Associations** | Choose which program opens each file type. | File Associations; <code>kcm_filetypes</code> | KDE bridge |
| **Personal Folder Locations** | Choose the locations of Documents, Downloads and other folders. | Locations; <code>kcm_desktoppaths</code> | KDE bridge |
| **Removable Device Actions** | Choose actions offered when media and devices are connected. | Device Actions; <code>kcm_solid_actions</code> | KDE bridge |

## Search and history (3)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **File Search and Indexing** | Choose indexed locations and file-search behavior. | File Search; <code>kcm_baloofile</code> | KDE bridge |
| **Recent Items** | Manage file activity history and exclusions. | Recent Files; <code>kcm_recentFiles</code> | KDE bridge |
| **Search Keywords** | Configure short keywords for web searches. | Web Search Keywords; <code>kcm_webshortcuts</code> | KDE bridge |

## Ease of access (2)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Ease of Access Center** | Make the computer easier to see, hear and operate. | Accessibility; Aero7 Control Panel page; original KDE module <code>kcm_access</code> | Aero7 partial |
| **Advanced Accessibility** | Configure keyboard, screen-reader and visual accessibility. | Accessibility; <code>kcm_access</code> | KDE bridge |

## Startup and shutdown (4)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Startup Programs** | Choose programs that start when you sign in. | Autostart; <code>kcm_autostart</code> | KDE bridge |
| **Sign-in and Sign-out** | Choose session restore, login and logout behavior. | Desktop Session; <code>kcm_smserver</code> | KDE bridge |
| **Lock Screen** | Configure automatic screen locking and lock appearance. | Screen Locking; <code>kcm_screenlocker</code> | KDE bridge |
| **Background Services** | Choose desktop services that run in the background. | Background Services; <code>kcm_kded</code> | KDE bridge |

## Security and maintenance (3)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Firewall** | View firewall status and network protection. | Firewall; Aero7 Control Panel page | Aero7 partial |
| **Linux Update** | Check for and install system updates. | Software Update; Aero7 Control Panel page | Aero7 native |
| **Diagnostic Data** | Choose whether anonymous desktop feedback is sent. | User Feedback; <code>kcm_feedback</code> | KDE bridge |

## Storage and devices (1)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **Automatic Media Mounting** | Choose which disks and volumes mount automatically. | Device Automounter; <code>kcm_device_automounter</code> | KDE bridge |

## Advanced system settings (2)

| Setting | What it does | Original KDE name and implementation | Status |
| --- | --- | --- | --- |
| **System Information** | View the operating system, processor, memory and computer name. | Quick Settings; Aero7 Control Panel page; original KDE module <code>kcm_landingpage</code> | Aero7 native |
| **Desktop Renderer** | Choose the graphics renderer used by the desktop shell. | Plasma Renderer; <code>kcm_qtquicksettings</code> | KDE bridge |

## When a setting does not open

1. Install all pending updates and restart Aero7.
2. Search for the setting again and note any missing-module message.
3. Hardware-specific pages such as Touchpad, Touchscreen, Drawing Tablet, Game
   Controller, and mobile power settings can be unavailable when the matching
   hardware or optional KDE module is absent.
4. Report the Aero7 setting name, original KDE name, and KCM identifier from
   this page when filing an issue.

The runtime source of truth is
[SettingsCatalog.cpp](https://github.com/memegeko/aero7-control-panel-/blob/main/src/ui/SettingsCatalog.cpp).

