#pragma once

#include "ange.hpp"

class AngePuissant : public Ange
{
	public:
		explicit AngePuissant(Partie* partie, const std::string& nom = "Ange");
		virtual bool incorrect(const Position& pos) const;
		virtual bool canMove() const;
	private:
		size_t m_force;
};

