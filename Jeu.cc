#include "Jeu.hh"

void Jeu::initialise(){

	//à configurer aprés le GUI
}

void Jeu::afficher()
{

	//GUI fera le travail

}

// déroulement d'un tour /!\ ça segfault
void Jeu::Jouer_tour(){
	for(auto i:Liste_Joueur){
		deplacement(*i,i->Joue_Deplacement());
	}
}

//ajoute un joueur à la partie
void Jeu::ajouter_joueur(Joueur const &J)
{
	Liste_Joueur.push_back(J.clone());
	if(J.estVoleur()) ajoutUnVoleur();
}

//retire un voleur de la partie et mets fin à la partie s'il s'agissait du dernier
void Jeu::supprimer_voleur(unsigned int id){
	//parcours des voleur et retrait de celui concerné
	for(auto i =Liste_Joueur.begin(); i!= Liste_Joueur.end();++i){
      if(Liste_Joueur[size_t(*i)]->getId()==id && Liste_Joueur[size_t(*i)]->estVoleur()){
        Liste_Joueur.erase(i);
        return; // fin si le voleur est supprimé
      }
    }
	//on vérifie si c'était le dernier voleur sur le terrain
	verifieFin();
}

//ajout d'un objet à la partie
void Jeu::ajouter_nonJoueur(NonJoueur nJ){
	Liste_Objets.push_back(new NonJoueur(nJ)); // fonctionnement à confirmer
}

// execute le déplacement d'un joueur vers une direction donnée
void Jeu::deplacement(Joueur & J, Direction const & D){
	//calcul de la nouvelle position
	J.setPosition(J.getPosition()+D);

	//traitement du voleur
	if(J.estVoleur()){
		//verification de la fuite du voleur
		for(auto sortie : Liste_Objets){
			if(sortie->getType()==Type::sortie && J.getPosition()==sortie->getPosition()) supprimer_voleur(J.getId());
		}
	//traitement du gendarme
	}else{
		for(auto voleur : Liste_Joueur){
			if(voleur->estVoleur() && J.getPosition()==voleur->getPosition()){
				supprimer_voleur(voleur->getId()); // remplacement du fonctionnement par id par un fonctionnement par voleur ?
				ajoutUneCapture();
			} // fin if
		}// fin for
	} // fin else
} // fin méthode



//le jeu se termine quand il n'y a plus de voleur en jeu
void Jeu::verifieFin(){
	for(auto i:Liste_Joueur){
			if(i->estVoleur()) return;
	}
	this->fini=true;
}
