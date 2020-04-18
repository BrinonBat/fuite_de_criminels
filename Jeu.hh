#pragma once
#include "Entites.hh"


class Jeu {

public :
//constructeurs et destructeurs
    Jeu(double plargeur, double phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
		fini=false;
    }
    Jeu(Jeu const & JeuCopier){
        largeur=JeuCopier.getLargeur();
        hauteur=JeuCopier.getHauteur();
		fini=JeuCopier.estFini();
	}
//accesseurs
	Joueur const & getJoueur(std::size_t num)const{return *(Liste_Joueur.at(num));}
	NonJoueur const & getObject(std::size_t num)const{return *(Liste_Objets.at(num));}
	void ajouter_joueur(Joueur const &J);
	void supprimer_voleur(int id);
	void ajouter_nonJoueur(NonJoueur nJ); // à retravailler
	double getLargeur()const{return largeur;}
	double getHauteur()const{return hauteur;}
	bool estFini()const{return fini;}

//méthodes
    void afficher();
    void initialise();
    void deplacement(Joueur & J, Direction const & d);
    void verifieFin();//met à jour le bool fini à chaque capture/fuite de voleur

private:
	bool fini;
    double largeur,hauteur;
    std::vector<Joueur *> Liste_Joueur;
    std::vector<NonJoueur *> Liste_Objets;

};
