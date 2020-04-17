#pragma once
#include "Entites.hh"


class Jeu {

public :
//constructeurs et destructeurs
    Jeu(double plargeur, double phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
    }
    Jeu(Jeu const & JeuCopier){
        largeur=JeuCopier.getlargeur();
        hauteur=JeuCopier.getHauteur();
    }
//accesseurs
	Joueur const & getJoueur(std::size_t num)const{return *(Liste_Joueur.at(num));}
	NonJoueur const & getObject(std::size_t num)const{return *(Liste_Objets.at(num));}
	void ajouter_joueur(Joueur const &J);
	void ajouter_nonJoueur(NonJoueur nJ); // à retravailler
	double getLargeur()const{return largeur;}
	double getHauteur()const{return hauteur;}

//méthodes
    void afficher();
    void initialise();
    void deplacement(Joueur & J, Direction const & d);
    bool victoire(Joueur const & J);

private:
    double largeur,hauteur;
    std::vector<Joueur *> Liste_Joueur;
    std::vector<NonJoueur *> Liste_Objets;

};
