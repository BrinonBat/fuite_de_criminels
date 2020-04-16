#include "Entites.hh"

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
