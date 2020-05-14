#include "Jeu.hh"

/// calcule la prochaine destination du voleur en fonction de l'IA choisie
void Jeu::Calcule_Deplacement(Voleur &V){

	//définitions
	Direction result(0,0);
	//constantes correspondant à l'importance de chaque action
	const int IMP_FUITE_GENDARME(6);
	const int IMP_EVITE_MUR(10);
	const int IMP_APPROCHE_SORTIE(2);

	//calcul du déplacement à réaliser en fonction de l'algorithme séléctionné
	switch (V.getAlgo()){

	/////IA RANDOM/////
		//cas de l'algo retournant des déplacements aléatoires
		case Choix_Algo::random:{
			result = Direction(fRand(-3,3),fRand(-3,3));
		}break;

	/////IA FUITE/////
		//cas de l'algo permettant au voleur de fuir le gendarme le plus proche
		case Choix_Algo::gendarmes_chasseurs:{
			Gendarme G = V.Gendarme_Plus_Proche(getListeGendarmes());
			result = result+V.Fuir(G)*IMP_FUITE_GENDARME;
		}break;

	/////IA Facile/////
		case Choix_Algo::IA_Facile:{

			// Fuit si rencontre un gendarme
			Gendarme G = V.Gendarme_Plus_Proche(getListeGendarmes());
			if (V.getDistance_From(G)<30){
				result = result+V.Fuir(G)*IMP_FUITE_GENDARME;
				break;
			}

			// Va vers sorties
			for (auto && sorties : getListeNonJoueurs()){
				result = result+V.Se_Rapprocher(*sorties)*IMP_APPROCHE_SORTIE;
			}

		}break;
	}

	//algo commun aux différentes IA
	// on évite les murs
	result = result+V.Evite_Murs()*IMP_EVITE_MUR;

	//on ramene X et Y à des valeurs variant de -1 à 1 en effectuant le calcule suivant:
		//x=x/(|x|+|y|)   et de même pour y
	Direction dir=Direction(0,0);
	if(abs(result.getX())+abs(result.getY())!=0){
		dir.setX(result.getX()/(abs(result.getX())+abs(result.getY())));
		dir.setY(result.getY()/(abs(result.getX())+abs(result.getY())));
	}
	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=dir*V.getSpeed();


	//enregistrement du résultat comme étant la prochaine destination du voleur
	V.setDestination(V.getPosition()+result);

}
