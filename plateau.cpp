#include "plateau.hpp"

using namespace std;

Plateau::Plateau(size_t dim) : m_dim(dim) {
	m_gameboard.emplace(Position(dim / 2, dim / 2), Case(false, false));
}

std::ostream& operator<< (std::ostream& out, Plateau& plateau) {
	for (int x = 0; x < plateau.m_dim; x++) {
		for (int y = 0; y < plateau.m_dim; y++) {
			Case point;
			auto pos = Position(x, y);
			if(plateau.m_gameboard.count(pos) > 0) {
				point = plateau.m_gameboard.at(pos);
			} else {
				point = Case(false, true);
			}
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
