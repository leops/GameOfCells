#include "partie.hpp"
#include "ange.hpp"
#include "demon.hpp"

using namespace std;

Partie::Partie(const size_t & dim, const std::string & nomA, const std::string & nomD) : m_plateau(dim) {
	m_joueurs = make_pair(new Ange(this, nomA), new Demon(this, nomD));
}

void Partie::tourDeJeu() {
	system("cls");
	cout << m_plateau;

	m_joueurs.first->jouer();

	system("cls");
	cout << m_plateau;

	if (m_joueurs.first->hasWon()) {
		cout << "L'ange s'est echappe." << endl;
		return;
	}

	m_joueurs.second->jouer();
	system("cls");
	cout << m_plateau;

	if (!m_joueurs.first->canMove()) {
		cout << "Le démon a encercle l'Ange." << endl;
		return;
	}
}

Plateau & Partie::getPlateau() {
	return m_plateau;
}

bool Partie::canPlay() {
	return m_joueurs.first->canMove() && !m_joueurs.first->hasWon();
}
