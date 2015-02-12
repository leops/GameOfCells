#pragma once

#include "plateau.hpp"
#include <string>
#include <iostream>

class Joueur {
	public:
		explicit Joueur(Plateau& plateau, const std::string& nom = "Joueur");
		Position saisir() const;
		virtual bool incorrect(const Position& pos) const = NULL;
		Position choisirCase() const;
		virtual void modifierCase(const Position& pos) = NULL;
		void jouer();
		Plateau& getPlateau() const;
	private:
		Plateau& m_plateau;
		std::string m_pseudo;
};
