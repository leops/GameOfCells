#pragma once

#include "joueur.hpp"
#include "partie.hpp"

class Demon : public Joueur {
	public:
		explicit Demon(Partie* partie, const std::string& nom = "Demon");
		bool incorrect(const Position& pos) const;
		void modifierCase(const Position& pos);
};
