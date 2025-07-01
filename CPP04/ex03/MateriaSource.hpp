#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

const size_t MAX_MATERIAS = 4;

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		virtual ~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(const std::string& type);
	private:
		AMateria* m_materias[MAX_MATERIAS];
		size_t m_idx;
};

#endif /*MATERIASOURCE_HPP*/
