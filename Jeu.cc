#include "Jeu.hh"

void Jeu::initialise()
{

}

void Jeu::ajouter_joueur(Joueur const &J)
{
	Liste_Joueur.push_back(J.clone());
}

void Jeu::ajouter_nonJoueur(NonJoueur nJ){
	Liste_Objets.push_back(new NonJoueur(nJ)); // fonctionnement à confirmer
}

void Jeu::deplacement(Joueur & J, Direction const & D)
{
	//calcul de la nouvelle position
	J.setPosition(J.getPosition()+D);

}

void Jeu::afficher()
{



}

bool Jeu::victoire(Joueur const & J)
{
	return true;
}
