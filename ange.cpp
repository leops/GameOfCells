#include "ange.hpp"
#include "partie.hpp"

using namespace std;

Ange::Ange(Partie* partie, const std::string & nom) : Joueur(partie, nom) {
	auto size = getPlateau().getDim();
	m_pos = Position(size / 2, size / 2);
}

double Ange::dist(const Position& a, const Position& b) {
	int aX = get<0>(a), aY = get<1>(a),
		bX = get<0>(b), bY = get<1>(b),
		x = abs(aX - bX),
		y = abs(aY - bY);
	return sqrt(pow(x, 2) + pow(y, 2));
}

bool Ange::incorrect(const Position & pos) const {
	auto cell = getPlateau().getCase(pos);
	auto len = dist(pos, m_pos);
	size_t dim = getPlateau().getDim(),
		x = get<0>(pos),
		y = get<1>(pos);
	return get<0>(cell) || len >= 2 || x > dim || y > dim;
}

void Ange::modifierCase(const Position & pos) {
	getPlateau().setCase(m_pos, Case(false, true));
	getPlateau().setCase(pos, Case(false, false));
	m_pos = pos;
}

bool Ange::canMove() const {
	int x = get<0>(m_pos),
		y = get<1>(m_pos),
		dim = getPlateau().getDim(),
		downX = max(x - 1, 0),
		upX = min(x + 1, dim),
		downY = max(y - 1, 0),
		upY = min(y + 1, dim);

	for (int i = downX; i < upX; i++)
		for (int j = downY; j < upY; j++)
			if (!incorrect(Position(i, j)))
				return true;

	return false;
}

Position Ange::getPosition() const {
	return m_pos;
}

bool Ange::hasWon() const {
	size_t dim = getPlateau().getDim() - 1,
		x = get<0>(m_pos),
		y = get<1>(m_pos);
	if (x == 0 || y == 0 || x >= dim || y >= dim)
		return true;
	else
		return false;
}
