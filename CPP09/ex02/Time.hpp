#ifndef TIME_HPP
#define TIME_HPP

#include <sys/time.h>

class Time
{
	public:
		static void start();
		static void stop();
		static double elapsed();

	private:
		Time();
		Time(const Time& other);
		Time& operator=(const Time& other);
		~Time();

		static timeval m_start;
		static timeval m_end;

		// utils
		static timeval now();
};

#endif //TIME_HPP
