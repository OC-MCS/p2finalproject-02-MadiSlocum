#include "Stopwatch.h"
using namespace std::chrono;

Stopwatch::Stopwatch()
	: elapsedTime(0), bPaused(true)
{

}

void Stopwatch::start()
{
	if (bPaused)
		bPaused = false;	// Start/Resume
	else
		elapsedTime = milliseconds::zero();	// Restart

	tpStart = high_resolution_clock::now();
}

void Stopwatch::stop()
{
	if (!bPaused)
	{
		elapsedTime += duration_cast<milliseconds>(high_resolution_clock::now() - tpStart);
		bPaused = true;
	}
}

void Stopwatch::reset()
{
	bPaused = true;
	elapsedTime = milliseconds::zero();
}

long long Stopwatch::getElapsedTime(STOPWATCH_UNITS units/*= MILLISECONDS*/) const
{
	if (bPaused)
		return elapsedTime.count() / units;
	else
		return duration_cast<milliseconds>(high_resolution_clock::now() - tpStart).count() / units;
}