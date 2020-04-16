#include <iostream>
#include <vector>
#include <iostream>
#include <string>

using coordonnee = unsigned int ;

enum class type {
	cachette,
	sortie
};

class Position {
public:
//constructeurs & destructeurs
	Position(double x, double y):
	x(x),y(y){};
//accesseurs
	double x,y;
	
};

using Direction = Position;

class Entite{
public:
//constructeurs & destructeurs
	Entite(Position const & pos):emplacement(pos){};

//accesseurs
	Position getPosition(){return emplacement;}
	void setPosition(Position nouv){emplacement=nouv;}

//méthodes
	std::string Affiche_Position() {return std::string()+"("+std::to_string(this->emplacement.x)+","+std::to_string(this->emplacement.y)+")";};

private:
	Position emplacement;
};
/*
class NonJoueur{
public:


}
*/
class Joueur: public Entite {

public:
//constructeurs & destructeurs
	Joueur(Position const & pos,std::string nom,int id,double speed):
		Entite(pos),nom(nom),id(id),speed(0.3){};

	virtual Joueur* clone() const=0; /* contructeur virtuel
	permet l'ajout (et la recopie) de Voleur et Gendarme dans le vecteur du Jeu sans y copier de Joueur tout court*/

	virtual ~Joueur() =default; // destructeur retiré pour que celui de Voleur et Gendarme soient utilisés

//accesseurs

//méthodes
	// Ajout IA - Joue_Deplacement (Haut,Bas,Gauche,Droite)
	virtual Direction jouer() {return Direction(3.2,3.1);};

// private:
	std::string nom;
	int id;
	double speed;

};


class Voleur : public Joueur {

public :
//constructeurs & destructeurs
	Voleur(Position const & pos,std::string nom,int id,double speed):
		Joueur(pos,nom,id,speed){};

	//redefinition du constructeur virtuel
	Joueur* clone() const override{
		return new Voleur(*this);
	}

//méthodes
	Direction jouer() override;

};

class Gendarme : public Joueur {

public :
//constructeurs & destructeurs
	Gendarme(Position const & pos,std::string nom,int id,double speed):
		Joueur(pos,nom,id,speed){};

	//redefinition du constructeur virtuel
	Joueur* clone() const override{
		return new Gendarme(*this);
	}

//méthodes
	Direction jouer() override;

};
