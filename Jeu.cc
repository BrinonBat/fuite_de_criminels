#include "Jeu.hh"
void Jeu::initialise()
{

}

void Jeu::ajouter_joueur(Joueur const &J)
{
	Liste_Joueur.push_back(J.clone());
}

void Jeu::supprimer_voleur(int id){
	for(auto i =Liste_Joueur.begin(); i!= Liste_Joueur.end();++i){
      if(Liste_Joueur[size_t(*i)]->getId()==id && Liste_Joueur[size_t(*i)]->estVoleur()){
        Liste_Joueur.erase(i);
        return; // fin si le voleur est supprimé
      }
    }
	//on vérifie si c'était le dernier voleur sur le terrain
	verifieFin();
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

//le jeu se termine quand il n'y a plus de voleur en jeu
void Jeu::verifieFin(){
	for(auto i:Liste_Joueur){
			if(i->estVoleur()) return;
	}
	this->fini=true;
}
