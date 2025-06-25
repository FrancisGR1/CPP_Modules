#include <iostream>

const size_t DEFAULT_CAPACITY = 10;

template <typename T>
class Vector {
	public:
		Vector(T el)
			: m_data(new T[DEFAULT_CAPACITY])
		{
			m_data[0] = el;
			m_size++;
		}

		Vector(const Vector& to_copy)
			: m_data(new T[to_copy.m_capacity])
			, m_size(to_copy.m_size)
			, m_capacity(to_copy.m_capacity)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = to_copy.m_data[i];
			}

		}

		~Vector()
		{
			delete[] m_data;
		}

		void push_back(T* el)
		{
			if (m_size >= m_capacity)
			{
				realloc(m_capacity * 2);
			}
			m_data[m_size] = el;
			m_size++;
		}

		void push_back(const T* el)
		{
			if (m_size >= m_capacity)
			{
				realloc(m_capacity * 2);
			}
			m_data[m_size] = el;
			m_size++;
		}

		size_t size(void) { return m_size; }
		size_t capacity(void) { return m_capacity; }

		T& operator[](size_t idx)
		{
			return (m_data[idx]);
		}

		T& operator=(const T& to_copy)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = to_copy.m_data[i];
			}
			return (*this);
		}

	private:
		T* m_data;


		size_t m_size = 0;
		size_t m_capacity = DEFAULT_CAPACITY;

		void realloc(size_t new_capacity)
		{
			T* new_data = new T[new_capacity];
			for (size_t i = 0; i < m_size; ++i)
			{
				new_data[i] = m_data[i];
			}
			delete[] m_data;
			m_data = new_data;
			m_capacity = new_capacity;
		}
};
