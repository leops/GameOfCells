#pragma once

#include "joueur.hpp"

/*! Joueur ayant la capacité de détruire des cases
 * Classe relativement simple par rapport a la classe Ange puisque le démon n'a pas de présence
 * physique sur le plateau, cette classe n'a donc qu'a verifier que les cases choisies par le joueur
 * sont valides et a les briser.
 */
class Demon : public Joueur {
	public:
		explicit Demon(Plateau& plateau, const std::string& nom = "Demon");
		bool incorrect(const Position& pos) const;
		void modifierCase(const Position& pos);
};
