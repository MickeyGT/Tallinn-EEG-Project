//This class should contain only static methods used throughout the application.
#ifndef UTILITY_H
#define UTILITY_H

#include <QDateTime>

class Utility
{
public:
	Utility();
	~Utility();
	static QDateTime getDateTime();

};
#endif UTILITY_H
