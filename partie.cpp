#include "partie.hpp"
#include "ange.hpp"
#include "demon.hpp"
#include "angePuissant.hpp"

using namespace std;

Partie::Partie(const size_t & dim, const std::string & nomA, const std::string & nomD) : m_plateau(dim) {
	shared_ptr<Ange> ange;
	char type;
	cout << "Quel type d'ange voulez vous jouer, (N)ormal ou (P)uissant: ";
	cin >> type;

	if (type == 'P' || type == 'p')
		ange = make_shared<AngePuissant>(this, nomA);
	else
		ange = make_shared<Ange>(this, nomA);

	m_joueurs = make_pair(ange, make_shared<Demon>(this, nomD));
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
