#pragma once
#include "Entites.hh"

class Jeu {

public :
//constructeurs et destructeurs
    Jeu(double plargeur, double phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
		nbVoleurs=0;
		nbCaptures=0;
    }
/*
    Jeu(Jeu const & JeuCopier){
        largeur=JeuCopier.getLargeur();
        hauteur=JeuCopier.getHauteur();
		nbVoleurs=JeuCopier.getNbVoleurs();
		nbCaptures=JeuCopier.getNbCaptures();
	}
*/
//accesseurs
	Voleur const getVoleur(std::size_t num)const{return Liste_Voleurs.at(num);}
	void ajouter_voleur(Voleur V);
	void supprimer_voleur(Voleur &V);

	Gendarme const getGendarme(std::size_t num)const{return Liste_Gendarmes.at(num);}
	void ajouter_gendarme(Gendarme G);

	NonJoueur const getObject(std::size_t num)const{return Liste_Objets.at(num);}
	void ajouter_nonJoueur(NonJoueur nJ); // à retravailler

	double getLargeur()const{return largeur;}
	double getHauteur()const{return hauteur;}

	unsigned int getNbCaptures()const{return nbCaptures;}
	void ajoutUneCapture(){nbCaptures++;}

	unsigned int getNbVoleurs()const{return nbVoleurs;}
	void ajoutUnVoleur(){nbVoleurs++;}

	std::vector<Voleur>* const getListeVoleurs(){return &(Liste_Voleurs);}
	std::vector<Gendarme>* const getListeGendarmes(){return &(Liste_Gendarmes);}
	std::vector<NonJoueur>* const getListeNonJoueurs(){return &(Liste_Objets);}

//méthodes
	void Jouer_tour();
    void afficher();
    void initialise();
    void Joue_deplacement(Voleur &V);
	void Joue_deplacement(Gendarme &G);
    bool estFini();

private:
	unsigned int nbVoleurs,nbCaptures;
    double largeur,hauteur;
    std::vector<Voleur> Liste_Voleurs;
	std::vector<Gendarme> Liste_Gendarmes;
    std::vector<NonJoueur> Liste_Objets;

};
