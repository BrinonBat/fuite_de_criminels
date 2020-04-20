#pragma once
#include <iostream>
#include <vector>
#include <string>

using Coordonnee = unsigned int ;

enum class Type {
	cachette,
	sortie
};

class Position {
public:
//constructeurs & destructeurs
	Position(double const & x, double const & y):
	x(x),y(y){};

//accesseurs
	double getX()const{return x;}
	void setX(int const & nouv){x=nouv;}
	double getY()const{return y;}
	void setY(int const & nouv){y=nouv;}

Position operator+(Position const & d); // redéfinition de l'addition pour les positions

private:
	double x,y;

	// plus simple si on redéfinit l'operaton "+" non ?

};
using Direction = Position;
//Position Position::operator+(Direction const & d); // redéfinition de l'addition pour les positions

class Entite{
public:
//constructeurs & destructeurs
	Entite(Position const & pos);

//accesseurs
	Position getPosition()const{return emplacement;}
	void setPosition(Position nouv){emplacement=nouv;}
	unsigned int getId()const{return id;}

//méthodes
	std::string Affiche_Position() {return std::string()+"("+std::to_string(this->emplacement.getX())+","+std::to_string(this->emplacement.getY())+")";};

private:
	Position emplacement;
	unsigned int id;
	static unsigned int compteur;
};

class NonJoueur: public Entite{
public:
//constructeurs & destructeurs
	NonJoueur(Position const & pos,Type const & t):
		Entite(pos),type(t){};

//accesseurs
	Type getType()const{return type;}

private:
	Type type;

};

class Joueur: public Entite {

public:
//constructeurs & destructeurs
	Joueur(Position const & pos,double speed,std::string nom):
		Entite(pos),speed(0.3),nom(nom){};

	virtual Joueur* clone() const=0; /* contructeur virtuel
	permet l'ajout (et la recopie) de Voleur et Gendarme dans le vecteur du Jeu sans y copier de Joueur tout court*/

	virtual ~Joueur() =default; // destructeur retiré pour que celui de Voleur et Gendarme soient utilisés

//accesseurs
	// Passage des valeurs de speed en constantes globales???(valeurs égales pour tout la classe)
	double getSpeed()const{return speed;}
	std::string getNom()const{return nom;}
//méthodes

	bool estVoleur() const{return false;}
	// Ajout IA - Joue_Deplacement (Haut,Bas,Gauche,Droite)
	virtual Direction jouer() {return Direction(3.2,3.1);};

private:
	double speed;
	std::string nom;

};


class Voleur : public Joueur{

public:
//constructeurs & destructeurs
	Voleur(Position const & pos,double speed,std::string nom):
		Joueur(pos,speed,nom){};

	//redefinition du constructeur virtuel
	Joueur* clone() const override{
		return new Voleur(*this);
	}

//méthodes
	bool estVoleur() const{return true;}
	Direction jouer() override;

};

class Gendarme : public Joueur {

public:
//constructeurs & destructeurs
	Gendarme(Position const & pos,double speed,std::string nom):
		Joueur(pos,speed,nom){};

	//redefinition du constructeur virtuel
	Joueur* clone() const override{
		return new Gendarme(*this);
	}

//méthodes
	Direction jouer() override;

};
