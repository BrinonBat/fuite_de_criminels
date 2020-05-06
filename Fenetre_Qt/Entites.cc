#include "Entites.hh"

unsigned int Entite::compteur(0);//compteur permettant d'attribuer des ID uniques.

/*************************************** IAs *******************************************/

void Entite::setHitbox(){

	HB.setH(getPosition().getY()+(TAILLE_HITBOX/2));
	HB.setB(getPosition().getY()-(TAILLE_HITBOX/2));
	HB.setG(getPosition().getX()-(TAILLE_HITBOX/2));
	HB.setD(getPosition().getX()+(TAILLE_HITBOX/2));

}

std::string Entite::Affiche_Hitbox(){

	// "Hitbox: (G,D,H,B)"
	return "Hitbox:("
		+std::to_string(this->HB.getG())+","
		+std::to_string(this->HB.getD())+","
		+std::to_string(this->HB.getH())+","
		+std::to_string(this->HB.getB())+
	")";

}

void Voleur::deplacement(){

	//calcul de la nouvelle position
	this->setPosition(this->getDestination());
	this->setHitbox();

}

void Gendarme::deplacement(){

	//calcul de la nouvelle position
	this->setPosition(this->getDestination());
	this->setHitbox();

}

Direction Joueur::Se_Rapprocher(Joueur & J){

	//déclarations
	double x,y;

	//traitement de X
	if (J.getPosition().getX()>this->getPosition().getX()) x=1;
	else if (J.getPosition().getX()<getPosition().getX()) x=-1;
	else x=0;

	//traitement de Y
	if (J.getPosition().getY()>this->getPosition().getY()) y=1;
	else if (J.getPosition().getY()<getPosition().getY()) y=-1;
	else y=0;

	//retourne la direction à emprunter
	return Direction(x,y);

}

Direction Joueur::Fuir(Joueur & J){

	//Pour fuir, on exécute l'action contraire à celle de se rapprocher
	Direction D = Se_Rapprocher(J);
	D.setX(-D.getX());
	D.setY(-D.getY());

	//retourne la diréction à emprunter
	return D;

}

Voleur Gendarme::Voleur_Plus_Proche(std::vector<Voleur*> Liste){

	//définitions
	double distance = 1000;
	Voleur V(Position(0,0),1.0,"V",Choix_Algo::random);

	//traitement pour chaque voleur
	for (auto && voleur : Liste){

		//On récupére la distance du voleur actuel, et la comparons à celle du plus proche connu.
		//Si elle lui est inférieure, le voleur est donc le nouveau plus proche
		if (this->getDistance_From(*voleur)<distance /*and this->getDistance_From(*i)<50*/){
			distance = this->getDistance_From(*voleur);
			V = *voleur;
		}//fin voleur actuel
	}//fin liste voleurs

	//fin
	return V;
}


Gendarme Voleur::Gendarme_Plus_Proche(std::vector<Gendarme*> Liste){

	//définition
	double distance = 1000;
	Gendarme G(Position(0,0),1.0,"G",Choix_Algo::random);

	//traitement pour chaque gendarme
	for (auto && i : Liste){

		//On récupére la distance du gendarme actuel, et la comparons à celle du plus proche connu.
		//Si elle lui est inférieure, le gendarme est donc le nouveau plus proche
		if (this->getDistance_From(*i)<distance and this->getDistance_From(*i)<20){
			distance = this->getDistance_From(*i);
			G = *i;
		}//fin gendarme actuel
	}//fin liste gendarmes

	//fin
	return G;

}


/******************************************* autre *******************************************/

Entite::Entite(Position const & pos):emplacement(pos),id(compteur++),HB(pos.getY()+(TAILLE_HITBOX/2),
		pos.getY()-(TAILLE_HITBOX/2),
		pos.getX()-(TAILLE_HITBOX/2),
		pos.getX()+(TAILLE_HITBOX/2))
{
	item = new QGraphicsRectItem(0,0,(TAILLE_HITBOX),(TAILLE_HITBOX));
	item->setPos(pos.getX(),pos.getY());
}

bool Entite::Hitbox_touche(Entite &J2)
{
	return (
	((this->getHitbox().getG()<=J2.getHitbox().getG() and this->getHitbox().getD()>=J2.getHitbox().getG()) && ((this->getHitbox().getB()<=J2.getHitbox().getH() and this->getHitbox().getH()>=J2.getHitbox().getH()) or ((this->getHitbox().getB()<=J2.getHitbox().getB() and this->getHitbox().getH()>=J2.getHitbox().getB()))))
	or (
	(this->getHitbox().getG()<=J2.getHitbox().getD() and this->getHitbox().getD()>=J2.getHitbox().getD()) && ((this->getHitbox().getB()<=J2.getHitbox().getH() and this->getHitbox().getH()>=J2.getHitbox().getH()) or ((this->getHitbox().getB()<=J2.getHitbox().getB() and this->getHitbox().getH()>=J2.getHitbox().getB()))))
	);
}

double Entite::getDistance_From(Entite E)
{
	return std::sqrt((((E.getPosition().getX()-this->getPosition().getX())*(E.getPosition().getX()-this->getPosition().getX()))+((E.getPosition().getY()-this->getPosition().getY())*(E.getPosition().getY()-this->getPosition().getY()))));
}


Position Position::operator+(Position const & p){
	return Position(getX() + p.getX(),getY() + p.getY());
}
Position Position::operator*(double mult){
	return Position(getX()*mult,getY()*mult);
}
bool Position::operator==(Position const & p){
	return (p.getX()==x && p.getY()==y);
}
void afficherValeur(Type e)
{
    switch (e) {
    case Type::cachette:
        std::cout<<"C";
        break;
    case Type::sortie:
        std::cout<<"S";
        break;
    }
}
