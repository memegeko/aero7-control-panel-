# Aero7 Control Panel Wiki

Welcome to the documentation for **Aero7 Control Panel**, the central settings
frontend for the Aero7 desktop. This Wiki belongs only to the Control Panel
project. Documentation for the Aero7 operating system, shell, package
repository, and website remains in each project's own repository.

## Start here

- [Control Panel Guide](Control-Panel-Guide) — categories, native pages,
  buttons, permissions, limitations, and troubleshooting.
- [Complete Settings Reference](Settings-Reference) — all 69 searchable
  settings, what each setting does, its original KDE name, backend, and status.
- [Backends and Permissions](Backends-and-Permissions) — the Linux services,
  commands, KDE modules, and privilege boundaries behind Control Panel.
- [Installation and Updates](Installation-and-Updates) — install or update the
  Control Panel through the Aero7 package repository.
- [Screenshots](Screenshots) — current captures of the main Control Panel and
  representative native settings pages.

## Finding a setting

Open **Control Panel** from the Start menu and use **Search Control Panel**.
Search accepts the public Aero7 setting name as well as the original KDE name.
Control Panel search results remain inside the Control Panel hierarchy.

The Start menu can also return Control Panel settings under its **Settings**
results without placing every setting among the normal application shortcuts.

If you know only part of a name, open the
[Complete Settings Reference](Settings-Reference) and use your browser's Find
command (`Ctrl+F`).

## Implementation labels

- **Aero7 native** means Control Panel owns the main workflow and talks to a
  Linux service or configuration directly.
- **Aero7 partial** means the main workflow is provided by Control Panel while
  advanced functions use a focused system component.
- **KDE bridge** means Control Panel opens one specific KDE Control Module. It
  never intentionally opens the generic System Settings home page.
- **Unavailable** controls are visibly disabled until a correct, safe backend
  exists. They are not decorative dead links.

## Project links

- [Source repository](https://github.com/memegeko/aero7-control-panel-)
- [Issue tracker](https://github.com/memegeko/aero7-control-panel-/issues)
- [Aero7 website](https://aero7.miku-dayo.com/)
- [Upstream linux-control project](https://github.com/actuallyaridan/linux-control)

## Independent-project notice

Aero7 Control Panel is an independent open-source project. It is not
affiliated with, authorized, sponsored, endorsed, or approved by Microsoft
Corporation. Microsoft and Windows are trademarks of the Microsoft group of
companies. Other trademarks belong to their respective owners.
