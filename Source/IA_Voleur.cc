#include "Jeu.hh"

/// calcule la prochaine destination du voleur en fonction de l'IA choisie
void Jeu::Calcule_Deplacement(Voleur &V){

	//définitions
	Direction result(0,0);
	//constantes correspondant à l'importance de chaque action
	const int IMP_FUITE_GENDARME(6);
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

	//on ramene X et Y à des valeurs variant de -1 à 1 en effectuant le calcule suivant:
		//x=x/(|x|+|y|)   et de même pour y
	Direction dir=Direction(0,0);
	if(abs(result.getX())+abs(result.getY())!=0){
		dir.setX(result.getX()/(abs(result.getX())+abs(result.getY())));
		dir.setY(result.getY()/(abs(result.getX())+abs(result.getY())));
	}

	std::cout<<"PING dir Initiale est "+std::to_string(dir.getX())+","+std::to_string(dir.getY())<<std::endl;
	// on évite les murs
	dir=V.Evite_Murs(dir);

	std::cout<<"PING dir fin est "+std::to_string(dir.getX())+","+std::to_string(dir.getY())<<std::endl;

	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=dir*V.getSpeed();

	std::cout<<"PING result fin est "+std::to_string(result.getX())+","+std::to_string(result.getY())<<std::endl;
	std::cout<<"PING destination fin est "+std::to_string(V.getPosition().getX()+result.getX())+","+std::to_string(V.getPosition().getY()+result.getY())<<std::endl;
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
			else dirResultat.setY(-1.0+fabs(dirResultat.getX())); // si le Voleur est vers le haut du terrain, il fuit vers la partie basse
		}

		//cas ou il ne se dirige pas exactement droit dedans
		else{
			if(dirActuelle.getY()<0) dirResultat.setY(-1.0+fabs(dirResultat.getX())); // si le Voleur se dirigeais vers le bas du terrain, il fuit vers le bas
			else dirResultat.setY(1.0-fabs(dirResultat.getX())); // si le Voleur se dirigeais vers le haut du terrain, il fuit vers le haut
		}

	}

	//si on peut apercevoir le mur Est
	else if(this->getPosition().getX()>=TAILLE_TERRAIN-PORTE_VUE){
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

	//si on peut apercevoir le mur Sud
	if(this->getPosition().getY()<=-(TAILLE_TERRAIN-PORTE_VUE)){
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
			if(dirActuelle.getX()<0) dirResultat.setX(-1.0+fabs(dirResultat.getY()));
			else dirResultat.setX(1.0-fabs(dirResultat.getY()));
		}
	}

	//si on peut apercevoir le mur Nord
	else if(this->getPosition().getY()>=TAILLE_TERRAIN-PORTE_VUE){

		//déclarations
		double proximite=TAILLE_TERRAIN-(this->getPosition().getY()+(dirActuelle.getY()*this->getSpeed()));
		double marge_modif=fabs(dirActuelle.getY())+1.0;

		//calcul du nouveau Y
		dirResultat.setX(dirActuelle.getY()-(marge_modif*((PORTE_VUE-proximite)/PORTE_VUE)));

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

	std::cout<<"PING resultat est "+std::to_string(dirResultat.getX())+","+std::to_string(dirResultat.getY())<<std::endl;
	return dirResultat;
}
