#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		virtual ~Cat();

		virtual std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;

};
#endif /*CAT_HPP*/
