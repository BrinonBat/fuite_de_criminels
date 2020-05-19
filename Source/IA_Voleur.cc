#include "Jeu.hh"

/// calcule la prochaine destination du voleur en fonction de l'IA choisie
void Jeu::Calcule_Deplacement(Voleur &V){

	//définitions
	Direction result(0,0);


	NonJoueur S = V.Sortie_Plus_Proche(getListeNonJoueurs());//sortie la plus proche du voleur

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
			result = result+V.Fuir(G);
		}break;

	/////IA Facile/////
		case Choix_Algo::IA_Facile:{

			//constantes locales correspondant à l'importance de chaque action
			const double IMP_FUITE_GENDARME(6);
			const double IMP_APPROCHE_SORTIE(2);

			// Fuit si rencontre un gendarme
			Gendarme G = V.Gendarme_Plus_Proche(getListeGendarmes());
			if (V.getDistance_From(G)<PORTE_VUE){
				result = result+V.Fuir(G)*IMP_FUITE_GENDARME;
			}

			// Se dirige vers la sortie la plus proche
			/* if (V.getDistance_From(S)<PORTE_VUE){ // A IMPLEMENTER SI DOIT TROUVER LA SORTIE */
				result = result+V.Se_Rapprocher(S)*IMP_APPROCHE_SORTIE;
			/*}*/

		}break;

	/////IA MOYEN/////
		case Choix_Algo::IA_Moyen:{

			//constantes locales correspondant à l'importance de chaque action
			const double IMP_FUITE_GENDARME(4); // comptée deux fois, donc plus faible que dans IA_Facile
			const double IMP_APPROCHE_SORTIE(3);

			//si la sortie est plus proche que n'importe quel gendarme, le voleur néglige les gendarmes
			if(V.getDistance_From(V.Gendarme_Plus_Proche(getListeGendarmes()))<=V.getDistance_From(S)){

				// Fuit si rencontre un (ou plusieurs) gendarmes
				for(auto &&G: getListeGendarmes()){

					//traitement pour chaque gendarme repéré
					if(V.getDistance_From(*G)<=PORTE_VUE){

						//calcul de la fuite
						Direction temp=result+V.Fuir(*G)*IMP_FUITE_GENDARME;

						//cas ou le voleur est cerné
						if(temp==Direction(0,0)){
							//rotation à 90°
							temp.setX(result.getY());
							temp.setY(result.getX());
						}
						result=temp;
					}

				}

				//on s'éloigne un peu plus du gendarme le plus proche
				Gendarme G = V.Gendarme_Plus_Proche(getListeGendarmes());
				if (V.getDistance_From(G)<=PORTE_VUE){
					result = result+V.Fuir(G)*IMP_FUITE_GENDARME;
				}

			}

			// Se dirige vers la sortie la plus proche
			/* if (V.getDistance_From(S)<PORTE_VUE){ // A IMPLEMENTER SI DOIT TROUVER LA SORTIE */
				result = result+V.Se_Rapprocher(S)*IMP_APPROCHE_SORTIE;
			/*}*/

		}break;
	}

	//on ramene X et Y à des valeurs variant de -1 à 1 en effectuant le calcule suivant:
		//x=x/(|x|+|y|)   et de même pour y
	Direction dir=Direction(0,0);
	if(fabs(result.getX())+fabs(result.getY())!=0){
		dir.setX(result.getX()/(fabs(result.getX())+fabs(result.getY())));
		dir.setY(result.getY()/(fabs(result.getX())+fabs(result.getY())));
	}

	//on évite le mur, mais que si on ne se dirige pas vers une sortie (donc quand on augmente la distance vers celle-ci)
	if(S.getDistance_From(V)<=S.getDistance_From(Voleur(V.getPosition()+dir,V.getSpeed(),"temp",Choix_Algo::random))){
		dir=V.Evite_Murs(dir);
	}
	std::cout<<"dist actuelle :"+std::to_string(S.getDistance_From(V))+"vs dist  destnation :"+std::to_string(S.getDistance_From(Voleur(V.getPosition()+dir,V.getSpeed(),"temp",Choix_Algo::random)))<<std::endl;

	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=dir*V.getSpeed();

	//si le personnage veut quitter le terrain, il est redirigé vers la sortie. (car s'il est proche du bord de terrain, c'est qu'il est proche de la sortie)
	if(fabs((V.getPosition()+result).getX())>TAILLE_TERRAIN or fabs((V.getPosition()+result).getY())>TAILLE_TERRAIN){
		result=V.Se_Rapprocher(S)*V.getSpeed();
	}

	//affichage dans le termine pour visualisation
	std::cout<<"PING V("+std::to_string(V.getPosition().getX())+","+std::to_string(V.getPosition().getY())+ // "PING V(x,y)"
	") + ("+std::to_string(result.getX())+","+std::to_string(result.getY())+ // " + (x,y)"
	") ---> ("+std::to_string(V.getPosition().getX()+result.getX())+","+std::to_string(V.getPosition().getY()+result.getY())+ // "---> (x,y)"
	") déplacement total:" +std::to_string(fabs(result.getX())+fabs(result.getY()))<<std::endl;// "déplacement total : x+y"

	//enregistrement du résultat comme étant la prochaine destination du voleur
	V.setDestination(V.getPosition()+result);
}


/// méthode permettant d'éviter aux Voleur de pércuter les murs
Direction Voleur::Evite_Murs(Direction const & dirActuelle){

	//déclarations
	Direction dirResultat=dirActuelle;

	//si on peut apercevoir le mur Ouest et qu'on s'en approche
	if((this->getPosition().getX()<=-(TAILLE_TERRAIN-PORTE_VUE)) && (dirActuelle.getX()<=0)){

		//déclarations
		double proximite=TAILLE_TERRAIN+(this->getPosition().getX()+(dirActuelle.getX()*this->getSpeed())); // indice indiquant à quel point l'on est proche du mur
		double marge_modif=fabs(dirActuelle.getX())+1.0; // on appliquera une modification appartenant à l'ensemble [0,marge_modif]

		//calcul du nouveau X
		dirResultat.setX(dirActuelle.getX()+(marge_modif*((PORTE_VUE-proximite)/PORTE_VUE))); // application d'une modification correspondant à un %age du max possible

		//cas ou le Voleur se dirige droit dans le mur (direction perpendiculaire)
		if(dirActuelle.getY()==this->getPosition().getY()){
			if(this->getPosition().getY()<0) dirResultat.setY(1.0-fabs(dirResultat.getX())); // si le Voleur est vers le bas du terrain, il fuit vers le haut
			else dirResultat.setY(fabs(dirResultat.getX()-1.0)); // si le Voleur est vers le haut du terrain, il fuit vers la partie basse
		}

		//cas ou il ne se dirige pas exactement droit dedans
		else{
			if(dirActuelle.getY()<0) dirResultat.setY(-1.0+fabs(dirResultat.getX())); // si le Voleur se dirigeais vers le bas du terrain, il fuit vers le bas
			else dirResultat.setY(1.0-fabs(dirResultat.getX())); // si le Voleur se dirigeais vers le haut du terrain, il fuit vers le haut
		}

	}

	//si on peut apercevoir le mur Est et qu'on s'en approche
	else if((this->getPosition().getX()>=TAILLE_TERRAIN-PORTE_VUE) && (dirActuelle.getX()>=0)){

		//déclarations
		double proximite=TAILLE_TERRAIN-(this->getPosition().getX()+(dirActuelle.getX()*this->getSpeed()));
		double marge_modif=fabs(dirActuelle.getX())+1.0;

		//calcul du nouveau X
		dirResultat.setX(dirActuelle.getX()-(marge_modif*((PORTE_VUE-proximite)/PORTE_VUE)));

		//cas ou le Voleur se dirige droit dans le mur (direction perpendiculaire)
		if(dirActuelle.getY()==this->getPosition().getY()){
			if(this->getPosition().getY()<0) dirResultat.setY(1.0-fabs(dirResultat.getX()));
			else dirResultat.setY(-1.0+fabs(dirResultat.getX()));
		}

		//cas ou il ne se dirige pas exactement droit dedans
		else{
			if(dirActuelle.getY()<0) dirResultat.setY(-1.0+fabs(dirResultat.getX()));
			else dirResultat.setY(1.0-fabs(dirResultat.getX()));
		}

	}

	//si on peut apercevoir le mur Sud et qu'on s'en approche
	if((this->getPosition().getY()<=-(TAILLE_TERRAIN-PORTE_VUE)) && (dirActuelle.getY()<=0)){

		//déclarations
		double proximite=TAILLE_TERRAIN+(this->getPosition().getY()+(dirActuelle.getY()*this->getSpeed()));
		double marge_modif=fabs(dirActuelle.getY())+1.0;

		//calcul du nouveau Y
		dirResultat.setY(dirActuelle.getY()+(marge_modif*((PORTE_VUE-proximite)/PORTE_VUE)));

		//cas ou le Voleur se dirige droit dans le mur (direction perpendiculaire)
		if(dirActuelle.getX()==this->getPosition().getX()){
			if(this->getPosition().getX()<0) dirResultat.setX(1.0-fabs(dirResultat.getY()));
			else dirResultat.setX(-1.0+fabs(dirResultat.getY()));
		}

		//cas ou il ne se dirige pas exactement droit dedans
		else{
			if(dirActuelle.getY()<0) dirResultat.setX(-1.0+fabs(dirResultat.getY()));
			else dirResultat.setX(1.0-fabs(dirResultat.getY()));
		}

	}

	//si on peut apercevoir le mur Nord et qu'on s'en approche
	else if((this->getPosition().getY()>=TAILLE_TERRAIN-PORTE_VUE) && (dirActuelle.getY()>=0)){

		//déclarations
		double proximite=TAILLE_TERRAIN-(this->getPosition().getY()+(dirActuelle.getY()*this->getSpeed()));
		double marge_modif=fabs(dirActuelle.getY())+1.0;

		//calcul du nouveau Y
		dirResultat.setY(dirActuelle.getY()-(marge_modif*((PORTE_VUE-proximite)/PORTE_VUE)));

		//cas ou le Voleur se dirige droit dans le mur (direction perpendiculaire)
		if(dirActuelle.getX()==this->getPosition().getX()){
			if(this->getPosition().getX()<0) dirResultat.setX(1.0-fabs(dirResultat.getY()));
			else dirResultat.setX(-1.0+fabs(dirResultat.getY()));
		}

		//cas ou il ne se dirige pas exactement droit dedans
		else{
			if(dirActuelle.getX()<0) dirResultat.setX(-1.0+fabs(dirResultat.getY()));
			else dirResultat.setX(1.0-fabs(dirResultat.getY()));
		}

	}

	return dirResultat;
}
