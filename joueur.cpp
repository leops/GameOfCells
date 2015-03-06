#include "joueur.hpp"

using namespace std;

//! Initilisation des variables membre
Joueur::Joueur(Plateau& plateau, const string& nom) : m_plateau(plateau), m_pseudo(nom) {
}

//! Demande au joueur d'entre une position
Position Joueur::saisir() const {
	size_t x, y;
	cout << "Entrez la position x: ";
	cin >> x;
	cout << "Entrez la position y: ";
	cin >> y;
	return Position(x, y);
}

//! Demande au joueur d'entre une case tant qu'elle est incorrecte
Position Joueur::choisirCase() const {
	Position pos;
	do {
		pos = saisir();
	} while (incorrect(pos));
	return pos;
}

//! Affiche le pseudo du joueur, puis joue une case après avoir demandé de l'entrer
void Joueur::jouer() {
	cout << "C'est au joueur " << m_pseudo << " de jouer." << endl;
	modifierCase(choisirCase());
}

//! Getter pour le plateau
Plateau & Joueur::getPlateau() const {
	return m_plateau;
}
