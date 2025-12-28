#ifndef TIME_HPP
#define TIME_HPP


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

		static double m_start;
		static double m_end;

		static double now();
};

#endif //TIME_HPP
