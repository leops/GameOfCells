#include "demon.hpp"

using namespace std;

Demon::Demon(Partie* partie, const std::string & nom) : Joueur(partie, nom) {
}

bool Demon::incorrect(const Position & pos) const {
	auto cell = getPlateau().getCase(pos);
	return get<0>(cell) || !get<1>(cell);
}

void Demon::modifierCase(const Position & pos) {
	getPlateau().setCase(pos, Case(true, true));
}
