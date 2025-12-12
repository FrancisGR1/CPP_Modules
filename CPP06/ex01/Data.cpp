#include "Data.hpp"

void set_data(Data* d, const std::string& name, const std::string& location)
{
	if (!d)
		return;
	d->name = name;
	d->location = location;
};
