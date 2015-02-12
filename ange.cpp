#include "ange.hpp"

using namespace std;

Ange::Ange(Plateau& plateau, const std::string & nom) : Joueur(plateau, nom) {
	auto size = getPlateau().getDim();
	m_pos = Position(size / 2, size / 2);
}

size_t dist(const Position& a, const Position& b) {
	return sqrt(pow(get<0>(a) - get<0>(b), 2) + pow(get<1>(a) - get<1>(b), 2));
}

bool Ange::incorrect(const Position & pos) const {
	auto cell = getPlateau().getCase(pos);
	return get<0>(cell) || !get<1>(cell) || dist(pos, m_pos) > 1;
}

void Ange::modifierCase(const Position & pos) {
	getPlateau().setCase(m_pos, Case(false, true));
	getPlateau().setCase(pos, Case(false, false));
	m_pos = pos;
}
