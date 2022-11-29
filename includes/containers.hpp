#pragma once

#ifndef NM
# define NM ft
# include "vector.hpp"
#else
# include <vector>
# include <iostream>
#endif

template<class T>
std::ostream &operator<<(std::ostream &stream, NM::vector<T> v)
{
	typename NM::vector<T>::iterator it;

	stream << "[";
	for (it = v.begin(); it != v.end(); it++)
		stream << *it << (it + 1 == v.end() ? "" : ", ");
	stream << "]";
	return (stream);
}
