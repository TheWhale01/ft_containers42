#include <vector>
#include <iostream>

int main(void)
{
	size_t len = 5;
	std::vector<int> v;

	for (size_t i = 0; i < len; i++)
		v.push_back(i);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;
	return (0);
}