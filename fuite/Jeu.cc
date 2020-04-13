
#include "Jeu.hh"

Direction Voleur::jouer() {
	return Direction::Bas_Droite;
}

Direction Gendarme::jouer() {
	return Direction::Bas_Droite;
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
	  for (unsigned int i = 0;i<largeur;++i)
    {
        for (unsigned int j =0;j<hauteur;++j)
        {
            Tab[i][j]=type::nobody;
        }
    }
}

void Grille::ajouter_joueur(Joueur &J)
{
	Liste_Joueur.push_back(J);
	Tab[J.pos.x][J.pos.y]=J.t;
}

void Grille::ajouter_sortie(Position P)
{
	Liste_Sortie.push_back(P);
	Tab[P.x][P.y]=type::sortie;
}

void Grille::deplacement(Joueur & J, Direction D)
{

	Tab[J.pos.x][J.pos.y]=type::nobody;

	switch (D) {
    case Direction::Bas:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers le bas\n";
    	J.pos.x=J.pos.x+1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

    case Direction::Haut:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers le haut\n";
    	J.pos.x=J.pos.x-1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

    case Direction::Gauche:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers la gauche\n";
    	J.pos.y=J.pos.y-1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

	case Direction::Droite:
		std::cout<<"Déplacement de : "<<J.nom<<" vers la droite\n";
    	J.pos.y=J.pos.y+1;
    	if (victoire(J)) {std::cout<<"Victoire";break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

    case Direction::Haut_Gauche:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers le haut-gauche\n";
    	J.pos.y=J.pos.y-1;
    	J.pos.x=J.pos.x-1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

    case Direction::Haut_Droite:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers le haut-droite\n";
    	J.pos.y=J.pos.y+1;
    	J.pos.x=J.pos.x-1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

    case Direction::Bas_Droite:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers le bas-droite\n";
    	J.pos.y=J.pos.y+1;
    	J.pos.x=J.pos.x+1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;

    case Direction::Bas_Gauche:
    	std::cout<<"Déplacement de : "<<J.nom<<" vers le bas-gauche\n";
    	J.pos.x=J.pos.x+1;
    	J.pos.y=J.pos.y-1;
    	if (victoire(J)) {std::cout<<"Victoire"; break;}
    	Tab[J.pos.x][J.pos.y]=J.t;
        break;
		
	default : std::cout<<"erreur lors du déplacement";
    }

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

    for (unsigned int i = 0;i<largeur;++i)
    {
        for (unsigned int j =0;j<hauteur;++j)
        {
            afficherValeur(Tab[i][j]);
        }
        std::cout<<std::endl;
    }

}

bool Grille::victoire(Joueur J)
{
	return (Tab[J.pos.x][J.pos.y]==type::sortie);
}
