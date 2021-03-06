#include "Entites.hh"

unsigned int Entite::compteur(0);//compteur permettant d'attribuer des ID uniques.

/*************************************** IAs *******************************************/
/// déplace le Personnage à la position suivante, qu'il a au préalable calculé
void Joueur::Deplacement(){

	//on place le Personnage à sa nouvelle position
	this->setPosition(this->getDestination());
	this->setHitbox();

}
/// indique la Direction dans laquelle se trouve le Joueur indiqué en paramètre
Direction Joueur::Se_Rapprocher(Entite const & E){

	//déclarations
	double x,y;

	//traitement de X
	if (E.getPosition().getX()>this->getPosition().getX()) x=1;
	else if (E.getPosition().getX()<getPosition().getX()) x=-1;
	else x=0;

	//traitement de Y
	if (E.getPosition().getY()>this->getPosition().getY()) y=1;
	else if (E.getPosition().getY()<getPosition().getY()) y=-1;
	else y=0;

	//retourne la direction à emprunter
	return Direction(x,y);

}

/// indique la Direction opposée à celle où se trouve le Joueur indiqué en paramètre
Direction Joueur::Fuir(Entite const & E){

	//Pour fuir, on exécute l'action contraire à celle de se rapprocher
	Direction D = Se_Rapprocher(E);
	D.setX(-D.getX());
	D.setY(-D.getY());

	//retourne la diréction à emprunter
	return D;

}

/// indique au Joueur quel est le Gendarme le plus proche
Gendarme Joueur::Gendarme_Plus_Proche(std::vector<Gendarme*> liGen){

	//définition
	double distance = 1000;
	Gendarme G(Position(0,0),1.0,"G",Choix_Algo::random);

	//traitement pour chaque gendarme
	for (auto && i : liGen){

		//On récupére la distance du gendarme actuel, et la comparons à celle du plus proche connu.
		//Si elle lui est inférieure, le gendarme est donc le nouveau plus proche
		if (this->getDistance_From(*i)<distance and this->getDistance_From(*i)<PORTE_VUE){
			distance = this->getDistance_From(*i);
			G = *i;
		}//fin gendarme actuel
	}//fin liste gendarmes

	//fin
	return G;

}

/// indique au Gendarme quel est le Voleur le plus proche
Voleur Gendarme::Voleur_Plus_Proche(std::vector<Voleur*> liVol){

	//définitions
	double distance = 1000;
	Voleur V(Position(0,0),1.0,"V",Choix_Algo::random);

	//traitement pour chaque voleur
	for (auto && voleur : liVol){

		//On récupére la distance du voleur actuel, et la comparons à celle du plus proche connu.
		//Si elle lui est inférieure, le voleur est donc le nouveau plus proche
		if (this->getDistance_From(*voleur)<distance and this->getDistance_From(*voleur)<PORTE_VUE){
			distance = this->getDistance_From(*voleur);
			V = *voleur;
		}//fin voleur actuel
	}//fin liste voleurs

	//fin
	return V;
}

/******************************************* autre *******************************************/

/// redéfinition de l'operateur +, permettant ainsi d'additionner deux Positions
Position Position::operator+(Position const & pos){

	//retour du résultat de l'addition
	return Position(getX() + pos.getX(),getY() + pos.getY());

}

/// redéfinition de l'operateur *, permettant ainsi de multiplier une position par un double
Position Position::operator*(double mult){

	//retour du résultat de la multiplication
	return Position(getX()*mult,getY()*mult);

}

/// redéfinition de l'operateur ==, permettant ainsi de verifier si deux Positions sont identiques
bool Position::operator==(Position const & pos){

	//retour du résultat de la comparaison
	return (pos.getX()==x && pos.getY()==y);
}

/// Défini les dimension de la hitbox à partir de TAILLE_HITBOX
void Entite::setHitbox(){

	HB.setH(getPosition().getY()+(TAILLE_HITBOX/2));
	HB.setB(getPosition().getY()-(TAILLE_HITBOX/2));
	HB.setG(getPosition().getX()-(TAILLE_HITBOX/2));
	HB.setD(getPosition().getX()+(TAILLE_HITBOX/2));

}

/// Permet d'afficher la hitbox de l'Entite dans le terminal
std::string Entite::Affiche_Hitbox(){

	// "Hitbox: (G,D,H,B)"
	return "Hitbox:("
		+std::to_string(this->HB.getG())+","
		+std::to_string(this->HB.getD())+","
		+std::to_string(this->HB.getH())+","
		+std::to_string(this->HB.getB())+
	")";

}

/// constructeur d'un Entité permettant de définir la hitbox. On ne va cependant jamais instancier Entite, mais plutôt ses classes filles
Entite::Entite(Position const & pos):emplacement(pos),id(compteur++),HB(pos.getY()+(TAILLE_HITBOX/2),pos.getY()-(TAILLE_HITBOX/2),pos.getX()-(TAILLE_HITBOX/2),pos.getX()+(TAILLE_HITBOX/2)){

	//définition de la hitbox pour l'affichage
	item = new QGraphicsRectItem(0,0,(TAILLE_HITBOX),(TAILLE_HITBOX));
	item->setPos(pos.getX(),pos.getY());

}

/// Verifie si deux Entité sont en contact ou non
bool Entite::Hitbox_Touche(Entite &J2){

	return (
	(//cas ou l'entité est à droite de J2
			(this->getHitbox().getG()<=J2.getHitbox().getG() and this->getHitbox().getD()>=J2.getHitbox().getG())
			and ((this->getHitbox().getB()<=J2.getHitbox().getH() and this->getHitbox().getH()>=J2.getHitbox().getH())
				or ((this->getHitbox().getB()<=J2.getHitbox().getB() and this->getHitbox().getH()>=J2.getHitbox().getB())
				)
			)
	)//fin cas
		or
	(// cas ou l'entité est à gauche de J2
		(this->getHitbox().getG()<=J2.getHitbox().getD() and this->getHitbox().getD()>=J2.getHitbox().getD())
		and ((this->getHitbox().getB()<=J2.getHitbox().getH() and this->getHitbox().getH()>=J2.getHitbox().getH())
			or ((this->getHitbox().getB()<=J2.getHitbox().getB() and this->getHitbox().getH()>=J2.getHitbox().getB())
			)
		)
	)//fin cas
	);//fin return

}

/// retourne la distance entre l'instance actuelle et l'Entite prise en paramètre
double Entite::getDistance_From(Entite E){

	//retourne la racine carré de la difference des position
	return std::sqrt((
			//traitement X
			(E.getPosition().getX()-this->getPosition().getX())
			*(E.getPosition().getX()-this->getPosition().getX())
		)+(
			//traitement Y
			(E.getPosition().getY()-this->getPosition().getY())
			*(E.getPosition().getY()-this->getPosition().getY())
		)
	); // fin return

}
