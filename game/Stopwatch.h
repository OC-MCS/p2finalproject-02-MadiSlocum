#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch
{
public:

	enum STOPWATCH_UNITS
	{
		MILLISECONDS = 1,
		SECONDS = 1000
	};

	Stopwatch();
	void start();
	void stop();
	void reset();
	long long getElapsedTime(STOPWATCH_UNITS units = MILLISECONDS) const;

private:

	std::chrono::high_resolution_clock::time_point tpStart;
	std::chrono::milliseconds elapsedTime;
	bool bPaused;
};

#endif