<a id="readme-top"></a>

<div align="center">

<img src="https://raw.githubusercontent.com/memegeko/aero7-shell/beta/docs/assets/aero7-logo.png" width="150" alt="Aero7 logo">

# Aero7 Control Panel

### A Windows 7-inspired control center for Aero7 and Arch Linux

A Qt 6 and KDE Frameworks application that brings Linux and KDE settings
together in a familiar Control Panel-style interface for the Aero7 desktop.

[![Arch Linux](https://img.shields.io/badge/Arch_Linux-supported-1793D1?logo=archlinux&logoColor=white)](https://archlinux.org/)
[![KDE Plasma](https://img.shields.io/badge/KDE_Plasma-6-1D99F3?logo=kde&logoColor=white)](https://kde.org/plasma-desktop/)
[![GPL-3.0 License](https://img.shields.io/badge/license-GPL--3.0-2ea44f.svg)](LICENSE)

[Features](#features) ·
[Installation](#installation) ·
[Roadmap](#roadmap) ·
[Upstream](#upstream) ·
[Report a bug](https://github.com/memegeko/aero7-control-panel-/issues/new)

</div>

---

**Aero7 Control Panel is an independent project and is not affiliated with or endorsed by Microsoft Corporation. Windows is a trademark of the Microsoft group of companies.**

> [!WARNING]
> Aero7 Control Panel is under active development. Some settings use an
> individual KDE Control Module as a documented compatibility backend while a
> native Aero7 implementation is developed.

## About the project

Aero7 Control Panel is the central settings application for the
[Aero7](https://github.com/memegeko/aero7-shell) Linux desktop. It is based on
[linux-control](https://github.com/actuallyaridan/linux-control) and is being
expanded into a unified home for Aero7, KDE Plasma, Arch Linux, hardware, and
system-management settings.

The goal is to provide the familiar layout and visual language of the Windows 7
Control Panel while exposing real Linux settings and tools. It does not emulate
Windows or disguise the operating system: Aero7 remains an Arch Linux-based
desktop.

## Features

Current functionality includes:

- Aero7 Getting Started page with internal links to working settings pages
- Catalog-driven settings hubs that preserve every original KDE setting name
- Search and large/small-icon views backed by the same settings catalog
- Windows 7-style Control Panel home screen organized by category
- Windows Update-style page backed by real `pacman` update checks
- Installed update history read from `pacman.log`
- Programs and Features package listing and removal
- Network and Sharing Center overview
- Firewall status, enable/disable, allow-rule and reset controls through `ufw`
- Power Options
- Windows Experience Index-style performance benchmark

Aero7-specific pages and integrations will be added as development continues.

### Getting Started

The **Getting Started** Start-menu application opens an internal Control Panel
page with a compact three-column launch point for common setup tasks. Every
task now routes to a real internal page or catalog-backed settings hub,
including Application Compatibility, Backup and Restore, and Display Settings.
The page can also be found through Control Panel search. The Learn about Aero7
actions open the
[official Aero7 website](https://aero7.miku-dayo.com/).

### KDE settings map

The wiki-ready [settings map](docs/KDE-SETTINGS-MAP.md) records each Aero7
label, its original KDE name, its KCM or native backend, and its replacement
state. Original KDE names remain traceable even when the public Aero7 wording
is improved later. Missing optional KCMs produce a visible explanation instead
of a dead button. The companion [function audit](docs/CONTROL-PANEL-FUNCTIONS.md)
records what every main page action currently does and which controls are
intentionally unavailable.

## Installation

Aero7 Control Panel is distributed through the official
[Aero7 Package Repository](https://github.com/memegeko/aero7-repo) and is
included with Aero7.

On a system with the Aero7 repository configured, install it with:

```bash
sudo pacman -S linux-control-panel
```

Updates are delivered through the Aero7 repository alongside the rest of the
Aero7 desktop.

## Runtime dependencies

| Tool | Purpose |
| --- | --- |
| `pkexec` | Privileged package-management actions |
| `pacman` | Updates, installed packages, and package removal |
| `ufw` | Firewall status and rules |
| `kcmshell6` | Opens an individual KDE setting used as a compatibility backend |

## Roadmap

Planned Aero7 expansion areas include:

- Aero7 appearance, theme, sound, and desktop controls
- Replace KDE compatibility bridges with direct Linux/KDE service APIs where practical
- Hardware, devices, networking, users, storage, and security pages
- Update, repair, recovery, and Aero7 repository management
- More native Aero7 controls for advanced settings
- Improved privilege separation and clear confirmation for system changes

Track planned work and report problems in the
[issue tracker](https://github.com/memegeko/aero7-control-panel-/issues).

## Related Aero7 projects

- [Aero7](https://github.com/memegeko/aero7) — the main Aero7 operating system
- [Aero7 Shell](https://github.com/memegeko/aero7-shell) — the Aero7 desktop shell and installer
- [Aero7 Package Repository](https://github.com/memegeko/aero7-repo) — official packages and updates for Aero7

## Upstream

Aero7 Control Panel is a fork of
[actuallyaridan/linux-control](https://github.com/actuallyaridan/linux-control).

The original project and its contributors remain credited through the Git
history and license. Aero7-specific changes are maintained in this repository.

## Contributing

Bug reports, tested fixes, new settings pages, and documentation improvements
are welcome. Keep changes focused, describe the Linux command or API behind each
setting, and include clear failure handling for privileged operations.

## License

This project is distributed under the [GNU General Public License v3.0](LICENSE),
inherited from the upstream project. Third-party libraries and assets retain
their own licenses.

## Legal / Trademark Notice

Aero7 Control Panel is an independent open-source project and is not affiliated
with, authorized, sponsored, endorsed, or approved by Microsoft Corporation.

Microsoft and Windows are trademarks of the Microsoft group of companies. All
other trademarks are the property of their respective owners.

This project recreates interface concepts and does not include or redistribute
proprietary Microsoft assets.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
