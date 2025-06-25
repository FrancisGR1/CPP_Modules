#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		virtual ~Cat();

		virtual std::string getType() const;
		virtual void makeSound() const;
		Cat* clone() const;

	protected:
		std::string type;

	private:
		Brain* b;


};
#endif /*CAT_HPP*/
