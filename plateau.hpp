#pragma once

#include <ostream>
#include <map>

// Des fois, c'est juste pas la peine de s'embeter avec une classe ...
typedef std::tuple<bool, bool> Case; // <broken, free>
typedef std::tuple<size_t, size_t> Position; // <x, y>

class Plateau {
	public:
		explicit Plateau(size_t dim = 35);
		friend std::ostream& operator<< (std::ostream& out, Plateau& plateau);
		Case getCase(const Position& pos) const;
		void setCase(const Position& pos, const Case& cell);
		size_t getDim() const;
	private:
		std::map<Position, Case> m_gameboard;
		size_t m_dim;
};
