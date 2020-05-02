#include "Jeu.hh"

void Jeu::initialise(){

	//à configurer aprés le GUI
}

void Jeu::afficher()
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

// déroulement d'un tour /!\ ça boucle
void Jeu::Jouer_tour(){
//calcul des déplacement
	for(auto &&V:Liste_Voleurs){
		V->Joue_Deplacement();
	}
	for(auto &&G:Liste_Gendarmes){
		G->Joue_Deplacement();

	}

//application des déplacement
	for(auto &&V:Liste_Voleurs){
		deplacement(*V);
	}
	for(auto &&G:Liste_Gendarmes){
		deplacement(*G);
		//on verifie s'il capture un voleur
		for(auto &&V:Liste_Voleurs){
			if (G->Hitbox_touche(*V)){
				std::cout<<"Le Gendarme "<<G->getNom()<<" à capturé le voleur "<<V->getNom()<<std::endl;
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
				supprimer_voleur(*V);
			}
		}
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

// execute le déplacement d'un voleur vers sa destination
void Jeu::deplacement(Voleur &V){
	//calcul de la nouvelle position
	V.setPosition(V.getDestination());
	V.setHitbox();
}

// execute le déplacement d'un gendarme vers sa destination
void Jeu::deplacement(Gendarme &G){
	//calcul de la nouvelle position
	G.setPosition(G.getDestination());
	G.setHitbox();
}


//le jeu se termine quand il n'y a plus de voleur en jeu
bool Jeu::estFini(){
	return Liste_Voleurs.empty();
}
