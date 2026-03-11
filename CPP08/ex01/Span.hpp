#include <vector>
#include <cstddef>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int num);
		void setNumberAt(int num, size_t idx);
		void fillRandom(int modulus);
		int  shortestSpan() const;
		int  longestSpan() const;
		void  print() const;

	private:
		std::vector<int> m_data;
};
