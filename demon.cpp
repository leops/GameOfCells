#include "demon.hpp"

using namespace std;

//! Appelle juste le constructeur parent
Demon::Demon(Plateau& plateau, const std::string & nom) : Joueur(plateau, nom) {
}

//! Une case est incorrecte si elle est hors du plateau, non libre ou déjà brisée
bool Demon::incorrect(const Position & pos) const {
	auto dim = getPlateau().getDim();
	auto cell = getPlateau().getCase(pos);
	return get<0>(pos) >= dim || get<1>(pos) >= dim|| get<0>(cell) || !get<1>(cell);
}

//! Pour le demon jouer une case revient simplement a la detuire
void Demon::modifierCase(const Position & pos) {
	getPlateau().setCase(pos, Case(true, true));
}
