qsrun
========
qsrun is a launcher. It contains user defined entries for applications and also searches
system-applications. Using libcalculate, it can also be used as a calculator.

If you run a desktop environment like KDE it is questionable whether you will
find this useful, since they usually bring applications that are more or less
comparable to qsrun, although much more
powerful  (like KRunner). It can be useful for users running a window manager like
fluxbox etc.

Dependencies
------------
Qt >=5.7.

For the calculation engine, libqalculate is needed.

Currently no conditional compile flags are supported...

Building
--------
Assuming the necessary dependencies are installed:

```
qmake 
make
```

Getting started
----------------
$HOME/.config/qsrun
In this folder user-defined entries should be put (See "Entry format").

Config format
------------
Path: $HOME/.config/qsrun/qsrun.config

Example:
```
[General]
sysAppsPaths = "/usr/share/applications/", "/var/lib/snapd/desktop/applications/"
```

sysAppsPaths will default to "/usr/share/applications/" if no value
is given. 

Entry format
------------
It rudimentary supports .desktop files, but for user entries, the own format
should be preferred.

It's a simple format: [key] [value].

Example: quasselclient.qsrun:

```
command quasselclient
name Quassel
icon /usr/share/icons/hicolor/128x128/apps/quassel.png
row 1
col 0
key I
```


Example with inheritance: qsrun will search for "vlc.desktop" inside the paths defined in sysAppsPaths:

```
inherit vlc.desktop
row 3
col 1
```

Therefore, there is no need to explicitly the entry a name or icon etc. However, values given here will overwrite the inherited values.


"key" means a shortcut key, you can launch those by pressing Ctrl + "key", so in
the example above: CTRL + I.

Simply pressing Ctrl will show you the associated shortcuts on each individual
button.


General usage
-------------
Starting to type will search user defined entries first, followed by system
entries. Then the PATH variable will be searched, if there is a single match you can also
press TAB for auto completion. 

In general it will launch anything once you press enter, however it won't open a
terminal.

Calculator
----------
Start by typing "=", followed by your expression, e. g: "=(2+3)^2"
