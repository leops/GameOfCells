#include "ange.hpp"

using namespace std;

//! Initialise l'ange en le placant au milieu du plateau
Ange::Ange(Plateau& plateau, const std::string & nom) : Joueur(plateau, nom) {
	auto size = getPlateau().getDim();
	m_pos = Position(size / 2, size / 2);
	getPlateau().setCase(m_pos, Case(false, false));
}

//! Fonction utilitaire pour calculer la distance entre 2 points
double Ange::dist(const Position& a, const Position& b) {
	int aX = get<0>(a), aY = get<1>(a),
		bX = get<0>(b), bY = get<1>(b),
		x = abs(aX - bX),
		y = abs(aY - bY);
	return sqrt(pow(x, 2) + pow(y, 2));
}

//! Une case est incorrecte si elle est brisée, trop loins ou hors du plateau
bool Ange::incorrect(const Position & pos) const {
	auto cell = getPlateau().getCase(pos);
	auto len = dist(pos, m_pos);
	size_t dim = getPlateau().getDim(),
		x = get<0>(pos),
		y = get<1>(pos);
	return get<0>(cell) || len >= 2 || x > dim || y > dim;
}

//! Lorsque l'ange se déplace
void Ange::modifierCase(const Position & pos) {
	getPlateau().removeCase(m_pos);  // Remet la case courante a sa valeur par défaut (en la supprimant pour liberer de la memoire)
	getPlateau().setCase(pos, Case(false, false));  // Met l'attribut free de la nouvelle case a false
	setPosition(pos);  // Et change la position courante de l'ange
}

//! Un setter pour m_pos
void Ange::setPosition(const Position& pos) {
	m_pos = pos;
}

//! L'ange peut bouger si au moins une case voisine n'est pas incorrecte
bool Ange::canMove() const {
	int x = get<0>(m_pos),
		y = get<1>(m_pos),
		dim = getPlateau().getDim(),
		downX = max(x - 1, 0),
		upX = min(x + 1, dim),
		downY = max(y - 1, 0),
		upY = min(y + 1, dim);

	for (int i = downX; i <= upX; i++)
		for (int j = downY; j <= upY; j++)
			if ((i != x || j != y) && !incorrect(Position(i, j)))
				return true;

	return false;
}

//! Getter pour m_pos
Position Ange::getPosition() const {
	return m_pos;
}

//! L'ange a gagné si il atteint le bord du plateau
bool Ange::hasWon() const {
	size_t dim = getPlateau().getDim() - 1,
		x = get<0>(m_pos),
		y = get<1>(m_pos);
	if (x == 0 || y == 0 || x >= dim || y >= dim)
		return true;
	else
		return false;
}
