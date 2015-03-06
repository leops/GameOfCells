#include "angePuissant.hpp"

using namespace std;

//! Le constructeur demande en plus a l'utilisateur la force de l'ange
AngePuissant::AngePuissant(Plateau& plateau, const std::string & nom) : Ange(plateau, nom) {
	cout << "Entrez la force de l'ange:";
	cin >> m_force;
}

//! Ici la distance ne doit pas être inferieur à 2 mais à (m_force + 1)
bool AngePuissant::incorrect(const Position& pos) const {
	auto cell = getPlateau().getCase(pos);
	auto len = dist(pos, getPosition());
	size_t dim = getPlateau().getDim(),
		x = get<0>(pos),
		y = get<1>(pos);
	return get<0>(cell) || len >= (m_force + 1) || x > dim || y > dim;
}

//! Teste toutes les cases a porté de l'ange
bool AngePuissant::canMove() const {
	auto pos = getPosition();
	auto dim = getPlateau().getDim();
	int x = get<0>(pos),
		y = get<1>(pos),
		downX = max<unsigned int>(x - m_force, 0),
		upX = min(x + m_force, dim),
		downY = max<unsigned int>(y - m_force, 0),
		upY = min(y + m_force, dim);

	for (int i = downX; i <= upX; i++)
		for (int j = downY; j <= upY; j++)
			if ((i != x || j != y) && !incorrect(Position(i, j)))
				return true;

	return false;
}
