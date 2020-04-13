#include <iostream>
#include <vector>
#include <iostream>
#include <string>


using coordonnee = unsigned int ;

enum class Direction {
	Haut,
	Bas,
	Gauche,
	Droite,
	//mouvements en diagonale possibles ?
	Haut_Gauche,
	Haut_Droite,
	Bas_Gauche,
	Bas_Droite
};

enum class type { // ou enum type tout seul pour conserver les indices ?
	nobody,
	voleur,
	gendarme,
	cachette,
	sortie
};

class Position {
public:
	Position(int x, int y):
	x(x),y(y){};
	int x,y;
};

class Joueur {

public:
	Joueur(std::string nom,type const & e,Position const & pos,int id):
	nom(nom),t(e),pos(pos),id(id){};
	std::string Affiche_Position() {return std::string()+"("+std::to_string(this->pos.x)+","+std::to_string(this->pos.y)+")";};

	// Ajout IA - Joue_Deplacement (Haut,Bas,Gauche,Droite)
	virtual Direction jouer() {return Direction::Bas;};

// private:
	std::string nom;
	type t;
	Position pos;
	int id;

};


class Voleur : public Joueur {

public :
	Voleur(std::string nom,type const & e,Position const & pos,int id):
		Joueur(nom,e,pos,id){};
	Direction jouer() override;

};

class Gendarme : public Joueur {

public :
	Gendarme(std::string nom,type const & e,Position const & pos,int id):
		Joueur(nom,e,pos,id){};
	Direction jouer() override;

};



class Grille {

public :
    Grille(coordonnee plargeur, coordonnee phauteur) {
		Tab.resize(plargeur,std::vector<type>(phauteur));
		largeur=plargeur;
		hauteur=phauteur;
    }
    Grille(Grille const & GrilleCopier){
        Tab=GrilleCopier.Tab;
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
    std::vector<std::vector<type>> Tab;
    std::vector<Joueur> Liste_Joueur;
    std::vector<Position> Liste_Sortie;

};
