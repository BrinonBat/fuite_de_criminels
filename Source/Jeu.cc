#include "Jeu.hh"

void Jeu::Initialise(){

	//à configurer aprés le GUI
}

void Jeu::Afficher()
{
	std::cout<<"Liste Joueurs avec position et Hitbox :\n";
	for(auto i:Liste_Voleurs){
		std::cout<<i->getNom()<<" position : "<<i->Affiche_Position()<<" | "<<i->Affiche_Hitbox()<<"\n";
	}
	for(auto i:Liste_Gendarmes){
		std::cout<<i->getNom()<<" position : "<<i->Affiche_Position()<<" | "<<i->Affiche_Hitbox()<<"\n";
	}
	std::cout<<"Liste NonJoueur avec position et Hitbox :\n";
	for (auto i:Liste_Objets)
	{
		std::cout<<"Sortie"<<" position : "<<i->Affiche_Position()<<" | "<<i->Affiche_Hitbox()<<"\n";
	}
}
//ajoute un voleur à la partie
void Jeu::ajouter_voleur(Voleur const &V)
{
	Liste_Voleurs.push_back(V.clone());
	ajoutUnVoleur();
}
//ajoute un joueur à la partie
void Jeu::ajouter_gendarme(Gendarme const &G)
{
	Liste_Gendarmes.push_back(G.clone());
	ajoutUnGendarme();
}
//retire un voleur de la partie et mets fin à la partie s'il s'agissait du dernier
void Jeu::supprimer_voleur(Voleur &V){
	int i=0;
	for(auto && Vcible: Liste_Voleurs)
	{
		if(Vcible->getId()==V.getId())
		{
			delete Vcible;
			break;
		}
		i++;
	}
	Liste_Voleurs.erase(Liste_Voleurs.begin()+i);
}

//ajout d'un objet à la partie
void Jeu::ajouter_nonJoueur(NonJoueur const nJ){
	Liste_Objets.push_back(new NonJoueur(nJ)); // fonctionnement à confirmer
}

/// Execution d'un tour entier pour le Jeu pris en paramètre.
void Jeu::Jouer_tour(){

//calcul des déplacements
	for(auto &&V:Liste_Voleurs){
		Calcule_Deplacement(*V);
	}
	for(auto &&G:Liste_Gendarmes){
		Calcule_Deplacement(*G);
	}

//application des déplacements
	for(auto &&V:Liste_Voleurs){
		V->Deplacement();
	}
	for(auto &&G:Liste_Gendarmes){
		G->Deplacement();
		//on verifie s'il capture un voleur
		for(auto &&V:Liste_Voleurs){
			if (G->Hitbox_touche(*V)){
				std::cout<<"Le Gendarme "<<G->getNom()<<" à capturé le voleur "<<V->getNom()<<std::endl;
				std::cout<<V->Affiche_Hitbox()<<"\n";
				 supprimer_voleur(*V);
				 ajoutUneCapture();
			 }
		}
	}
	//on verifie si un voleur s'est enfui sans se faire attraper
	for(auto &&V:Liste_Voleurs){
		for(auto &&S : Liste_Objets){
			if(S->getType()==Type::sortie && S->Hitbox_touche(*V)){
				std::cout<<"Le voleur "<<V->getNom()<<" est sorti!\n";
				std::cout<<V->Affiche_Hitbox()<<"\n";
				supprimer_voleur(*V);
			}
		}
	}
}

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

bool Jeu::Coup_Possible(Joueur &J, Direction coup)
{

	coup = coup *J.getSpeed();
	Direction verif = J.getPosition()+coup;

	// Sortie du Terrain
	if (verif.getX()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getX()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN )
	{
		return false;
	}
	if (verif.getY()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getY()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN)
	{
		return false;
	}

	// HitBox en contact avec un autre joueur
	for (auto &&i : Liste_Voleurs)
	{
		if (J.Hitbox_touche(*i)) return false;
	}

	for (auto &&j : Liste_Gendarmes)
	{
		if (J.Hitbox_touche(*j)) return false;
	}

	return true;

}

//le jeu se termine quand il n'y a plus de voleur en jeu
bool Jeu::estFini(){
	return Liste_Voleurs.empty();
}
