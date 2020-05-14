#include "Jeu.hh"

/***************************** accesseurs **************************/

///setter permettant d'ajouter un Voleur à la partie
void Jeu::ajouter_Voleur(Voleur const &V){

	//ajout d'un pointeur vers le Voleur à la liste de voleurs
	listeVoleurs.push_back(V.clone());
	ajoutUnVoleur(); // augmentation du nombre total de voleurs

}

/// setter permettant de retirer un Voleur de la partie et mettre fin à celle-ci s'il s'agissait du dernier
void Jeu::supprimer_Voleur(Voleur &V){

	//définition
	int i=0;

	//parcours de la liste de voleurs pour y trouver le voleur cherché
	for(auto && Vcible: listeVoleurs){
		if(Vcible->getId()==V.getId()){

			//une fois le voleur trouvé, on le supprime
			delete Vcible;
			break;

		}
		i++;
	}

	//on retire le pointeur associé
	listeVoleurs.erase(listeVoleurs.begin()+i);

}

/// setter permettant d'ajouter un Gendarme à la partie
void Jeu::ajouter_Gendarme(Gendarme const &G){

	//ajout d'un pointeur vers le Gendarme à la liste de gendarmes
	listeGendarmes.push_back(G.clone());

}

///  setter permettant d'ajouter un NonJoueur à la partie
void Jeu::ajouter_nonJoueur(NonJoueur const &nJ){

	//ajout d'un pointeur vers le nonJoueur à la liste
	listeObjets.push_back(new NonJoueur(nJ));

}

/// le jeu se termine quand il n'y a plus de voleur en jeu
bool Jeu::estFini(){

	// retourne vrai si la liste de voleur est vide, faux sinon
	return listeVoleurs.empty();
}

/******************** méthodes **************************/

/// Execution d'un tour entier pour le Jeu pris en paramètre.
void Jeu::Jouer_tour(){

	//calcul des déplacements
	for(auto &&V:listeVoleurs){
		Calcule_Deplacement(*V);
	}
	for(auto &&G:listeGendarmes){
		Calcule_Deplacement(*G);
	}

	//application des déplacements
	for(auto &&V:listeVoleurs){
		V->Deplacement();
	}
	for(auto &&G:listeGendarmes){
		G->Deplacement();

		//on verifie s'il capture un voleur
		for(auto &&V:listeVoleurs){
			if (G->Hitbox_Touche(*V)){
				std::cout<<"Le Gendarme "<<G->getNom()<<" à capturé le voleur "<<V->getNom()<<std::endl;
				std::cout<<V->Affiche_Hitbox()<<"\n";
				 supprimer_Voleur(*V);
				 ajoutUneCapture();
			 }
		}
	}

	//on verifie si un voleur s'est enfui sans se faire attraper
	for(auto &&V:listeVoleurs){
		for(auto &&S : listeObjets){
			if(S->getType()==Type::sortie && S->Hitbox_Touche(*V)){
				std::cout<<"Le voleur "<<V->getNom()<<" est sorti!\n";
				std::cout<<V->Affiche_Hitbox()<<"\n";
				supprimer_Voleur(*V);
			}
		}
	}
}

/// génére un affichage de l'état actuel du Jeu dans le terminal
void Jeu::Afficher(){

	//affichage des Joueurs
	std::cout<<"Liste Joueurs avec position et Hitbox :\n";

	//affichage de tous les voleurs (position et hitbox)
	for(auto i:listeVoleurs){
		std::cout<<i->getNom()<<" position : "<<i->Affiche_Position()<<" | "<<i->Affiche_Hitbox()<<"\n";
	}

	//affichage de tous les gendarmes
	for(auto i:listeGendarmes){
		std::cout<<i->getNom()<<" position : "<<i->Affiche_Position()<<" | "<<i->Affiche_Hitbox()<<"\n";
	}

	//affichage des NonJoueurs
	std::cout<<"Liste NonJoueur avec position et Hitbox :\n";
	for (auto i:listeObjets){
		std::cout<<"Sortie"<<" position : "<<i->Affiche_Position()<<" | "<<i->Affiche_Hitbox()<<"\n";
	}
}

/// fonction inutilisée et non documentée pour le moment, mais conservée de côté si on a besoin à un moment de s'en servir.
/// indique si le coup pris en paramètre est possible pour le Joueur pris en paramètre
bool Jeu::Coup_Possible(Joueur &J, Direction coup)
{

	coup = coup *J.getSpeed();
	Direction verif = J.getPosition()+coup;

	// Sortie du Terrain
	if (verif.getX()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getX()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN ){
		return false;
	}
	if (verif.getY()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getY()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN){
		return false;
	}

	// HitBox en contact avec un autre joueur
	for (auto &&i : listeVoleurs){
		if (J.Hitbox_Touche(*i)) return false;
	}

	for (auto &&j : listeGendarmes){
		if (J.Hitbox_Touche(*j)) return false;
	}

	return true;

}

/************************** fonction ******************************/

/// redéfinition de fRanD pour avoir un double random entre un certain minimum et maximum
double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
