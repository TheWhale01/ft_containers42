#pragma once

class Stack
{
	public:
		Stack(void);
		Stack(Stack const &rhs);
		~Stack(void);

		Stack &operator=(Stack const &rhs);
};