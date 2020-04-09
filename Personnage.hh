#pragma once
#include <string>
#include "Position.hh"
#include "Jeu.hh"

enum class Cardinal{
	Nord,
	Sud,
	Est,
	Ouest
};

class Personnage{
	public:
		//Constructeur & destructeur
		Personnage(std::string const & nom, Position const & pos,Cardinal dir):
			nom(nom),position(pos),direction(dir){};
		virtual ~Personnage()=default;
//		virtual Personnage* clone() const=0;

		//accesseurs
		/* à faire
		getNom
		setNom
		getDirection
		setDirection
		getPosition
		*/

		//méthodes
		virtual int prevoir_coup(Jeu const & game) const;

	private:
		std::string nom;
		Position position;
		Cardinal direction;
};

class Voleur:public Personnage{
	public:
		int prevoir_coup(Jeu const & game) const override;
//		Personnage clone() const override{return new Voleur(*this);}
};

class Gendarme:public Personnage{
	public:
		int prevoir_coup(Jeu const & game) const override;
//		Personnage clone() const override{return new Gendarme(*this);}
};
