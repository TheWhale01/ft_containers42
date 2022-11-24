#include "Map.hpp"

Map::Map(void)
{
	return ;
}

Map::Map(Map const &rhs)
{
	*this = rhs;
	return ;
}

Map::~Map(void)
{
	return ;
}

/* OPERATOR OVERLOAD */

Map &Map::operator=(Map const &rhs)
{
	(void)rhs;
	return (*this);
}

/* MEMBER FUNCTIONS */
