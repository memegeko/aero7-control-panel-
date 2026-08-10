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
[Building](#building) ·
[Roadmap](#roadmap) ·
[Upstream](#upstream) ·
[Report a bug](https://github.com/memegeko/aero7-control-panel-/issues/new)

</div>

---

**Aero7 Control Panel is an independent project and is not affiliated with or endorsed by Microsoft Corporation. Windows is a trademark of the Microsoft group of companies.**

> [!WARNING]
> Aero7 Control Panel is under active development. Several pages are incomplete,
> experimental, or still use placeholder actions. Test changes carefully.

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

Current upstream functionality includes:

- Windows 7-style Control Panel home screen organized by category
- Windows Update-style page backed by real `pacman` update checks
- Installed update history read from `pacman.log`
- Programs and Features package listing, uninstall, and AUR-aware reinstall
- Network and Sharing Center overview
- Firewall status and rule summary through `ufw`
- Power Options
- Windows Experience Index-style performance benchmark

Aero7-specific pages and integrations will be added as development continues.

## Building

### Arch Linux

Install the build dependencies:

```bash
sudo pacman -S --needed qt6-base qt6-multimedia cmake   kwidgetsaddons kwindowsystem openssl zlib
```

Build and run:

```bash
cmake -B build
cmake --build build -j"$(nproc)"
./build/control
```

The application also requires
[libAeroQt](https://gitgud.io/atmk/libaero-qt). Place the built
`libAeroQt.so*` files beside `build/control`, or install them in a system
library path.

## Runtime dependencies

| Tool | Purpose |
| --- | --- |
| `pkexec` | Privileged package-management actions |
| `pacman` | Updates, installed packages, and package removal |
| `yay` | Optional reinstall support for AUR and foreign packages |
| `ufw` | Firewall status and rules |

## Roadmap

Planned Aero7 expansion areas include:

- A Getting Started page for new Aero7 installations
- Aero7 appearance, theme, sound, and desktop controls
- KDE Plasma settings presented inside one consistent interface
- Hardware, devices, networking, users, storage, and security pages
- Update, repair, recovery, and Aero7 repository management
- Removal of placeholder actions in favor of real system integrations
- Improved privilege separation and clear confirmation for system changes

Track planned work and report problems in the
[issue tracker](https://github.com/memegeko/aero7-control-panel-/issues).

## Related Aero7 projects

- [Aero7-shell](https://github.com/memegeko/aero7-shell) — installs and manages the Aero7 desktop
- [Aero7 Package Repository](https://github.com/memegeko/aero7-repo) — signed Arch Linux packages for Aero7

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

Microsoft, Windows, and the Windows logo are trademarks of the Microsoft group
of companies. All other trademarks are the property of their respective owners.

This project recreates interface concepts and does not include or redistribute
proprietary Microsoft logos, icons, sounds, fonts, or other copyrighted assets.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
