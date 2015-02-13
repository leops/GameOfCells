#include "angePuissant.hpp"

using namespace std;

AngePuissant::AngePuissant(Partie* partie, const std::string & nom) : Ange(partie, nom) {
	cout << "Entrez la force de l'ange:";
	cin >> m_force;
}

bool AngePuissant::incorrect(const Position& pos) const {
	auto cell = getPlateau().getCase(pos);
	auto len = dist(pos, getPosition());
	size_t dim = getPlateau().getDim(),
		x = get<0>(pos),
		y = get<1>(pos);
	return get<0>(cell) || len >= (m_force + 1) || x > dim || y > dim;
}

bool AngePuissant::canMove() const {
	auto pos = getPosition();
	auto dim = getPlateau().getDim();
	int x = get<0>(pos),
		y = get<1>(pos),
		downX = max<unsigned int>(x - m_force, 0),
		upX = min(x + m_force, dim),
		downY = max<unsigned int>(y - m_force, 0),
		upY = min(y + m_force, dim);

	for (int i = downX; i < upX; i++)
		for (int j = downY; j < upY; j++)
			if (!incorrect(Position(i, j)))
				return true;

	return false;
}
