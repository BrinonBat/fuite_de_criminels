#include "Jeu.hh"
/// calcule la prochaine destination du voleur en fonction de l'IA choisie
void Jeu::Calcule_Deplacement(Voleur &V){

	//définition
	Direction result(0,0);

	//calcul du déplacement à réaliser en fonction de l'algorithme séléctionné
	switch (V.getAlgo()){

		//cas de l'algo retournant des déplacements aléatoires
		case Choix_Algo::random:{
			result = Direction(fRand(-3,3),fRand(-3,3));
		}break;

		//cas de l'algo déplacant le personnage vers le haut
		case Choix_Algo::haut:{
			result = Direction(0,1);
		}break;

		//cas de l'algo déplacant le personnage vers le bas
		case Choix_Algo::bas:{
			result = Direction(0,-1);
		}break;

		//cas de l'algo permettant au voleur de fuir le gendarme le plus proche
		case Choix_Algo::gendarmes_chasseurs:{
			Gendarme G = V.Gendarme_Plus_Proche(getListeGendarmes());
			result = V.Fuir(G);
		}break;

		//IA Facile
		case Choix_Algo::IA_Facile:{
			
			// Va vers sorties
			for (auto && sorties : getListeNonJoueurs())
			{
				result = V.Se_Rapprocher(*sorties);
			}

		}break;
	}

	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=result*V.getSpeed();

/* CE SERA MODIFIE */
	Direction verif = V.getPosition()+result;

	//  Verification des murs
	if (verif.getX()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getX()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN ){
		result.setX(-result.getX());
	}
	if (verif.getY()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getY()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN){
		result.setY(-result.getY());
	}

	//enregistrement du résultat comme étant la prochaine destination du voleur
	V.setDestination(V.getPosition()+result);

}
