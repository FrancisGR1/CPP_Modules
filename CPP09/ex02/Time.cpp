#include <cstddef>
#include <sys/time.h>

#include "Time.hpp"

double Time::m_start = 0.0;
double Time::m_end   = 0.0;

void Time::start()
{
	m_start = now();
}

void Time::stop()
{
	m_end = now();
}

double Time::elapsed()
{
	return m_end - m_start;
}

double Time::now()
{
	timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec + t.tv_usec * 1e-6;
}
