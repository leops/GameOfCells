#pragma once

#include "plateau.hpp"
#include "ange.hpp"
#include "demon.hpp"
#include <vector>
#include <memory>

class Partie {
	public:
		explicit Partie(const size_t& dim, const std::string& nomA, const std::string& nomD);
		void tourDeJeu();
		Plateau& getPlateau();
		bool canPlay();
	private:
		Plateau m_plateau;
		std::pair<std::shared_ptr<Ange>, std::shared_ptr<Demon>> m_joueurs; // Des pointeurs ? En C++ ? hahahaha ! HAHAHAHAHA !
};
