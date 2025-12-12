#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t size, F fun)
{
	for (size_t i = 0; i < size; ++i)
		fun(array[i]);
}

#endif //ITER_HPP
