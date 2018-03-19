#include "Utility.h"

Utility::Utility()
{
}


Utility::~Utility()
{
}

QDateTime Utility::getDateTime()
{
	return QDateTime::currentDateTime();
}

QTime Utility::getCurrentTime()
{
	return QTime::currentTime();
}