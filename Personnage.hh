#pragma once
#include <string>

enum class Cardinal{
	Nord,
	Sud,
	Est,
	Ouest
};

struct Coordonnee{
	int x,y;
}

class Personnage{
	public:
		//Constructeur
		Personnage(std::string const & nom, Coordonnee const & pos,Cardinal const & dir):
			nom(nom),position(pos),direction(dir){}

		//accesseurs
		/* à faire */

		//méthodes
		virtual int prevoir_coup(Jeu const & game) const;

	private:
		std::string nom;
		Coordonnee position;
		Cardinal direction;
};

class Voleur:public Personnage{
	public:
		int prevoir_coup(Jeu const & game) const override;
}

class Gendarme:public Personnage{
	public:
		int prevoir_coup(Jeu const & game) const override;
}
