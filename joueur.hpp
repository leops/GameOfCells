#pragma once

#include "plateau.hpp"
#include <string>
#include <iostream>

/*! Classe de base pour tous les joueurs
 * Bien que le jeu ait un gameplay asymetrique, les deux tours de jeu ont une structure commune,
 * représentée par la classe joueur. Cette classe demande au joueur de choisir une case valide
 * (la validation est laissée aux classes enfant), puis joue cette case (la encore l'action est
 * effectuée par les classes enfant).
 * Chaque joueur garde en mémoire son pseudo (affiché par la fonction jouer()) ainsi qu'une référence vers le plateau de jeu.
 */
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
