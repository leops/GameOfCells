#pragma once

#include "joueur.hpp"
#include "partie.hpp"
#include <cmath>
#include <algorithm>

class Ange : public Joueur {
	public:
		explicit Ange(Partie* partie, const std::string& nom = "Ange");
		virtual bool incorrect(const Position& pos) const;
		virtual void modifierCase(const Position& pos);
		virtual bool canMove() const;
		Position getPosition() const;
		bool hasWon() const;
	protected:
		static double dist(const Position& a, const Position& b);
	private:
		Position m_pos;
};
