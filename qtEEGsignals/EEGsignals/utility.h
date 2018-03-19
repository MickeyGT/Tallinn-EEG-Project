//This class should contain static methods used throughout the application.
#ifndef UTILITY_H
#define UTILITY_H

#include <QDateTime>
#include <QTime>

class Utility
{
public:
	Utility();
	~Utility();
	static QDateTime getDateTime();
	static QTime getCurrentTime();
};
#endif UTILITY_H
