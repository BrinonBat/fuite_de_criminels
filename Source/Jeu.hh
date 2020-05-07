#pragma once
#include "Entites.hh"

class Jeu {

public :
//constructeurs et destructeurs
    Jeu(double plargeur, double phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
		nbVoleurs=0;
		nbGendarmes=0;
		nbCaptures=0;
    }
    Jeu(Jeu const & JeuCopier){
        largeur=JeuCopier.getLargeur();
        hauteur=JeuCopier.getHauteur();
		nbVoleurs=JeuCopier.getNbVoleurs();
		nbCaptures=JeuCopier.getNbCaptures();
	}
//accesseurs
	Voleur const & getVoleur(std::size_t num)const{return *(Liste_Voleurs.at(num));}
	void ajouter_voleur(Voleur const &V);
	void supprimer_voleur(Voleur  &V);

	Gendarme const & getGendarme(std::size_t num)const{return *(Liste_Gendarmes.at(num));}
	void ajouter_gendarme(Gendarme const &G);

	NonJoueur const & getObject(std::size_t num)const{return *(Liste_Objets.at(num));}
	void ajouter_nonJoueur(NonJoueur const nJ); // à retravailler

	double getLargeur()const{return largeur;}
	double getHauteur()const{return hauteur;}

	unsigned int getNbCaptures()const{return nbCaptures;}
	void ajoutUneCapture(){nbCaptures++;}

	unsigned int getNbVoleurs()const{return nbVoleurs;}
	void ajoutUnVoleur(){nbVoleurs++;}

	unsigned int getNbGendarmes()const{return nbGendarmes;}
	void ajoutUnGendarme(){nbGendarmes++;}

	unsigned int getNbVoleursSorties()const{return nbVoleurs-(nbCaptures+Liste_Voleurs.size());}

	std::vector<Voleur *> getListeVoleur()const {return Liste_Voleurs;}
	std::vector<Gendarme *> getListeGendarme()const {return Liste_Gendarmes;}
	std::vector<NonJoueur *> getListeNonJoueur()const {return Liste_Objets;}

//méthodes
	void Jouer_tour();
    void afficher();
    void initialise();
    void calcule_deplacement(Voleur &V);
	void calcule_deplacement(Gendarme &G);
	bool Coup_Possible(Joueur & J, Direction coup);
    bool estFini();

private:
	unsigned int nbVoleurs,nbGendarmes,nbCaptures;
    double largeur,hauteur;
    std::vector<Voleur *> Liste_Voleurs;
	std::vector<Gendarme *> Liste_Gendarmes;
    std::vector<NonJoueur *> Liste_Objets;

};

double fRand(double fMin, double fMax);
