#pragma once

#include "joueur.hpp"

class Demon : public Joueur {
	public:
		Demon(Plateau& plateau, const std::string& nom = "Demon");
		bool incorrect(const Position& pos) const;
		void modifierCase(const Position& pos);
};
