#pragma once

#include "plateau.hpp"
#include <string>
#include <iostream>

class Partie;

class Joueur {
	public:
		explicit Joueur(Partie* partie, const std::string& nom = "Joueur");
		Position saisir() const;
		virtual bool incorrect(const Position& pos) const = NULL;
		Position choisirCase() const;
		virtual void modifierCase(const Position& pos) = NULL;
		void jouer();
		Plateau& getPlateau() const;
	private:
		Partie* m_partie;
		std::string m_pseudo;
};

//std::ostream& operator<< (std::ostream& out, const Position& t);
