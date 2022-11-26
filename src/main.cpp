#include "Vector.hpp"

int main(void)
{
	ft::Vector<int> v;

	v.assign(5, 10);
	for (size_t i = 0; i < 4; i++)
		std::cout << v[i] << std::endl;
	return (0);
}