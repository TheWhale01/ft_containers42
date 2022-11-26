#pragma once

#include <vector>
#include <iostream>

template<typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> v)
{
	stream << "[";
	typename std::vector<T>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		stream << *it << (it + 1 == v.end() ? "" : ", ");
	stream << "]";
	return (stream);
}