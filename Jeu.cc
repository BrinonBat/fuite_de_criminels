#include "Jeu.hh"

void Jeu::initialise()
{

}

void Jeu::ajouter_joueur(Joueur const &J)
{
	Liste_Joueur.push_back(J.clone());
}

void Jeu::ajouter_sortie(Position P)
{
	Liste_Sortie.push_back(P); // à retravailler. Utilisation de pointeur plutot que de copie ? liste_sortie devient liste_objets ?
}

void Jeu::deplacement(Joueur & J, Direction D)
{
	//calcul de la nouvelle position
	J.setPosition(J.getPosition()+D);

	//J.setPosition(Position(J.getPosition().getX()+(D.getX()*J.getSpeed()),J.getPosition().getY()+(D.getY()*J.getSpeed())));

}

void Jeu::afficher()
{



}

bool Jeu::victoire(Joueur const & J)
{
	return true;
}
