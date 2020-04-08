#include "Personnage.hh"
#include "Jeu.hh"

int main(int argc,char * argv[]){
	//paramètrage
	int hauteur=20;
	int largeur=20;
	int nb_gendarmes = 4;
	int nb_voleurs = 3;

	//initialisation
	Jeu game=new Jeu(largeur,hauteur);
	game.init(nb_gendarmes,nb_voleurs);

}
