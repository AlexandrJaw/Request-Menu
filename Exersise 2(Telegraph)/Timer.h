#pragma once
#include <time.h>
using namespace std;

using millis = clock_t;
using second = clock_t;
using hour = clock_t;
using minutes = clock_t;

class Timer
{
private:
	millis start = clock();
public:

	inline void reset(void)
	{
		start = clock();
	}

	inline millis getElapsedTime(void)
	{
		return clock() - start;
	}

	inline second getSecond(millis mil)
	{
		return mil / 1000;
	}

	inline minutes getMinutes(millis mil)
	{
		return getSecond(mil) / 60;
	}

	inline hour getHour(millis mil)
	{
		return getMinutes(mil) / 60;
	}
};

void sleep(millis mil)
{
	Timer time;
	while(time.getElapsedTime() < mil) {}
}