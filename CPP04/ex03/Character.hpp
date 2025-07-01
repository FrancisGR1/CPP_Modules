#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const Character&);
		Character(std::string name);
		Character& operator=(const Character&);
		~Character();

		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		const std::string m_name;
		size_t m_idx;
		AMateria* m_materias[MAX_MATERIAS];
};

#endif /*CHARACTER_HPP*/
