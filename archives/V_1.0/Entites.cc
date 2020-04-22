#include "Entites.hh"

unsigned int Entite::compteur(0);
/************************** IAs **************************/
Direction Voleur::Joue_Deplacement(){
	return Direction(0,1);
}
Direction Gendarme::Joue_Deplacement(){
	return Direction(0,-1);
}
/************************* autre *************************/
Entite::Entite(Position const & pos):emplacement(pos),id(compteur++){}

Position Position::operator+(Position const & p){
	return Position(getX() + p.getX(),getY() + p.getY());
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
