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

		void ajoutVoleur(std::string const & nom,Position const & p,Cardinal const & dir);
		void ajoutGendarme(std::string const & nom,Position const & p,Cardinal const & dir);
		void supprimeVoleur(Position const & p);
		void supprimeGendarme(Position const & p);

	private:
		int largeur;
		int hauteur;
		Personnage <std::vector> liPersos;

}
