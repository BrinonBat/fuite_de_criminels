#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <QtWidgets>

// Constantes pour la taille du TERRAIN et la taille HITBOX
#define TAILLE_TERRAIN 400 // (400x400)
#define TAILLE_HITBOX 4 // Correspond à un carré avec 4 en taille
						//           +2
						// 		   -----
						// 	   -2<-| x |-> +2
						// 		   -----
						// 			-2

//différents types d'objets non-joueurs
enum class Type {
	//Obstacle,
	cachette,
	sortie
};

//liste des différénts algorithmes disponible pour chaque joueurs
enum class Choix_Algo {
	random,
	haut,
	bas,
	gendarmes_chasseurs,
};

class Position {
public:

//constructeurs & destructeurs
	Position(double const & x, double const & y):
	x(x),y(y){};

//accesseurs
	double getX()const{return x;}
	double getY()const{return y;}
	void setX(double const & nouv){x=nouv;}
	void setY(double const & nouv){y=nouv;}

//operateurs
	Position operator+(Position const & pos); // redéfinition de l'addition pour les positions
	Position operator*(double mult); //redéfinition de la multiplication
	bool operator==(Position const & pos); //redéfinition de la comparaison

private:
	double x,y;
};

/// les classes Direction et Position sont identiques bien que les concepts soient différents
using Direction = Position;


class Hitbox {
public:

//constructeur
	Hitbox(double const & H,double const & B,double const & G,double const & D):
		haut(H),bas(B),gauche(G),droite(D){};

//accesseurs

	//getters
	double getH()const{return haut;}
	double getB()const{return bas;}
	double getG()const{return gauche;}
	double getD()const{return droite;}

	//setters
	void setH(double const & nouv){haut=nouv;}
	void setB(double const & nouv){bas=nouv;}
	void setG(double const & nouv){gauche=nouv;}
	void setD(double const & nouv){droite=nouv;}

private:
	double haut,bas,gauche,droite;
};

class Entite{
public:
//constructeur & destructeur
	Entite(Position const & pos);
	virtual ~Entite() =default;

//accesseurs

	//getters
	unsigned int getId()const{return id;}
	Position getPosition()const{return emplacement;}
	Hitbox getHitbox() const {return HB;}
	double getDistance_From (Entite E);
	QGraphicsRectItem* getItem()const{return item;}

	//setters
	void setPosition(Position nouv){emplacement=nouv;}
	void setHitbox();
	void setItem() {this->item->setPos(emplacement.getX(),emplacement.getY());}

//méthodes

	//affiche "(x,y)"
	std::string Affiche_Position() {return std::string()+"("+std::to_string(this->emplacement.getX())+","+std::to_string(this->emplacement.getY())+")";};

	//gestion de la hitbox
	std::string Affiche_Hitbox();
	bool Hitbox_touche(Entite &E);

private:
	Position emplacement;
	unsigned int id;
	static unsigned int compteur;
	Hitbox HB;
	QGraphicsRectItem * item;
};

class NonJoueur: public Entite{
public:
//constructeur
	NonJoueur(Position const & pos,Type const & t):
		Entite(pos),type(t){};

//accesseur
	Type getType()const{return type;}

private:
	Type type;
};

class Joueur: public Entite {
public:
//constructeur & destructeur
	Joueur(Position const & pos,double speed,std::string nom,Choix_Algo choix):
		Entite(pos),speed(speed),nom(nom),destination(pos),Algo(choix){
	};

	virtual ~Joueur() =default; ///< destructeur mis en virtuel pour que celui de Voleur et Gendarme soient utilisés

//accesseurs

	//getters
	double getSpeed()const{return speed;}
	std::string getNom()const{return nom;}
	Position getDestination()const{return destination;}
	Choix_Algo getAlgo()const{return Algo;}

	//setters
	void setDestination(Position const &pos){destination=pos;this->setPosition(destination);}

//méthode virtuelle
	void Deplacement();

//méthodes
	Direction Se_Rapprocher(Joueur const & J);
	Direction Fuir(Joueur const & J);

private:
	double speed;
	std::string nom;
	Position destination;
	Choix_Algo Algo;
};

class Gendarme; // Déclaration pour faire appel à la fonction Gendarme_Plus_Proche

class Voleur : public Joueur{
public:
//constructeurs
	Voleur(Position const & pos,double speed,std::string nom, Choix_Algo choix):
		Joueur(pos,speed,nom,choix){
		};

	///redefinition du constructeur virtuel
	Voleur* clone() const {return new Voleur(*this);}

//méthodes
	Gendarme Gendarme_Plus_Proche(std::vector<Gendarme*> Liste);
};

class Gendarme : public Joueur {
public:
//constructeurs
	Gendarme(Position const & pos,double speed,std::string nom,Choix_Algo choix):
		Joueur(pos,speed,nom,choix){
		};

	///redefinition du constructeur virtuel
	Gendarme* clone() const {return new Gendarme(*this);}

//méthodes
	Voleur Voleur_Plus_Proche(std::vector<Voleur*> Liste);
};
