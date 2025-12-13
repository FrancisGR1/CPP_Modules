#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx) const;
		unsigned int size() const;

	private:
		unsigned int m_size;
		T* m_data;
};

template <typename T>
Array<T>::Array()
	: m_size(0)
	, m_data(NULL)
{}

template <typename T>
Array<T>::Array(unsigned int n)
	: m_size(n)
	, m_data(new T[n]())
{}

template <typename T>
Array<T>::Array(const Array& other)
	: m_size(other.m_size)
	, m_data(NULL)
{
	if (!(m_size > 0))
		return ;

	m_data = new T[m_size];
	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i] = other.m_data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	delete[] m_data;

	m_size = other.m_size;
	m_data = new T[m_size];
	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i] = other.m_data[i];
	}

	return *this;
}

template <typename T>
Array<T>::~Array()
{
	m_size = 0;
	delete[] m_data;
}


template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= m_size)
		throw std::out_of_range("Index is out of bounds");
	return m_data[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= m_size)
		throw std::out_of_range("Index is out of bounds");
	return m_data[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return m_size;
}

#endif //ARRAY_HPP
