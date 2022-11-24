#include "Stack.hpp"

Stack::Stack(void)
{
	return ;
}

Stack::Stack(Stack const &rhs)
{
	*this = rhs;
	return ;
}

Stack::~Stack(void)
{
	return ;
}

/* OPERATOR OVERLOAD */

Stack &Stack::operator=(Stack const &rhs)
{
	(void)rhs;
	return (*this);
}

/* MEMBER FUNCTIONS */
