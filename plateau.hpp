#pragma once

#include <ostream>
#include <map>

typedef std::tuple<bool, bool> Case; // <broken, free>
typedef std::tuple<int, int> Position; // <x, y>

class Plateau {
	public:
		explicit Plateau(size_t dim = 35);
		friend std::ostream& operator<< (std::ostream& out, Plateau& plateau);
	private:
		std::map<Position, Case> m_gameboard;
		size_t m_dim;
};
