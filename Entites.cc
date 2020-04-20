#include "Entites.hh"

unsigned int Entite::compteur(0);

Entite::Entite(Position const & pos):emplacement(pos),id(compteur++){}

Position Position::operator+(Position const & p){
	return Position(getX() + p.getX(),getY() + p.getY());
}


Direction Voleur::jouer() {
	return Direction(3.2,3.1);
}

Direction Gendarme::jouer() {
	return Direction(3.2,3.1);
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
