#pragma once

#include "joueur.hpp"
#include <cmath>

class Ange : public Joueur {
	public:
		Ange(Plateau& plateau, const std::string& nom = "Ange");
		bool incorrect(const Position& pos) const;
		void modifierCase(const Position& pos);
	private:
		Position m_pos;
};
