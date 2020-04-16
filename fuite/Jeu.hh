#include <iostream>
#include <vector>
#include <iostream>
#include <string>


using coordonnee = unsigned int ;

enum class type {
	nobody,
	voleur,
	gendarme,
	cachette,
	sortie
};

class Position {
public:
	Position(double x, double y):
	x(x),y(y){};
	double x,y;
};

using Direction = Position;

class Joueur {

public:
	Joueur(std::string nom,type const & e,Position const & pos,int id,double speed):
	nom(nom),t(e),pos(pos),id(id),speed(0.3){};
	std::string Affiche_Position() {return std::string()+"("+std::to_string(this->pos.x)+","+std::to_string(this->pos.y)+")";};

	// Ajout IA - Joue_Deplacement (Haut,Bas,Gauche,Droite)
	virtual Direction jouer() {return Direction(3.2,3.1);};

// private:
	std::string nom;
	type t;
	Position pos;
	int id;
	double speed;

};


class Voleur : public Joueur {

public :
Voleur(std::string nom,type const & e,Position const & pos,int id,double speed):
Joueur(nom,e,pos,id,speed){};
Direction jouer() override;

};

class Gendarme : public Joueur {

public :
Gendarme(std::string nom,type const & e,Position const & pos,int id,double speed):
Joueur(nom,e,pos,id,speed){};
Direction jouer() override;

};



class Grille {

public :
    Grille(coordonnee plargeur, coordonnee phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
    }
    Grille(Grille const & GrilleCopier){
        largeur=GrilleCopier.largeur;
        hauteur=GrilleCopier.hauteur;
    }

    void afficher();
    void initialise();
    void ajouter_joueur(Joueur &J);
    void ajouter_sortie(Position P);
    void deplacement(Joueur & J, Direction d);
    bool victoire(Joueur J);


    coordonnee largeur,hauteur;
    std::vector<Joueur> Liste_Joueur;
    std::vector<Position> Liste_Sortie;

};
