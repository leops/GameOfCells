#include "partie.hpp"

using namespace std;

// Permet d'eviter d'integrer la fonction main lorsque le projet est compilé en mode bibliothèque
#ifndef _LIB
int main() {
	string nomA, nomD;
	size_t dim;

	// Demande quelques informations au joueur
	cout << "Bienvenue dans Game of Cells" << endl
		<< "Entrez le nom du joueur Ange: ";
	cin >> nomA;
	cout << "Entrez le nom du joueur Demon: ";
	cin >> nomD;
	cout << "Entrez la taille de la grille de jeu: ";
	cin >> dim;

	char type;
	cout << "Quel type d'ange voulez vous jouer, (N)ormal ou (P)uissant: ";
	cin >> type;

	// Initiliase la partie avec les entrées des joueurs
	Partie partie(dim, nomA, nomD, type);
	do {  // Boucle de jeu
		partie.tourDeJeu();
	} while (partie.canPlay());

	system("pause");  // Bloque l'execution du programme avec de fermer
	return 0;
}
#endif
