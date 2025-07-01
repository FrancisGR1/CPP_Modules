#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

const size_t IDEAS = 100;

class Brain
{
	public:
		Brain();
		Brain(const Brain&);
		Brain& operator=(const Brain&);
		~Brain();

		std::string ideas[IDEAS];

	private:
		void copyIdeas(const Brain& other);
};
#endif /*BRAIN_HPP*/
