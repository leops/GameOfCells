#pragma once

#include "plateau.hpp"
#include "ange.hpp"
#include "demon.hpp"
#include <vector>
#include <memory>

/*! Plutot que de stocker les joueurs dans un tableau, ils sont stockés dans une paire
 * ce qui simplifie leur gestion, et utilisent des pointeurs automatiques pour eviter
 * d'avoir a utiliser un destructeur.
 */
typedef std::pair<std::shared_ptr<Ange>, std::shared_ptr<Demon>> Players;

/*! Gère une partie de jeu
 * En plus de la fonction tourDeJeu() au nom assez explicite et de quelque getters, cette classe
 * a une methode canPlay() qui permet de savoir si la partie est terminée (utilisée pour controler
 * la boucle de jeu)
 */
class Partie {
	public:
		explicit Partie(const size_t& dim, const std::string& nomA, const std::string& nomD, const char& type);
		void tourDeJeu();
		Plateau& getPlateau();
		bool canPlay();
		Players& getPlayers();
	private:
		Plateau m_plateau;
		Players m_joueurs;
};
