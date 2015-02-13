#pragma once

#include "plateau.hpp"
#include "joueur.hpp"
#include <vector>

class Ange;
class Demon;

class Partie {
	public:
		explicit Partie(const size_t& dim, const std::string& nomA, const std::string& nomD);
		void tourDeJeu();
		Plateau& getPlateau();
		bool canPlay();
	private:
		Plateau m_plateau;
		std::pair<Ange*, Demon*> m_joueurs;
};
