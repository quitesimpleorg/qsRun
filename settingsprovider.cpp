#include "settingsprovider.h"
#include <QDir>
#include <QFileInfo>

SettingsProvider::SettingsProvider(QSettings &settings)
{
	this->settings = &settings;
}

QStringList SettingsProvider::userEntriesPaths() const
{
	// TODO: make it configurable, but we stick with this for now.
	QFileInfo fi(this->settings->fileName());
	return {fi.absoluteDir().absolutePath()};
}

QStringList SettingsProvider::systemApplicationsEntriesPaths() const
{
	return settings->value("sysAppsPaths", "/usr/share/applications/").toStringList();
}

int SettingsProvider::getMaxCols() const
{
	return settings->value("maxColumns", 3).toInt();
}

bool SettingsProvider::singleInstanceMode() const
{
	return settings->value("singleInstance", true).toBool();
}

QString SettingsProvider::getTerminalCommand() const
{
	return settings->value("terminal", "/usr/bin/x-terminal-emulator -e %c").toString();
}

QString SettingsProvider::socketPath() const
{
	return settings->value("singleInstanceSocket", "/tmp/qsrun").toString();
}
