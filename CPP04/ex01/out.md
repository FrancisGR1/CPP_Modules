#include "Animal.hpp"

Animal::Animal()
	: type("Animal") { std::cout << "<Animal> constructed" << std::endl; }

Animal::~Animal() { std::cout << "<Animal> destructed" << std::endl; }

std::string Animal::getType() const { return type; }
void Animal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();

		virtual std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;

};
#endif /*ANIMAL_HPP*/
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

const size_t IDEAS = 100;

class Brain
{
	public:
		//TODO: constructor; TODO: Destructor
		std::string ideas[IDEAS];
};
#endif /*BRAIN_HPP*/
#include "Cat.hpp"

Cat::Cat()
	: type("Cat") 
	, b(new Brain())
{ 
	std::cout << "<Cat> constructed" << std::endl; 
}

Cat::~Cat() 
{ 
	delete b;
	std::cout << "<Cat> destructed" << std::endl; 
}

std::string Cat::getType() const { return type; }
void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();

		virtual std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;

	private:
		Brain* b;


};
#endif /*CAT_HPP*/
#include "Dog.hpp"

Dog::Dog()
	: type("Dog") 
	, b(new Brain())
{ 
	std::cout << "<Dog> constructed" << std::endl; 
};

Dog::~Dog()
{ 
	delete b;
	std::cout << "<Dog> destructed" << std::endl; 
}

std::string Dog::getType() const { return type; }
void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();

		virtual std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;

	private:
		Brain* b;

};
#endif /*DOG_HPP*/
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	size_t size = 10;
	Animal* animals[size];
	for (size_t i = 0; i < size; i++)
	{
		if (i < size)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	delete j;//should not create a leak
	delete i;

	for (size_t i = 0; i < size; i++)
	{
		delete animals[i];
	}
}
NAME = a.out

VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall -Wshadow -Wno-shadow $(VERSION)
SRC     = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal") { std::cout << "<WrongAnimal> constructed" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "<WrongAnimal> destructed" << std::endl; }

std::string WrongAnimal::getType() const { return type; }
void WrongAnimal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;

};
#endif /*WRONGANIMAL_HPP*/
#include "WrongCat.hpp"

WrongCat::WrongCat()
	: type("WrongCat") { std::cout << "<WrongCat> constructed" << std::endl; }

WrongCat::~WrongCat() { std::cout << "<WrongCat> destructed" << std::endl; }

std::string WrongCat::getType() const { return type; }
void WrongCat::makeSound() const { std::cout << "Meow!" << std::endl; }
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;

};
#endif /*WRONGCAT_HPP*/
#include "Animal.hpp"

Animal::Animal()
	: type("Animal") { std::cout << "<Animal> constructed" << std::endl; }

Animal::Animal(const Animal& other) 
	: type(other.type)
{
	std::cout << "<Animal> copy constructed" << std::endl;
};

Animal& Animal::operator=(const Animal &other) 
{ 
	std::cout << "<Animal> Assignment operator called" << std::endl;
	type = other.type;
	return *this; 
};

Animal::~Animal() { std::cout << "<Animal> destroyed" << std::endl; }

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }

Animal* Animal::clone() const
{
	return new Animal(*this);
};
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		virtual ~Animal();

		virtual std::string getType() const;
		virtual void makeSound() const;
		virtual Animal* clone() const;
	protected:
		std::string type;

};
#endif /*ANIMAL_HPP*/
#include "Brain.hpp"

Brain::Brain()  
{ 
	std::cout << "<Brain> constructed " << std::endl; 
}

Brain::Brain(const Brain& other)
{
	copyIdeas(other);
	std::cout << "<Brain> copied " << std::endl; 
};

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "<Brain> Assignment operator called" << std::endl;
	copyIdeas(other);
	return (*this);
};

Brain::~Brain() 
{ 
	std::cout << "<Brain> destructed " << std::endl; 
}

void Brain::copyIdeas(const Brain& other)
{
	for(size_t i = 0; i < IDEAS; i++)
	{
		std::cout << "copying " << i << std::endl;
		ideas[i] = other.ideas[i];
	}
};
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
#include "Cat.hpp"

Cat::Cat()
	: type("Cat") { std::cout << "<Cat> constructed" << std::endl; }

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "<Cat> Assignment operator called" << std::endl;
	type = other.type;
	return *this;
};

//@TODO: qual versão é que implemento?
/*Cat::Cat(const Cat& other)
	: type(other.type)
{
	std::cout << "<Cat> copy constructed" << std::endl;
};*/

Cat::Cat(const Cat& other)
	: Animal(other)
{
	type = other.type;
	b = new Brain(*other.b);
	std::cout << "<Cat> copied" << std::endl;
};

Cat::~Cat() { std::cout << "<Cat> destroyed" << std::endl; }

std::string Cat::getType() const { return type; }

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

Cat* Cat::clone() const
{
	std::cout << "<Cat> clone" << std::endl; 
	return new Cat(*this);
};
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);
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
#include "Dog.hpp"

Dog::Dog()
	: type("Dog") 
	, b(new Brain())
{ 
	std::cout << "<Dog> constructed" << std::endl; 
};

Dog::Dog(const Dog& other)
	: Animal(other)
{
	type = other.type;
	b = new Brain(*other.b);
	std::cout << "<Dog> copied" << std::endl;
};

Dog::~Dog()
{ 
	delete b;
	std::cout << "<Dog> destructed" << std::endl; 
}

std::string Dog::getType() const { return type; }

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

Dog* Dog::clone() const
{
	std::cout << "<Dog> clone" << std::endl; 
	return new Dog(*this);
};
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		std::string getType() const;
		void makeSound() const;
		Dog* clone() const;


	protected:
		std::string type;

	private:
		Brain* b;

};
#endif /*DOG_HPP*/
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

//https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/
int main()
{
	Animal* d = new Dog();
	Animal* c = new Cat();

	size_t size = 4;
	Animal* animals[size];

	std::cout << "deep copies: " << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "construct loop: " << i << std::endl;
		if (i < size / 2)
			animals[i] = d->clone();
		else
			animals[i] = c->clone();
	}
	delete d;//should not create a leak
	delete c;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "delete loop: " << i << std::endl;
		delete animals[i];
	}
}
NAME = a.out

CXX     =  c++
VERSION = -std=c++98
FLAGS   = -Werror -Wextra -Wall -Wshadow -Wno-shadow $(VERSION)
SRC     = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ     = $(SRC:.cpp=.o) 
INC     = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: type("WrongAnimal") { std::cout << "<WrongAnimal> constructed" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type)
{
	std::cout << "<WrongAnimal> copy constructed" << std::endl;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "<WrongAnimal> Assignment operator called" << std::endl;
	type = other.type;
	return (*this);
};

WrongAnimal::~WrongAnimal() { std::cout << "<WrongAnimal> destructed" << std::endl; }

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const { std::cout << "(What is the sound of an abstract category?)" << std::endl; }

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&);
		WrongAnimal& operator=(const WrongAnimal&);
		~WrongAnimal();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;

};
#endif /*WRONGANIMAL_HPP*/
#include "WrongCat.hpp"

WrongCat::WrongCat()
	: type("WrongCat") { std::cout << "<WrongCat> constructed" << std::endl; }

WrongCat::~WrongCat() { std::cout << "<WrongCat> destructed" << std::endl; }

std::string WrongCat::getType() const { return type; }
void WrongCat::makeSound() const { std::cout << "Meow!" << std::endl; }
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat&);
		WrongCat& operator=(const WrongCat&);
		~WrongCat();

		std::string getType() const;
		void makeSound() const;

	protected:
		std::string type;

};
#endif /*WRONGCAT_HPP*/
