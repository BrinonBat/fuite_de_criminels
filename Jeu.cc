#include "Jeu.hh"

void Jeu::init(int const & nb_gendarmes,int const & nb_voleurs){
	//ajout des gendarmes
	for(int i=0;i<nb_gendarmes;i++){
		/*ajouter la prise en compte du cas ou il y a beaucoup de gendarmes*/
		Position p=new Position(i,0,this.largeur,this.hauteur);
		std::string nom="gend"+itoa(i);
		ajoutGendarme(nom,p,Nord);
	}
	//ajout des voleurs
	for(int i=0;i<nb_voleurs;i++){
		/*ajouter la prise en compte du cas ou il y a beaucoup de voleurs*/
		Position p=new Position((this.largeur)/2,(this.hauteur-i),this.largeur,this.hauteur);
		std::string nom="vol"+itoa(i);
		ajoutVoleur(nom,p,Nord);
	}
}

void Jeu::ajoutGendarme(std::string const & nom,Position const & p,Cardinal const & dir){
	liPersos.push_back(new Gendarme(nom,p,dir));
}

void Jeu::ajoutVoleur(std::string const & nom,Position const & p,Cardinal const & dir){
	liPersos.push_back(new Voleur(nom,p,dir));
}
