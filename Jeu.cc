#include "Jeu.hh"

void Jeu::initialise(){

	//à configurer aprés le GUI
}

void Jeu::afficher()
{
	std::cout<<"Liste Joueurs avec position :\n";
	for(auto i:Liste_Voleurs){
		std::cout<<i->getNom()<<" position : "<<i->Affiche_Position()<<"\n";
	}
	for(auto i:Liste_Gendarmes){
		std::cout<<i->getNom()<<" position : "<<i->Affiche_Position()<<"\n";
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
			if (G->getPosition()==V->getPosition()){
				 supprimer_voleur(*V);
				 ajoutUneCapture();
			 }
		}
	}
	//on verifie si un voleur s'est enfui sans se faire attraper
	for(auto &&V:Liste_Voleurs){
		for(auto &&sortie : Liste_Objets){
			if(sortie->getType()==Type::sortie && V->getPosition()==sortie->getPosition()){
				std::cout<<"Le voleur"<<V->getNom()<<" est sorti!\n";
				supprimer_voleur(*V);
			}
		}
	}
	/*
	for(auto J:Liste_Joueur){
		//traitement du voleur
		if(J->estVoleur()){
			//verification de la fuite du voleur

			for(auto sortie : Liste_Objets){
				if(sortie->getType()==Type::sortie && J->getPosition()==sortie->getPosition()) supprimer_voleur(J->getId());
			}
		//traitement du gendarme
		}else{
			for(auto voleur : Liste_Joueur){
				if(voleur->estVoleur() && J->getPosition()==voleur->getPosition()){
					supprimer_voleur(voleur->getId()); // remplacement du fonctionnement par id par un fonctionnement par voleur ?
					ajoutUneCapture();
				} // fin if
			}// fin for
		} // fin else
	} */

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
}

// execute le déplacement d'un gendarme vers sa destination
void Jeu::deplacement(Gendarme &G){
	//calcul de la nouvelle position
	G.setPosition(G.getDestination());
}


//le jeu se termine quand il n'y a plus de voleur en jeu
bool Jeu::estFini(){
	return Liste_Voleurs.empty();
}
