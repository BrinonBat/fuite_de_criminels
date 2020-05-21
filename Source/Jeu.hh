#pragma once
#include "Entites.hh"

class Jeu {
public:

//constructeurs
    Jeu() {
		largeur=TAILLE_TERRAIN;
		hauteur=TAILLE_TERRAIN;
		nbVoleurs=0;
		nbCaptures=0;
    }

    Jeu(Jeu const & jeuCopier){
        largeur=jeuCopier.getLargeur();
        hauteur=jeuCopier.getHauteur();
		nbVoleurs=jeuCopier.getNbVoleurs();
		nbCaptures=jeuCopier.getNbCaptures();
	}

//accesseurs

	//Voleurs
	Voleur const & getVoleur(std::size_t num)const{return *(listeVoleurs.at(num));}
	unsigned int getNbVoleurs()const{return nbVoleurs;}
	std::vector<Voleur *> getListeVoleurs()const {return listeVoleurs;}
	unsigned int getNbVoleursSortis()const{return nbVoleurs-(nbCaptures+listeVoleurs.size());}
	void ajouter_Voleur(Voleur const &V);
	void ajoutUnVoleur(){nbVoleurs++;}
	void supprimer_Voleur(Voleur  &V);

	//Gendarmes
	Gendarme const & getGendarme(std::size_t num)const{return *(listeGendarmes.at(num));}
	unsigned int getNbGendarmes()const{return listeGendarmes.size();}
	std::vector<Gendarme *> getListeGendarmes()const {return listeGendarmes;}
	void ajouter_Gendarme(Gendarme const &G);

	//NonJoueur
	NonJoueur const & getObject(std::size_t num)const{return *(listeObjets.at(num));}
	std::vector<NonJoueur *> getListeNonJoueurs()const {return listeObjets;}
	void ajouter_nonJoueur(NonJoueur const &nJ); // à retravailler

	//autre
	unsigned int getNbCaptures()const{return nbCaptures;}
	void ajoutUneCapture(){nbCaptures++;}

	double getLargeur()const{return largeur;}
	double getHauteur()const{return hauteur;}

	bool estFini();

//méthodes
	void Jouer_tour();
    void Afficher();
    void Calcule_Deplacement(Voleur &V);
	void Calcule_Deplacement(Gendarme &G);

private:
	unsigned int nbVoleurs,nbCaptures;
    double largeur,hauteur;
    std::vector<Voleur *> listeVoleurs;
	std::vector<Gendarme *> listeGendarmes;
    std::vector<NonJoueur *> listeObjets;

};

double fRand(double fMin, double fMax);
