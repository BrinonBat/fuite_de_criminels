#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <QtWidgets>

using Coordonnee = unsigned int ;

//différents types d'objets non-joueurs
enum class Type {
	cachette,
	sortie
};

//Correspond à la liste des différénts algorithmes disponible pour chaque joueurs
enum class Choix_Algo {
	random,
	haut,
	bas,
	Gendarme_Chasseurs,
};

class Position {
public:
//constructeurs & destructeurs
	Position(double const & x, double const & y):
	x(x),y(y){};

//accesseurs
	double getX()const{return x;}
	void setX(double const & nouv){x=nouv;}
	double getY()const{return y;}
	void setY(double const & nouv){y=nouv;}

//operateurs
	Position operator+(Position const & d); // redéfinition de l'addition pour les positions
	Position operator*(double mult);
	bool operator==(Position const & d); //redéfinition de la comparaison

private:
	double x,y;
};
using Direction = Position;


class Hitbox {
public:
	Hitbox(double const & H,double const & B,double const & G,double const & D):
		Haut(H),Bas(B),Gauche(G),Droite(D){};

	double getH()const{return Haut;}
	double getB()const{return Bas;}
	double getG()const{return Gauche;}
	double getD()const{return Droite;}

	void setH(double const & nouv){Haut=nouv;}
	void setB(double const & nouv){Bas=nouv;}
	void setG(double const & nouv){Gauche=nouv;}
	void setD(double const & nouv){Droite=nouv;}


private:
	double Haut,Bas,Gauche,Droite;
};

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
	Hitbox getHitbox() const {return HB;}
	void setHitbox() {HB.setH(getPosition().getY()+2);HB.setB(getPosition().getY()-2);HB.setG(getPosition().getX()-2);HB.setD(getPosition().getX()+2);}
	std::string Affiche_Hitbox() {return std::string()+"Hitbox:("+std::to_string(this->HB.getG())+","+std::to_string(this->HB.getD())+","+std::to_string(this->HB.getH())+","+std::to_string(this->HB.getB())+")";}
	bool Hitbox_touche(Entite &E);

	QGraphicsRectItem* getItem()const{return item;}
	void setItem(Position const &pos) {this->item->setPos(pos.getX(),pos.getY());}

	// Distance entre deux entités
	double getDistance_From (Entite E);

private:
	Position emplacement;
	unsigned int id;
	static unsigned int compteur;
	Hitbox HB;
	QGraphicsRectItem * item;
};

class NonJoueur: public Entite{
public:
//constructeurs & destructeurs
	NonJoueur(Position const & pos,Type const & t):
		Entite(pos),type(t){};

//accesseurs
	Type getType()const{return type;}


//méthodes

private:
	Type type;


};

class Joueur: public Entite {

public:
//constructeurs & destructeurs
	Joueur(Position const & pos,double speed,std::string nom,Choix_Algo choix):
		Entite(pos),speed(speed),nom(nom),destination(pos),Algo(choix){
	};

	virtual ~Joueur() =default; // destructeur retiré pour que celui de Voleur et Gendarme soient utilisés

//accesseurs
	// Passage des valeurs de speed en constantes globales???(valeurs égales pour tout la classe)
	double getSpeed()const{return speed;}
	std::string getNom()const{return nom;}
	Position getDestination()const{return destination;}
	void setDestination(Position const &pos){destination=pos;this->setPosition(destination);}

	//Setter/Getter pour le choix de l'algo
	Choix_Algo getAlgo()const{return Algo;}
	void setAlgo(Choix_Algo const choix) {Algo=choix;}

//méthodes virtuel
	virtual void deplacement() =0;

//méthodes
	Direction Se_Rapprocher(Joueur & J);
	Direction Fuir (Joueur & J);

private:
	double speed;
	std::string nom;
	Position destination;
	Choix_Algo Algo;

};

class Gendarme; // Pour faire appel à la fonction Gendarme_Plus_Proche

class Voleur : public Joueur{

public:
//constructeurs & destructeurs
	Voleur(Position const & pos,double speed,std::string nom, Choix_Algo choix):
		Joueur(pos,speed,nom,choix){
		};

//méthodes
	void deplacement() override;

	Gendarme Gendarme_Plus_Proche(std::vector<Gendarme>const & Liste);

};

class Gendarme : public Joueur {

public:
//constructeurs & destructeurs
	Gendarme(Position const & pos,double speed,std::string nom,Choix_Algo choix):
		Joueur(pos,speed,nom,choix){
		};


//méthodes
	void deplacement() override;

	Voleur Voleur_Plus_Proche(std::vector<Voleur>const & Liste);

};
