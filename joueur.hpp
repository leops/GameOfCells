#pragma once

#include <string>

class Joueur {
	public:
		explicit Joueur(const std::string& nom = "Joueur");
	private:
		std::string m_pseudo;
};

