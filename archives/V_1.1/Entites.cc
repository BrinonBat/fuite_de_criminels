#include "Entites.hh"

unsigned int Entite::compteur(0);
/************************** IAs **************************/
void Voleur::Joue_Deplacement(){
	//calcul du déplacement à réaliser
	Direction result(0,1);
	//enregistrement de celui-ci
	result=result*getSpeed();
	setDestination(getPosition()+result);
}
void Gendarme::Joue_Deplacement(){
	//calcul du déplacement à réaliser
	Direction result(0,-1);
	//enregistrement de celui-ci
	result=result*getSpeed();
	setDestination(getPosition()+result);
}
/************************* autre *************************/
Entite::Entite(Position const & pos):emplacement(pos),id(compteur++){}

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
