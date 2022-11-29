#include "containers.hpp"
#include <vector>

using namespace NM;

int main(void)
{
	size_t len = 10;
	vector<int> v;

	for (size_t i = 0; i < len; i++)
		v.push_back(i);
	std::cout << v << std::endl;
	std::cout << v.size() << std::endl;
	return (0);
}