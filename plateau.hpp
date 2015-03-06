#pragma once

#include <ostream>
#include <map>

// Pour ce genre de classe ne contenant que des donn�es, il y a std::tuple
typedef std::tuple<bool, bool> Case; // <broken, free>
typedef std::tuple<size_t, size_t> Position; // <x, y>

/*! Classe de gestion du plateau
 * En plus de quelques getters / setters, cette classe dispose d'un operator<< utilis� pour
 * �crire une representation du plateau dans un std::ostream (ici dans cout, mais pourrait
 * �tre utilis� pour ecrire dans un fichier par exemple), d'un operator++ pour agrandir le
 * plateau, et d'une methode removeCase() permettant de supprimer une case (= la remettre
 * a sa valeur par d�faut).
 */
class Plateau {
	public:
		explicit Plateau(size_t dim = 35);
		friend std::ostream& operator<< (std::ostream& out, Plateau& plateau);
		Case getCase(const Position& pos) const;
		void setCase(const Position& pos, const Case& cell);
		void removeCase(const Position & pos);
		size_t getDim() const;
		Plateau& operator++(void);
	private:
		/*! Plutot que s'embeter avec une tableau en 2D � taille dynamique, ce qui est lourd a utiliser
		 * et pas du tout efficace au niveau de l'usage de m�moire, j'ai utilis� une std::map.
		 * Cette methode a plusieurs avantages: d'une part, cete methode consomme beaucoup moins de m�moire
		 * puisque seul les cases n'�tant pas dans l'�tat par d�faut sont sauvegard�es. Ensuite, cela
		 * simplifie enormement la classe puisque la forme canonique de Coplien est inutile
		 * (la classe map a un constructeur de copie, un destructeur et un operator= qui executent
		 * toutes les op�rations n�c�ssaires), mais aussi parce ce fonctionnement r�duit le risque
		 * d'erreurs li�es aux pointeurs et au tableaux (il est m�me possible d'editer une case
		 * hors des limites du plateau sans erreur). Enfin, cela simplifie beaucoup l'operation
		 * de redimensionnement (modifier la variable m_dim suffit pour agrandir le plateau,
		 * cependant l'operateur++ effectue aussi un d�calage de toutes les cl�s)
		 */
		std::map<Position, Case> m_gameboard;
		size_t m_dim;
};
