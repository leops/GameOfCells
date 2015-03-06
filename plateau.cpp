#include "plateau.hpp"

using namespace std;

//! Agrandit le plateau d'une case si la dimension entrée est paire
Plateau::Plateau(size_t dim) : m_dim(dim) {
	if (m_dim % 2 == 0)
		m_dim++;
}

//! Si la case demandée est définie, retourne sa valeur, sinon retourne la valeur par défaut
Case Plateau::getCase(const Position& pos) const {
	if (m_gameboard.count(pos) > 0) {
		return m_gameboard.at(pos);
	} else {
		return Case(false, true);
	}
}

//! Si la case demandé existe, remplace sa valeur, sinon crée la valeur dans la map
void Plateau::setCase(const Position & pos, const Case & cell) {
	auto it = m_gameboard.find(pos);
	if (it != m_gameboard.end())
		it->second = cell;
	else
		m_gameboard.emplace(pos, cell);
}

//! Supprime une case
void Plateau::removeCase(const Position & pos) {
	m_gameboard.erase(pos);
}

//! Getter pour m_dim
size_t Plateau::getDim() const {
	return m_dim;
}

//! Agrandit le tableau de 2 lignes et 2 colonnes
Plateau & Plateau::operator++(void) {
	m_dim += 2;
	// Crée une copie temporaire de la map
	map<Position, Case> temp(m_gameboard);
	// Efface le gamebord courant
	m_gameboard.clear();
	// Lit les valeurs du plateau temporaire et les copie dans le gameboard courant en décalant les clés d'une case
	for (auto i : temp) {
		auto pos = i.first;
		m_gameboard.emplace(Position(get<0>(pos) + 1, get<1>(pos) + 1), i.second);
	}
	return *this;
}

//! Affiche le plateau dans un flux
std::ostream& operator<< (std::ostream& out, Plateau& plateau) {
	for (size_t x = 0; x < plateau.m_dim; x++) {
		for (size_t y = 0; y < plateau.m_dim; y++) {
			auto point = plateau.getCase(Position(x, y));  // Recupere chaque case
			if (!get<1>(point)) {  // Si elle n'est pas libre (contient un ange)
				out << 'O';
			} else if (get<0>(point)) {  // Si elle est detruite
				out << 'X';
			} else {
				out << '.';
			}
			out << ' ';
		}
		out << endl;
	}
	return out;
}
