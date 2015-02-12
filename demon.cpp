#include "demon.hpp"

using namespace std;

Demon::Demon(Plateau& plateau, const std::string & nom) : Joueur(plateau, nom) {
}

bool Demon::incorrect(const Position & pos) const {
	auto cell = getPlateau().getCase(pos);
	return get<0>(cell) || !get<1>(cell);
}

void Demon::modifierCase(const Position & pos) {
	getPlateau().setCase(pos, Case(true, true));
}
