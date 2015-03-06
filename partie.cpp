#include "partie.hpp"
#include "ange.hpp"
#include "demon.hpp"
#include "angePuissant.hpp"

using namespace std;

//! Initialise les joueurs avec la methode make_shared permettant de construire un pointeur automatique
Partie::Partie(const size_t & dim, const std::string & nomA, const std::string & nomD, const char& type) : m_plateau(dim) {
	shared_ptr<Ange> ange;

	if (type == 'P' || type == 'p')
		ange = make_shared<AngePuissant>(m_plateau, nomA);
	else
		ange = make_shared<Ange>(m_plateau, nomA);

	m_joueurs = make_pair(ange, make_shared<Demon>(m_plateau, nomD));
}

//! Deroulement d'un tour de jeu
void Partie::tourDeJeu() {
	// Affiche le plateau
	system("cls");
	cout << m_plateau;

	// Tour de l'ange
	m_joueurs.first->jouer();

	// Affiche le plateau
	system("cls");
	cout << m_plateau;

	// Quitte si l'ange a gagné
	if (m_joueurs.first->hasWon()) {
		cout << "L'ange s'est echappe." << endl;
		return;
	}

	// Demande au démon s'il veut agrandir le plateau
	char grow;
	cout << "Voulez vous agrandir le plateau, (O)ui ou (N)on:";
	cin >> grow;

	if (grow == 'O') {
		++m_plateau;
		system("cls");
		cout << m_plateau;
	}

	// Tour du démon
	m_joueurs.second->jouer();

	// Affiche (encore) le plateau
	system("cls");
	cout << m_plateau;

	// Vérifie si le démon a gagné
	if (!m_joueurs.first->canMove()) {
		cout << "Le demon a encercle l'Ange." << endl;
		return;
	}
}

//! Getter pour m_plateau
Plateau & Partie::getPlateau() {
	return m_plateau;
}

//! Getter pour m_joueurs
Players & Partie::getPlayers() {
	return m_joueurs;
}

//! Si la partie continue (l'ange peut bouger et n'a pas atteint le bord)
bool Partie::canPlay() {
	return m_joueurs.first->canMove() && !m_joueurs.first->hasWon();
}
