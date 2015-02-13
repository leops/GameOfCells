#include "joueur.hpp"
#include "partie.hpp"

using namespace std;

Joueur::Joueur(Partie* partie, const string& nom) : m_partie(partie), m_pseudo(nom) {
}

Position Joueur::saisir() const {
	size_t x, y;
	cout << "Entrez la position x: ";
	cin >> x;
	cout << "Entrez la position y: ";
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
	return m_partie->getPlateau();
}

/*ostream& operator<< (ostream& out, const Position& t) {
	out << "Pos(" << get<0>(t) << ", " << get<1>(t) << ")";
	return out;
}*/
