#include "Jeu.hh"

void Jeu::initialise(){

	//à configurer aprés le GUI
}

// déroulement d'un tour /!\ ça boucle
void Jeu::Jouer_tour(){
//calcul des déplacement
	for(auto V:Liste_Voleurs){
		Joue_deplacement(V);
	}
	for(auto G:Liste_Gendarmes){
		Joue_deplacement(G);
	}

//application des déplacement
	for(auto V:Liste_Voleurs){
		V.deplacement();
	}
	for(auto G:Liste_Gendarmes){
		G.deplacement();
		//on verifie s'il capture un voleur
		for(auto V:Liste_Voleurs){
			if (G.Hitbox_touche(V)){
				std::cout<<"Le Gendarme "<<G.getNom()<<" à capturé le voleur "<<V.getNom()<<std::endl;
				std::cout<<V.Affiche_Hitbox()<<"\n";
				 supprimer_voleur(V);
				 ajoutUneCapture();
			 }
		}
	}
	//on verifie si un voleur s'est enfui sans se faire attraper
	for(auto V:Liste_Voleurs){
		for(auto S : Liste_Objets){
			if(S.getType()==Type::sortie && S.Hitbox_touche(V)){
				std::cout<<"Le voleur "<<V.getNom()<<" est sorti!\n";
				std::cout<<V.Affiche_Hitbox()<<"\n";
				supprimer_voleur(V);
			}
		}
	}
}

//ajoute un voleur à la partie
void Jeu::ajouter_voleur(Voleur V)
{
	Liste_Voleurs.push_back(V);
	ajoutUnVoleur();
}
//ajoute un joueur à la partie
void Jeu::ajouter_gendarme(Gendarme G)
{
	Liste_Gendarmes.push_back(G);
}
//retire un voleur de la partie et mets fin à la partie s'il s'agissait du dernier
void Jeu::supprimer_voleur(Voleur &V){
	int i=0;
	for(auto Vcible: Liste_Voleurs)
	{
		if(Vcible.getId()==V.getId())
		{
			Liste_Voleurs.erase(Liste_Voleurs.begin()+i);
			break;
		}
		i++;
	}
}

//ajout d'un objet à la partie
void Jeu::ajouter_nonJoueur(NonJoueur nJ){
	Liste_Objets.push_back(nJ); // fonctionnement à confirmer
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

// execute le déplacement d'un voleur vers sa destination
void Jeu::Joue_deplacement(Voleur &V){
	//calcul du déplacement à réaliser
	Direction result(0,0);
	switch (V.getAlgo())
	{
		case Choix_Algo::random:
		{
			result = Direction(fRand(-3,3),fRand(-3,3));
		}
		break;

		case Choix_Algo::haut:
		{
			result = Direction(0,1);
		}
		break;

		case Choix_Algo::bas:
		{
			result = Direction(0,-1);
		}
		break;

		case Choix_Algo::Gendarme_Chasseurs:
		{
			Gendarme G = V.Gendarme_Plus_Proche(getListeGendarme());
			result = V.Fuir(G);
		}
		break;
	}

	//enregistrement de celui-ci
	result=result*V.getSpeed();

	Direction verif = V.getPosition()+result;

	//  Verification des murs
	if (verif.getX()+2>400 or verif.getX()-2<-400 )
	{
		result.setX(-result.getX());
	}
	if (verif.getY()+2>400 or verif.getY()-2<-400)
	{
		result.setY(-result.getY());

	}



	V.setDestination(V.getPosition()+result);

}

// execute le déplacement d'un gendarme vers sa destination
void Jeu::Joue_deplacement(Gendarme &G){
	//calcul du déplacement à réaliser
	Direction result(0,0);
	switch (G.getAlgo())
	{
		case Choix_Algo::random:
		{
			result = Direction(fRand(-3,3),fRand(-3,3));
		}
		break;

		case Choix_Algo::haut:
		{
			result = Direction(0,1);
		}
		break;

		case Choix_Algo::bas:
		{
			result = Direction(0,-1);
		}
		break;

		case Choix_Algo::Gendarme_Chasseurs:
		{
			Voleur V = G.Voleur_Plus_Proche(getListeVoleur());
			result = G.Se_Rapprocher(V);
		}
		break;
	}

	//enregistrement de celui-ci
	result=result*G.getSpeed();

	Direction verif = G.getPosition()+result;

	//  Verification des murs
	if (verif.getX()+2>400 or verif.getX()-2<-400 )
	{
		result.setX(-result.getX());
	}
	if (verif.getY()+2>400 or verif.getY()-2<-400)
	{
		result.setY(-result.getY());
	}

	G.setDestination(G.getPosition()+result);


}


//le jeu se termine quand il n'y a plus de voleur en jeu
bool Jeu::estFini(){
	return Liste_Voleurs.empty();
}
