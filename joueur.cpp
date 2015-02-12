#include "joueur.hpp"

using namespace std;

Joueur::Joueur(Plateau& plateau, const string& nom) : m_plateau(plateau), m_pseudo(nom) {
}

Position Joueur::saisir() const {
	size_t x, y;
	cout << "Entrez la position x:" << endl;
	cin >> x;
	cout << "Entrez la position y:" << endl;
	cin >> y;
	return Position(x, y);
}

Position Joueur::choisirCase() const {
	Position pos;
	do {
		pos = saisir();
	} while (incorrect(pos));
	return pos;
}

void Joueur::jouer() {
	cout << "C'est au joueur " << m_pseudo << " de jouer." << endl;
	modifierCase(choisirCase());
}

Plateau & Joueur::getPlateau() const {
	return m_plateau;
}
