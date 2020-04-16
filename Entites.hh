#include <iostream>
#include <vector>
#include <iostream>
#include <string>

using Coordonnee = unsigned int ;

enum class Type {
	cachette,
	sortie
};

class Position {
public:
//constructeurs & destructeurs
	Position(double x, double y):
	x(x),y(y){};
//accesseurs
	double x,y; // mise en private et ajout d'accesseurs ?

	// plus simple si on redéfinit l'operaton "+" non ?

};

using Direction = Position;

class Entite{
public:
//constructeurs & destructeurs
	Entite(Position const & pos,int id):emplacement(pos),id(id){};

//accesseurs
	Position getPosition(){return emplacement;}
	void setPosition(Position nouv){emplacement=nouv;}
	int getId(){return id;}
	void setId(int nouv){id=nouv;}

//méthodes
	std::string Affiche_Position() {return std::string()+"("+std::to_string(this->emplacement.x)+","+std::to_string(this->emplacement.y)+")";};

private:
	Position emplacement;
	int id;
};

class NonJoueur: public Entite{
public:
	NonJoueur(Position const & pos, int id,Type const & t):
		Entite(pos,id),type(t){};

private:
	Type type;

};

class Joueur: public Entite {

public:
//constructeurs & destructeurs
	Joueur(Position const & pos,int id,double speed,std::string nom):
		Entite(pos,id),speed(0.3),nom(nom){};

	virtual Joueur* clone() const=0; /* contructeur virtuel
	permet l'ajout (et la recopie) de Voleur et Gendarme dans le vecteur du Jeu sans y copier de Joueur tout court*/

	virtual ~Joueur() =default; // destructeur retiré pour que celui de Voleur et Gendarme soient utilisés

//accesseurs

//méthodes
	// Ajout IA - Joue_Deplacement (Haut,Bas,Gauche,Droite)
	virtual Direction jouer() {return Direction(3.2,3.1);};

// private:
	double speed;
	std::string nom;

};


class Voleur : public Joueur{

public:
//constructeurs & destructeurs
	Voleur(Position const & pos,int id,double speed,std::string nom):
		Joueur(pos,id,speed,nom){};

	//redefinition du constructeur virtuel
	Joueur* clone() const override{
		return new Voleur(*this);
	}

//méthodes
	Direction jouer() override;

};

class Gendarme : public Joueur {

public:
//constructeurs & destructeurs
	Gendarme(Position const & pos,int id,double speed,std::string nom):
		Joueur(pos,id,speed,nom){};

	//redefinition du constructeur virtuel
	Joueur* clone() const override{
		return new Gendarme(*this);
	}

//méthodes
	Direction jouer() override;

};
