#include <cstddef>
#include <sys/time.h>

#include "Time.hpp"

timeval Time::m_start;
timeval Time::m_end;

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
    return (m_end.tv_sec - m_start.tv_sec) + 
           (m_end.tv_usec - m_start.tv_usec) / 1000000.0;
}

timeval Time::now()
{
	timeval t;
	gettimeofday(&t, NULL);
	return t;
}
