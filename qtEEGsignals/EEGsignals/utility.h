#ifndef UTILITY_H
#define UTILITY_H

#include <QDateTime>


//this class should contain only static methods used throughout the application
class utility
{
public:
	utility();
	~utility();
	static QDateTime getDateTime();

};
#endif UTILITY_H
