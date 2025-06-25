#include "AMateria.hpp"

AMateria::AMateria() {}
AMateria::~AMateria() {}

AMateria::AMateria(const std::string& type)
	: m_type(type)
{};

const std::string& AMateria::getType() const { return m_type; }

void AMateria::use(ICharacter& target) { (void) target; }
