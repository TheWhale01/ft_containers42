#pragma once

class Map
{
	public:
		Map(void);
		Map(Map const &rhs);
		~Map(void);

		Map &operator=(Map const &rhs);
};