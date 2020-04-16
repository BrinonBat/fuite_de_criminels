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
	J.setPosition(Position(J.getPosition().x+(D.x*J.speed),J.getPosition().y+(D.y*J.speed)));

}

void Jeu::afficher()
{



}

bool Jeu::victoire(Joueur const & J)
{
	return true;
}
