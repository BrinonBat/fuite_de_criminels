#include "Jeu.hh"
/// calcule la prochaine destination du gendarme en fonction de l'IA choisie
void Jeu::Calcule_Deplacement(Gendarme &G){

	//définition
	Direction result(0,0);

	//calcul du déplacement à réaliser en fonction de l'algorithme séléctionné
	switch (G.getAlgo()){

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

		//cas de l'algo déplacant le gendarme vers le voleur le plus proche
		case Choix_Algo::gendarmes_chasseurs:{
			Voleur V = G.Voleur_Plus_Proche(getListeVoleurs());
			result = G.Se_Rapprocher(V);
		}break;

		// IA Facile
		case Choix_Algo::IA_Facile:{

			//Repère un voleur 
			Voleur V = G.Voleur_Plus_Proche(getListeVoleurs());
			if (G.getDistance_From(V)<=20)
			{
				result = G.Se_Rapprocher(V);
				break;
			}

			// Respect des distances entre Gendarmes
			Gendarme G2 = G.Gendarme_Plus_Proche(getListeGendarmes());
			if (G.getDistance_From(G2)<=15)
			{	
				result = G.Fuir(G2);
			}
	
			// Vont vers les sorties
			for (auto && sorties : getListeNonJoueurs())
			{
				result = G.Se_Rapprocher(*sorties);

				if (G.getDistance_From(*sorties)<10)
				{
					result = G.Fuir(*sorties);
					
				}
			}


			// Sortie déja protégé -> Cherche position optimale
			

		}break;
	}
	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=result*G.getSpeed();

/* CE SERA MODIFIE */
	Direction verif = G.getPosition()+result;

	//  Verification des murs
	if (verif.getX()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getX()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN ){
		result.setX(-result.getX());
	}
	if (verif.getY()+(TAILLE_HITBOX/2)>TAILLE_TERRAIN or verif.getY()-(TAILLE_HITBOX/2)<-TAILLE_TERRAIN){
		result.setY(-result.getY());
	}

	//enregistrement du résultat comme étant la prochaine destination du gendarme
	G.setDestination(G.getPosition()+result);

}
