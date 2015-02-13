#include "partie.hpp"

using namespace std;

int main() {
	string nomA, nomD;
	size_t dim;

	cout << "Bienvenue dans Game of Cells" << endl
		<< "Entrez le nom du joueur Ange: ";
	cin >> nomA;
	cout << "Entrez le nom du joueur Demon: ";
	cin >> nomD;
	cout << "Entrez la taille de la grille de jeu: ";
	cin >> dim;

	Partie partie(dim, nomA, nomD);
	do {
		partie.tourDeJeu();
	} while (partie.canPlay());

	system("pause");
	return 0;
}
