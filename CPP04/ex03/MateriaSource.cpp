#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() 
	: m_idx(0) 
{
    for (size_t i = 0; i < MAX_MATERIAS; i++) 
    {
        m_materias[i] = NULL;
    }
};

MateriaSource::MateriaSource(const MateriaSource& other)
	: IMateriaSource(other)
	, m_idx(other.m_idx)
{
    for (size_t i = 0; i < MAX_MATERIAS; i++) 
    {
        m_materias[i] = other.m_materias[i];
    }
};

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	m_idx = other.m_idx;

	for (size_t i = 0; i < MAX_MATERIAS; i++) 
	{
		m_materias[i] = other.m_materias[i];
	}
	return (*this);
};

MateriaSource::~MateriaSource() 
{
	for (size_t i = 0; i < MAX_MATERIAS; i++) 
	{
		if (m_materias[i]) 
		{
			delete m_materias[i];
		}
	}
};

void MateriaSource::learnMateria(AMateria* creation)
{
	if (m_idx == MAX_MATERIAS)
		m_idx = 0;

	if (m_materias[m_idx])
		delete m_materias[m_idx];

	m_materias[m_idx] = creation;
	m_idx++;
};

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (size_t i = 0; i < MAX_MATERIAS; i++) 
	{
		if (m_materias[i] && m_materias[i]->getType() == type) 
		{
			return m_materias[i]->clone();
		}
	}
	return NULL;
};
