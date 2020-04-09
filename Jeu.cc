#include "Jeu.hh"

void Jeu::init(int const & nb_gendarmes,int const & nb_voleurs){
	//ajout des gendarmes
	for(int i=0;i<nb_gendarmes;i++){
		Position p=new Position(i,0,this.largeur,this.hauteur);
		std::string name="gend"+itoa(i);

	}
	//ajout des voleurs
}
