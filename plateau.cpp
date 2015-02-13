#include "plateau.hpp"

using namespace std;

Plateau::Plateau(size_t dim) : m_dim(dim) {
	if (m_dim % 2 == 0)
		m_dim++;
	m_gameboard.emplace(Position(m_dim / 2, m_dim / 2), Case(false, false));
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
	if (it != m_gameboard.end())
		it->second = cell;
	else
		m_gameboard.emplace(pos, cell);
}

size_t Plateau::getDim() const {
	return m_dim;
}

Plateau & Plateau::operator++(void) {
	m_dim += 2;
	map<Position, Case> temp;
	for (auto i : m_gameboard) {
		auto pos = i.first;
		temp.emplace(Position(get<0>(pos) + 1, get<1>(pos) + 1), i.second);
	}
	m_gameboard = temp;
	return *this;
}

std::ostream& operator<< (std::ostream& out, Plateau& plateau) {
	for (size_t x = 0; x < plateau.m_dim; x++) {
		for (size_t y = 0; y < plateau.m_dim; y++) {
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
