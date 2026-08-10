# Aero7 Control Panel settings map

This page records the user-facing Aero7 name, the original KDE Plasma name,
the KDE Control Module (KCM) or Aero7 backend, and the current replacement
state for every setting exposed through the catalog-driven Control Panel.

The runtime source of truth is
[`src/ui/SettingsCatalog.cpp`](../src/ui/SettingsCatalog.cpp). The same data
drives Control Panel pages, search results, icon views, routing tests, and the
original-name labels visible beneath each setting. This document is formatted
so it can later be copied directly into the Aero7 GitHub wiki.

## Naming policy

- **Aero7 name** is the public label. It may be improved later when a clearer,
  more familiar name is found.
- **Original KDE name** remains recorded even after a public rename. It is the
  stable trace back to KDE documentation and bug reports.
- **Aero7 native** means the setting is handled inside Control Panel.
- **Aero7 partial** means Control Panel handles part of the workflow and may
  still use a KDE or Linux service for advanced options.
- **KDE bridge** means Control Panel is the frontend and opens the individual
  KCM as a compatibility backend. It does not open the System Settings landing
  application.
- If an optional KCM is not installed, Control Panel shows a clear error rather
  than silently doing nothing.
- Aero7 installs `plasma-nm` for Network Management and uses Plasma 6's
  `kcmspellchecking` module with English and Dutch Hunspell dictionaries.
- KDE Wallet is intentionally not installed or exposed by Aero7 Control Panel.

## Appearance and themes

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Personalization | Global Theme | Plasma configuration / Aero7 Personalization | Aero7 native |
| Window Color | Colors | `kcm_colors` | KDE bridge |
| Application Appearance | Application Style | `kcm_style` | KDE bridge |
| Desktop Style | Plasma Style | `kcm_desktoptheme` | KDE bridge |
| Icons | Icons | `kcm_icons` | KDE bridge |
| Mouse Pointers | Pointers | `kcm_cursortheme` | KDE bridge |
| Desktop Background | Wallpaper | `kcm_wallpaper` | KDE bridge |
| Fonts | Fonts | `kcm_fonts` | KDE bridge |
| Font Management | Font Management | `kcm_fontinst` | KDE bridge |
| Welcome Animation | Splash Screen | `kcm_splashscreen` | KDE bridge |

## Display

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Screen Resolution | Display Configuration | `kcm_kscreen` | KDE bridge |
| Night Light | Night Light | `kcm_nightlight` | KDE bridge |
| Day and Night Schedule | Day-Night Cycle | `kcm_nighttime` | KDE bridge |

## Taskbar and Start menu

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Desktop Behavior | General Behavior | `kcm_workspace` | KDE bridge |
| Start Menu Search | Plasma Search | `kcm_plasmasearch` | KDE bridge |
| Keyboard Shortcuts | Shortcuts | `kcm_keys` | KDE bridge |
| Notification Area | Notifications | `kcm_notifications` | KDE bridge |

## Window behavior

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Window Borders | Window Decorations | `kcm_kwindecoration` | KDE bridge |
| Window Behavior | Window Behavior | `kcm_kwinoptions` | KDE bridge |
| Program Window Rules | Window Rules | `kcm_kwinrules` | KDE bridge |
| Switch Between Windows | Task Switcher | `kcm_kwintabbox` | KDE bridge |
| Visual Effects | Desktop Effects | `kcm_kwin_effects` | KDE bridge |
| Animations | Animations | `kcm_animations` | KDE bridge |
| Screen Edges | Screen Edges | `kcm_kwinscreenedges` | KDE bridge |
| Multiple Desktops | Virtual Desktops | `kcm_kwin_virtualdesktops` | KDE bridge |
| Activities | Activities | `kcm_activities` | KDE bridge |
| Window Manager Add-ons | KWin Scripts | `kcm_kwin_scripts` | KDE bridge |
| Legacy App Keyboard Access | Legacy X11 App Support | `kcm_kwinxwayland` | KDE bridge |

## Input devices

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Mouse | Mouse | `kcm_mouse` | KDE bridge |
| Keyboard | Keyboard | `kcm_keyboard` | KDE bridge |
| Touchpad | Touchpad | `kcm_touchpad` | KDE bridge |
| Touchscreen | Touchscreen | `kcm_touchscreen` | KDE bridge |
| Touchscreen Gestures | Touchscreen Gestures | `kcm_kwintouchscreen` | KDE bridge |
| Pen and Drawing Tablet | Drawing Tablet | `kcm_tablet` | KDE bridge |
| Game Controller | Game Controller | `kcm_gamecontroller` | KDE bridge |
| On-Screen Keyboard | Virtual Keyboard | `kcm_virtualkeyboard` | KDE bridge |

## Sound

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Sound | Sound | PipeWire/PulseAudio / Aero7 Sound dialog | Aero7 native |
| System Sounds | System Sounds | `kcm_soundtheme` | KDE bridge |

## Network

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Network and Sharing Center | Connections | NetworkManager / Aero7 network page | Aero7 native |
| Change Adapter Settings | Connections | `kcm_networkmanagement` | KDE bridge |
| Proxy Settings | Proxy | `kcm_proxy` | KDE bridge |
| Connection Preferences | Connection Preferences | `kcm_netpref` | KDE bridge |

## Power

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Power Options | Power Management | power-profiles-daemon + UPower / Aero7 Power Options | Aero7 native |
| Advanced Power Settings | Power Management | `kcm_powerdevilprofilesconfig` | KDE bridge |
| Battery and Energy | Energy | `kcm_mobile_power` | KDE bridge |

## User accounts

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| User Accounts | Users | Linux account tools + polkit / Aero7 User Accounts | Aero7 native |
| Online Accounts | Online Accounts | `kcm_kaccounts` | KDE bridge |

## Region and language

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Date and Time | Date & Time | `kcm_clock` / Aero7 Date and Time dialog | Aero7 partial |
| Region and Language | Region & Language | `kcm_regionandlang` | KDE bridge |
| Spelling | Spell Check | `kcmspellchecking` | KDE bridge |

## Default programs and files

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Default Programs | Default Applications | `kcm_componentchooser` | KDE bridge |
| File Type Associations | File Associations | `kcm_filetypes` | KDE bridge |
| Personal Folder Locations | Locations | `kcm_desktoppaths` | KDE bridge |
| Removable Device Actions | Device Actions | `kcm_solid_actions` | KDE bridge |

## Search and history

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| File Search and Indexing | File Search | `kcm_baloofile` | KDE bridge |
| Recent Items | Recent Files | `kcm_recentFiles` | KDE bridge |
| Search Keywords | Web Search Keywords | `kcm_webshortcuts` | KDE bridge |

## Ease of access

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Ease of Access Center | Accessibility | `kcm_access` / Aero7 Ease of Access Center | Aero7 partial |
| Advanced Accessibility | Accessibility | `kcm_access` | KDE bridge |

## Startup and shutdown

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Startup Programs | Autostart | `kcm_autostart` | KDE bridge |
| Sign-in and Sign-out | Desktop Session | `kcm_smserver` | KDE bridge |
| Lock Screen | Screen Locking | `kcm_screenlocker` | KDE bridge |
| Background Services | Background Services | `kcm_kded` | KDE bridge |

## Security and maintenance

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Firewall | Firewall | Aero7 `ufw` page | Aero7 partial |
| Linux Update | Software Update | Aero7 `pacman` update page | Aero7 native |
| Diagnostic Data | User Feedback | `kcm_feedback` | KDE bridge |

## Storage and devices

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| Automatic Media Mounting | Device Automounter | `kcm_device_automounter` | KDE bridge |

## Advanced system settings

| Aero7 name | Original KDE name | Original KDE module/backend | State |
| --- | --- | --- | --- |
| System Information | Quick Settings | `kcm_landingpage` / Aero7 System page | Aero7 native |
| Desktop Renderer | Plasma Renderer | `kcm_qtquicksettings` | KDE bridge |

## Replacement priorities

The remaining KDE bridges are intentional compatibility layers for settings
whose behavior is owned by Plasma. The five former partial pages now use
NetworkManager, PipeWire/PulseAudio, UPower, power-profiles-daemon, Plasma
configuration files, and authenticated Linux account tools for their main
workflows. Advanced connection editing and PowerDevil policy remain available
as individually labelled compatibility actions.

When a bridge becomes native, update its one `SettingDefinition` entry. The
public label, search result, hub row, original KDE trace, and tests then remain
in sync automatically.
