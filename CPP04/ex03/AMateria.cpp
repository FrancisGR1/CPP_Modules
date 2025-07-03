#include "AMateria.hpp"

AMateria::AMateria() {}


AMateria::AMateria(const AMateria& other)
	: m_type(other.getType())
{};

AMateria::AMateria(const std::string& type)
	: m_type(type)
{};

AMateria& AMateria::operator=(const AMateria& other)
{
	m_type = other.getType();
	return *this;
};

AMateria::~AMateria() {}

const std::string& AMateria::getType() const { return m_type; }

//@REVIEW: Isto é de propósito? "(void) target"
void AMateria::use(ICharacter& target) { (void) target; }
