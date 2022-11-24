#pragma once
#include <iostream>

template<typename T>
class Vector
{
	public:
		Vector(void);
		Vector(Vector const &rhs);
		~Vector(void);

		Vector &operator=(Vector const &rhs);
	
	private:
		T *_data;
		size_t _size;
};