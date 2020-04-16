#include "Entites.hh"

Direction Voleur::jouer() {
	return Direction(3.2,3.1);
}

Direction Gendarme::jouer() {
	return Direction(3.2,3.1);
}

void afficherValeur(type e)
{
    switch (e) {
    case type::cachette:
        std::cout<<"C";
        break;
    case type::sortie:
        std::cout<<"S";
        break;
    }
}
