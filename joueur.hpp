#pragma once

#include "plateau.hpp"
#include <string>
#include <iostream>

/*! Classe de base pour tous les joueurs
 * Bien que le jeu ait un gameplay asymetrique, les deux tours de jeu ont une structure commune,
 * repr�sent�e par la classe joueur. Cette classe demande au joueur de choisir une case valide
 * (la validation est laiss�e aux classes enfant), puis joue cette case (la encore l'action est
 * effectu�e par les classes enfant).
 * Chaque joueur garde en m�moire son pseudo (affich� par la fonction jouer()) ainsi qu'une r�f�rence vers le plateau de jeu.
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
