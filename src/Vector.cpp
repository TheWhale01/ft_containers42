#include "Vector.hpp"

Vector::Vector(void)
{
	return ;
}

Vector::Vector(Vector const &rhs)
{
	*this = rhs;
	return ;
}

Vector::~Vector(void)
{
	return ;
}

/* OPERATOR OVERLOAD */

Vector &Vector::operator=(Vector const &rhs)
{
	(void)rhs;
	return (*this);
}

/* MEMBER FUNCTIONS */
