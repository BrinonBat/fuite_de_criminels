#include "Jeu.hh"
/// calcule la prochaine destination du gendarme en fonction de l'IA choisie
void Jeu::Calcule_Deplacement(Gendarme &G){

	//définition
	Direction result(0,0);

	//calcul du déplacement à réaliser en fonction de l'algorithme séléctionné
	switch (G.getAlgo()){

	/////IA RANDOM/////
		//cas de l'algo retournant des déplacements aléatoires
		case Choix_Algo::random:{
			result = Direction(fRand(-3,3),fRand(-3,3));
		}break;

	/////IA CHASSE/////
		//cas de l'algo déplacant le gendarme vers le voleur le plus proche
		case Choix_Algo::gendarmes_chasseurs:{
			Voleur V = G.Voleur_Plus_Proche(getListeVoleurs());
			result = G.Se_Rapprocher(V);
		}break;

	/////IA FACILE/////
		case Choix_Algo::IA_Facile:{

			//Repère un voleur
			Voleur V = G.Voleur_Plus_Proche(getListeVoleurs());
			if (G.getDistance_From(V)<=PORTE_VUE){
				result = result+G.Se_Rapprocher(V);
			}
			else { // sinon,on va vers la sorie pour guetter
				NonJoueur S = G.Sortie_Plus_Proche(getListeNonJoueurs());
				// se rapproche de la sortie si on est loin
				if (G.getDistance_From(S)>PORTE_VUE){ // IA_facile, il ne guette que du côté où il se trouve
					result = result+G.Se_Rapprocher(S);
				} // sinon, il reste à côté de la sortie en tant que guet

			}

		}break;

	/////IA MOYEN/////
		case Choix_Algo::IA_Moyen:{

			//Repère un (ou plusieurs) voleur
			for(auto &&V : getListeVoleurs()){

				//on traite tous les voleurs qu'on aperçoit
				if (G.getDistance_From(*V)<=PORTE_VUE){

					//par défaut, il faut poursuivre le voleur
					bool deja_poursuivi(false);

					//on verifie si un camarade poursuit déjà le Voleur de façon plus efficace
					for(auto &&camarade : getListeGendarmes()){
						if((G.getDistance_From(*V)>camarade->getDistance_From(*V))&&(G.getDistance_From(*V)>G.getDistance_From(*camarade))) deja_poursuivi=true;
					}

					//si ce n'est pas le cas, on se lance à la poursuite du Voleur
					if(!deja_poursuivi){
						result = result+G.Se_Rapprocher(*V);
						break;
					}

				}
			}

			 // sinon,on surveille une sortie
			if(result==Direction(0,0)){

				//on verifie si la sortie la plus proche de nous doit être surveillée
				NonJoueur S = G.Sortie_Plus_Proche(getListeNonJoueurs());

/*				//si on garde actuellement la sortie la plus proche, on ne bouge pas.
				if(G.getDistance_From(S)>=PORTE_VUE/3){
*/
					bool est_garde(false);
					// se rapproche de la sortie la plus proche qui n'est pas gardée
					for(auto &&camarade : getListeGendarmes()){
						if((camarade->getDistance_From(S)<=PORTE_VUE/3)&&(G.getDistance_From(S)>=G.getDistance_From(*camarade))){
							est_garde=true;
							break;
						}
					}

					//si la sortie la plus proche est gardée, on vérifie s'il existe une autre sortie à garder
					if(est_garde){
						for(auto &&autre_sortie:getListeNonJoueurs()){

							//parcours de la liste de sorties
							if(autre_sortie->getType()==Type::sortie){
								bool est_garde(false);

								//verification de si la sortie est gardée par un camarade
								for(auto &&camarade : getListeGendarmes()){
									if((camarade->getDistance_From(*autre_sortie)<=PORTE_VUE/3)&&(G.getDistance_From(*autre_sortie)>=G.getDistance_From(*camarade))){
										 est_garde=true;
										 break;
									 }
								}
								//si la sortie n'est pas gardée, alors c'est elle qu'on choisit
								if(!est_garde){
									S=*autre_sortie;
									break;
								}
							}
						}
					}

					//si la sortie choisie est trop loin, on s'en approche
					if(G.getDistance_From(S)>PORTE_VUE/3){ // divisé par 3 pour avoir 2/3 de champ de vision de marge de l'autre côté de la Sortie
						result = result+G.Se_Rapprocher(S);
					}
/*				}
*/			}

			// Sortie déja protégé -> Cherche position optimale, fonctionnalité de l'IA "Difficile"
		}break;
	}

	//on ramene X et Y à des valeurs variant de -1 à 1 en effectuant le calcule suivant:
		//x=x/(|x|+|y|)   et de même pour y
	Direction dir=Direction(0,0);
	if(fabs(result.getX())+fabs(result.getY())!=0){
		dir.setX(result.getX()/(fabs(result.getX())+fabs(result.getY())));
		dir.setY(result.getY()/(fabs(result.getX())+fabs(result.getY())));
	}

	//on ajoute la vitesse à la direction pour obtenir le vecteur à appliquer au personnage
	result=dir*G.getSpeed();

	//affichage dans le termine pour visualisation
	std::cout<<"PING G("+std::to_string(G.getPosition().getX())+","+std::to_string(G.getPosition().getY())+ // "PING G(x,y)"
	") + ("+std::to_string(result.getX())+","+std::to_string(result.getY())+ // " + (x,y)"
	") ---> ("+std::to_string(G.getPosition().getX()+result.getX())+","+std::to_string(G.getPosition().getY()+result.getY())+ // "---> (x,y)"
	") déplacement total:" +std::to_string(fabs(result.getX())+fabs(result.getY()))<<std::endl;// "déplacement total : x+y"

	//enregistrement du résultat comme étant la prochaine destination du gendarme
	G.setDestination(G.getPosition()+result);

}
