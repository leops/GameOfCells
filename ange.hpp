#pragma once

#include "joueur.hpp"
#include <cmath>
#include <algorithm>

/*! Classe de gestion de l'ange.
 * L'ange est pr�sent physiquement sur la plateau et doit donc avoir une position stock�e dans une variable.
 * En plus des fonctions h�rit�es de Joeur, il dispose d'une fonction canMove() verifiant si l'Ange peut se d�placer (ou si le Demon a gagn�)
 * et d'une fonction hasWon() qui v�rifie s'il a atteint le bord du plateau.
 */
class Ange : public Joueur {
	public:
		explicit Ange(Plateau& plateau, const std::string& nom = "Ange");
		virtual bool incorrect(const Position& pos) const;
		void modifierCase(const Position& pos);
		virtual bool canMove() const;
		Position getPosition() const;
		void setPosition(const Position& pos);
		bool hasWon() const;
	protected:
		static double dist(const Position& a, const Position& b);
	private:
		Position m_pos;
};
