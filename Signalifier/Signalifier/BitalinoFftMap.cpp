#include "BitalinoFftMap.h"


bool BitalinoFftMap::isFftScriptRunning()
{
	return _isFftScriptRunning;
}

void BitalinoFftMap::setIsFftFactoryRunningFlag(const bool& result)
{
	_isFftScriptRunning = result;
}