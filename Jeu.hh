#pragma once
#include "Entites.hh"

class Jeu {

public :
//constructeurs et destructeurs
    Jeu(double plargeur, double phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
		fini=false;
		nbVoleurs=0;
		nbCaptures=0;
    }
    Jeu(Jeu const & JeuCopier){
        largeur=JeuCopier.getLargeur();
        hauteur=JeuCopier.getHauteur();
		fini=JeuCopier.estFini();
		nbVoleurs=JeuCopier.getNbVoleurs();
		nbCaptures=JeuCopier.getNbCaptures();
	}
//accesseurs
	Joueur const & getJoueur(std::size_t num)const{return *(Liste_Joueur.at(num));}
	void ajouter_joueur(Joueur const &J);
	void supprimer_voleur(Joueur &J);

	NonJoueur const & getObject(std::size_t num)const{return *(Liste_Objets.at(num));}
	void ajouter_nonJoueur(NonJoueur nJ); // à retravailler

	double getLargeur()const{return largeur;}
	double getHauteur()const{return hauteur;}

	unsigned int getNbCaptures()const{return nbCaptures;}
	void ajoutUneCapture(){nbCaptures++;}

	unsigned int getNbVoleurs()const{return nbVoleurs;}
	void ajoutUnVoleur(){nbVoleurs++;}

	bool estFini()const{return fini;}

//méthodes
	void Jouer_tour();
    void afficher();
    void initialise();
    void deplacement(Joueur & J, Direction const & d); // sera remplacé ?
    void verifieFin();//met à jour le bool fini à chaque capture/fuite de voleur

private:
	bool fini;
	unsigned int nbVoleurs,nbCaptures;
    double largeur,hauteur;
    std::vector<Joueur *> Liste_Joueur;
    std::vector<NonJoueur *> Liste_Objets;

};
