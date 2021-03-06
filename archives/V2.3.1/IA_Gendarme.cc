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

		//cas de l'algo déplacant le gendarme vers le voleur le plus proche
		case Choix_Algo::gendarmes_chasseurs:{
			Voleur V = G.Voleur_Plus_Proche(getListeVoleurs());
			result = G.Se_Rapprocher(V);
		}break;

		// IA Facile
		case Choix_Algo::IA_Facile:{

			//Repère un voleur
			Voleur V = G.Voleur_Plus_Proche(getListeVoleurs());
			if (G.getDistance_From(V)<=50){
				result = G.Se_Rapprocher(V);
				break;
			}

			// Respect des distances entre Gendarmes
			Gendarme G2 = G.Gendarme_Plus_Proche(getListeGendarmes());
			if (G.getDistance_From(G2)<=15){
				result = G.Fuir(G2);
			}

			// Vont vers les sorties
			for (auto && sorties : getListeNonJoueurs()){
				result = G.Se_Rapprocher(*sorties);

				if (G.getDistance_From(*sorties)<10){
					result = G.Fuir(*sorties);
				}
			}


			// Sortie déja protégé -> Cherche position optimale


		}break;
	}

	//on ramene X et Y à des valeurs variant de -1 à 1 en effectuant le calcule suivant:
		//x=x/(|x|+|y|)   et de même pour y
	Direction dir=Direction(0,0);
	if(abs(result.getX())+abs(result.getY())!=0){
		dir.setX(result.getX()/(abs(result.getX())+abs(result.getY())));
		dir.setY(result.getY()/(abs(result.getX())+abs(result.getY())));
	}

	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=dir*G.getSpeed();

	//enregistrement du résultat comme étant la prochaine destination du gendarme
	G.setDestination(G.getPosition()+result);

}
