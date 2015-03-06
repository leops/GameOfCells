#pragma once

#include <ostream>
#include <map>

// Pour ce genre de classe ne contenant que des données, il y a std::tuple
typedef std::tuple<bool, bool> Case; // <broken, free>
typedef std::tuple<size_t, size_t> Position; // <x, y>

/*! Classe de gestion du plateau
 * En plus de quelques getters / setters, cette classe dispose d'un operator<< utilisé pour
 * écrire une representation du plateau dans un std::ostream (ici dans cout, mais pourrait
 * être utilisé pour ecrire dans un fichier par exemple), d'un operator++ pour agrandir le
 * plateau, et d'une methode removeCase() permettant de supprimer une case (= la remettre
 * a sa valeur par défaut).
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
		/*! Plutot que s'embeter avec une tableau en 2D à taille dynamique, ce qui est lourd a utiliser
		 * et pas du tout efficace au niveau de l'usage de mémoire, j'ai utilisé une std::map.
		 * Cette methode a plusieurs avantages: d'une part, cete methode consomme beaucoup moins de mémoire
		 * puisque seul les cases n'étant pas dans l'état par défaut sont sauvegardées. Ensuite, cela
		 * simplifie enormement la classe puisque la forme canonique de Coplien est inutile
		 * (la classe map a un constructeur de copie, un destructeur et un operator= qui executent
		 * toutes les opérations nécéssaires), mais aussi parce ce fonctionnement réduit le risque
		 * d'erreurs liées aux pointeurs et au tableaux (il est même possible d'editer une case
		 * hors des limites du plateau sans erreur). Enfin, cela simplifie beaucoup l'operation
		 * de redimensionnement (modifier la variable m_dim suffit pour agrandir le plateau,
		 * cependant l'operateur++ effectue aussi un décalage de toutes les clés)
		 */
		std::map<Position, Case> m_gameboard;
		size_t m_dim;
};
