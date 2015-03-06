#pragma once

#include "ange.hpp"

/*! Ange capable de se d�placer de plusieurs cases en un tour
 * Cette classe a le m�me comporetement que la classe Ange, elle ne remplace que les fonctions incorrect()
 * et canMove() pour refleter la possibilit� de se d�placer sur une plus grande distance.
 * La "puissance" de l'ange est stock�e dans la variable m_force.
 */
class AngePuissant : public Ange
{
	public:
		explicit AngePuissant(Plateau& plateau, const std::string& nom = "Ange");
		virtual bool incorrect(const Position& pos) const;
		virtual bool canMove() const;
	private:
		size_t m_force;
};

