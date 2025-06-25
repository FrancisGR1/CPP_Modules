#include "Character.hpp"

Character::Character() 
	: m_name("")
	, m_idx(0) 
{
	for (size_t i = 0; i < MAX_MATERIAS; i++)
	{
		m_materias[i] = NULL;
	}
};

Character::Character(std::string name) 
	: m_name(name)
	, m_idx(0)
{
	for (size_t i = 0; i < MAX_MATERIAS; i++)
	{
		m_materias[i] = NULL;
	}
};

Character::~Character() 
{
	for (size_t i = 0; i < MAX_MATERIAS; i++)
	{
		if (m_materias[i])
		{
			delete m_materias[i];
			m_materias[i] = NULL;
		}
	}
};

const std::string& Character::getName() const
{
	return (m_name);
};

void Character::equip(AMateria* m)
{
	if (m_idx == MAX_MATERIAS)
	{
		std::cerr << "Inventory is full!" << std::endl;
		return ;
	}
	m_materias[m_idx] = m;
	m_idx++;
};

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < static_cast<int>(MAX_MATERIAS) && m_materias[idx])
		m_materias[idx] = NULL;
};

void Character::use(int idx, ICharacter& target)
{
	if (idx >= static_cast<int>(MAX_MATERIAS) || idx < 0)
	{
		std::cerr << "Wrong index: " << idx << std::endl;
	}
	else if (!m_materias[idx])
	{
		std::cerr << "Nothing equiped at: " << idx << std::endl;
	}
	else
	{
		m_materias[idx]->use(target);
	};

};
