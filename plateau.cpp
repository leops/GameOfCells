#include "plateau.hpp"

using namespace std;

Plateau::Plateau(size_t dim) : m_dim(dim) {
	m_gameboard.emplace(Position(dim / 2, dim / 2), Case(false, false));
}

Case Plateau::getCase(const Position& pos) const {
	if (m_gameboard.count(pos) > 0) {
		return m_gameboard.at(pos);
	} else {
		return Case(false, true);
	}
}

void Plateau::setCase(const Position & pos, const Case & cell) {
	auto it = m_gameboard.find(pos);
	if(it != m_gameboard.end())
		it->second = cell;
}

size_t Plateau::getDim() const {
	return m_dim;
}

std::ostream& operator<< (std::ostream& out, Plateau& plateau) {
	for (int x = 0; x < plateau.m_dim; x++) {
		for (int y = 0; y < plateau.m_dim; y++) {
			auto point = plateau.getCase(Position(x, y));
			if (!get<1>(point)) {
				out << 'O';
			} else if (get<0>(point)) {
				out << 'X';
			} else {
				out << '.';
			}
			out << ' ';
		}
		out << endl;
	}
	return out;
}
