
#include "Jeu.hh"

Direction Voleur::jouer() {
	return Direction(3.2,3.1);
}

Direction Gendarme::jouer() {
	return Direction(3.2,3.1);
}

void afficherValeur(type e)
{
    switch (e) {
    case type::nobody:
    	std::cout<<" ";
        break;
    case type::voleur:
        std::cout<<"V";
        break;
    case type::gendarme:
        std::cout<<"G";
        break;
    case type::cachette:
        std::cout<<"C";
        break;
    case type::sortie:
        std::cout<<"S";
        break;
    }
}

void Grille::initialise()
{
	
}

void Grille::ajouter_joueur(Joueur &J)
{
	Liste_Joueur.push_back(J);
}

void Grille::ajouter_sortie(Position P)
{
	Liste_Sortie.push_back(P);	
}

void Grille::deplacement(Joueur & J, Direction D)
{
	J.pos.x=J.pos.x+(D.x*J.speed);
	J.pos.y=J.pos.y+(D.y*J.speed);


	for (unsigned int i = 0;i<Liste_Joueur.size();++i)
	{
		if (Liste_Joueur.at(i).id==J.id)
		{
			Liste_Joueur.at(i).pos.x=J.pos.x;
			Liste_Joueur.at(i).pos.y=J.pos.y;
		}
	}

}

void Grille::afficher()
{



}

bool Grille::victoire(Joueur J)
{
	return true;	
}