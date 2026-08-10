# Control Panel function audit

This document records what the main controls do today. It is intended for the
Aero7 wiki and for regression testing. A blue link or enabled button must have
a real destination; unavailable items are grey, carry an explanation, and do
not pretend to be working controls.

## Native and partial Aero7 pages

| Page | Control | Current function |
| --- | --- | --- |
| Getting Started | Nine setup tasks | Routes to an internal Aero7 page or a catalog-backed settings hub |
| Getting Started | Learn more | Opens the official Aero7 website |
| System | Change settings | Validates and changes the real hostname through `hostnamectl` and polkit |
| System | Experience rating | Opens Performance Information and Tools |
| Linux Update | Check/install updates | Uses the existing Aero7 `pacman` update workflow |
| Programs and Features | Uninstall/repair | Uses the existing package-management workflow and confirmations |
| Installed Updates | Installed update list | Reads package history; it no longer claims a single historical update can be uninstalled safely |
| Network and Sharing Center | Connection links | Routes to Network Settings rather than acting as decorative text |
| Firewall | Turn on/off | Runs the corresponding `ufw` command through polkit |
| Firewall | Allow a port or service | Validates a user-provided `ufw allow` rule and applies it through polkit |
| Firewall | Notification settings | Configures UFW event logging from Off through Full and explains that UFW does not provide per-program popups |
| Firewall | Restore defaults | Confirms the destructive reset before running `ufw --force reset` |
| Action Center | Security/account/network/backup tasks | Routes to the appropriate internal page or hub |
| Power Options | Advanced plan links | Opens only `kcm_powerdevilprofilesconfig`, the original KDE Power Management module |
| Personalization | Color scheme tiles | Applies an installed color scheme; the UI now calls these color schemes rather than claiming to change a complete theme |
| Personalization | Background, color, sounds, lock screen | Opens the matching individual KCM or Aero7 dialog |
| User Accounts | Change password | Opens `passwd` in the configured terminal, with a KDE Users fallback |
| User Accounts | Change picture | Writes the user's standard `~/.face.icon` image |
| User Accounts | Change display name | Uses `usermod -c` through polkit after confirmation |
| User Accounts | Manage users/account type | Opens only the original KDE Users module (`kcm_users`) |
| Date and Time | Date, time, time zone and Internet time | Uses the existing native dialog and authenticated system tools |
| Sound | Devices/defaults/test/browse/schemes | Uses PipeWire/PulseAudio tools where available and stores cosmetic Aero7 scheme preferences |
| Performance | Rate/rerun/details | Uses the existing Aero7 benchmark workflow |
| Fonts | Font list/preview | Uses the installed font database and `kfontview` |
| Ease of Access | Accessibility tasks | Uses truthfully named configuration links for magnifier, screen reader, virtual keyboard, contrast and input |

## Catalog-backed settings

The group pages for Display, Network, Region and Language, Taskbar and Start
Menu, Default Programs, Input Devices, Startup and Shutdown, Window Behavior,
Security and Maintenance, Storage, Internet Options, Folder Options, AutoPlay,
and Backup and Restore are generated from the central catalog.

Each row contains:

1. the current Aero7 name;
2. the immutable original KDE name;
3. the original KCM module ID when one exists;
4. a native/partial/compatibility status;
5. a working action button.

KCM buttons call `kcmshell6 <module>` directly, so users stay in the Aero7
Control Panel hierarchy and never land on the normal System Settings home page.
Before launching, Control Panel checks the installed module list. Missing
optional components produce a clear dialog instead of a silent failure.

See [KDE-SETTINGS-MAP.md](KDE-SETTINGS-MAP.md) for the complete name and module
mapping.

## Intentionally unavailable controls

The following controls are deliberately non-clickable until a correct backend
exists:

- generic **Organize** command-bar menus that do not yet have page-specific
  commands;
- help-article links whose Aero7 documentation page has not been written;
- Parental Controls, because Aero7 does not currently ship a supported parental
  control service.

These controls are grey and explain their state in a tooltip. They should not
be changed back into blue decorative links.

## Adding or renaming a setting

Edit one entry in `src/ui/SettingsCatalog.cpp`. Change `aeroName` when the
public wording is unclear, but keep `kdeName` and `kdeModule` as the original
trace. Add a native page/applet target or an individual KCM command, update the
mapping document, and run all four CTest tests. Navigation must never depend on
matching the visible label; stable `PageId` values are used for internal routes.
