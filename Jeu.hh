#include <vector>
#include "Personnage.hh"

class Jeu{
	public:
		//constructeur
		Jeu(int const & larg,int const & haut):
			largeur(larg),hauteur(haut){};

		//accesseurs
		int getLargeur() {return largeur;}
		int getHauteur() {return hauteur;}

		//méthodes
		void init(int const & nb_gendarmes,int const & nb_voleurs);

		void ajoutVoleur(Position p,Cardinal dir);
		void ajoutGendarme(Position p,Cardinal dir);
		void supprimeVoleur(Position p);
		void supprimeGendarme(Position p);

	private:
		int largeur;
		int hauteur;
		Personnage <std::vector> liPersos;

}
