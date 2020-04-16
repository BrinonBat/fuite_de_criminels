#include "Entites.hh"


class Jeu {

public :
    Jeu(coordonnee plargeur, coordonnee phauteur) {
		largeur=plargeur;
		hauteur=phauteur;
    }
    Jeu(Jeu const & JeuCopier){
        largeur=JeuCopier.largeur;
        hauteur=JeuCopier.hauteur;
    }

    void afficher();
    void initialise();
    void ajouter_joueur(Joueur const &J);
    void ajouter_sortie(Position P);
    void deplacement(Joueur & J, Direction d);
    bool victoire(Joueur const & J);


    coordonnee largeur,hauteur;
    std::vector<Joueur *> Liste_Joueur;
    std::vector<Position> Liste_Sortie;

};
