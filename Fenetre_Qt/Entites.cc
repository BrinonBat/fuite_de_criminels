#include "Entites.hh"




unsigned int Entite::compteur(0);
/************************** IAs **************************/
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

Direction Joueur::Se_Rapprocher(Joueur & J)
{
	double x,y;

	if (J.getPosition().getX()>this->getPosition().getX())
	{
		x=1;
	}
	else if (J.getPosition().getX()<getPosition().getX())
	{
		x=-1;
	}
	else {
		x=0;
	}

	if (J.getPosition().getY()>this->getPosition().getY())
	{
		y=1;
	}
	else if (J.getPosition().getY()<getPosition().getY())
	{
		y=-1;
	}
	else {
		y=0;
	}

	return Direction(x,y);
}

Direction Joueur::Fuir(Joueur & J)
{
	Direction D = Se_Rapprocher(J);
	D.setX(-D.getX());
	D.setY(-D.getY());

	return D;
}

Voleur Gendarme::Voleur_Plus_Proche(std::vector<Voleur*> Liste)
{
	double distance = 1000;
	Voleur V(Position(0,0),1.0,"V",Choix_Algo::random);

	for (auto && i : Liste)
	{
		// (this->getDistance_From(*i)<distance and this->getDistance_From(*i)<50) -> pour donner un champs de vision 
		if (this->getDistance_From(*i)<distance)
		{
			distance = this->getDistance_From(*i);
			V = *i;	
		}
	}
	return V;
}


Gendarme Voleur::Gendarme_Plus_Proche(std::vector<Gendarme*> Liste)
{
	double distance = 1000;
	Gendarme G(Position(0,0),1.0,"G",Choix_Algo::random);

	for (auto && i : Liste)
	{
		// (this->getDistance_From(*i)<distance and this->getDistance_From(*i)<50) -> pour donner un champs de vision 
		if (this->getDistance_From(*i)<distance and this->getDistance_From(*i)<20)
		{
			distance = this->getDistance_From(*i);
			G = *i;	
		}
	}
	return G;
}


/************************* autre *************************/

Entite::Entite(Position const & pos):emplacement(pos),id(compteur++),HB(pos.getY()+(TAILLE_HITBOX/2),pos.getY()-(TAILLE_HITBOX/2),pos.getX()-(TAILLE_HITBOX/2),pos.getX()+(TAILLE_HITBOX/2)){
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
