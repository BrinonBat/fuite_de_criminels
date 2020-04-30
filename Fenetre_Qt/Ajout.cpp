#include <iostream>
#include "Fenetre_Ajout.hh"
#include "Jeu.hh"

using namespace std;

int main(int argc, char *argv[])
{

	// Jeu Test(40,40);

	// //creation des entités
	// NonJoueur Sortie(Position(38,38),Type::sortie);
	// Voleur V1(Position(7,0),1.0,"V1");
	// Voleur V2(Position(38,30),0.5,"V2");
	// Gendarme G1(Position(7,6),2.0,"G1");
	// Gendarme G2(Position(6,9),2.0,"G2");

	// //ajout des entités au Jeu
	// Test.ajouter_voleur(V1);
	// Test.ajouter_gendarme(G1);
	// Test.ajouter_voleur(V2);
	// Test.ajouter_gendarme(G2);
	// Test.ajouter_nonJoueur(Sortie);


	// std::cout<<"Etat Initial"<<std::endl;
	// Test.afficher();
	// std::cout<<"\n EXEMPLE_EXECUTION : \n ";

	// // Partie
	// for(unsigned int nb_tour=1;!Test.estFini();nb_tour++){
	// 	std::cout<<"\n TOUR "<<nb_tour<<" : \n";
	// 	Test.Jouer_tour();
	// 	Test.afficher();
	// }

	// // Partie
	// for(unsigned int nb_tour=1;nb_tour!=10;nb_tour++){
	// 	std::cout<<"\n TOUR "<<nb_tour<<" : \n";
	// 	Test.Jouer_tour();
	// 	Test.afficher();
		
	// }
	// std::cout<<"test nbCaptures résultat attendu: 1 -->"<<Test.getNbCaptures()<<std::endl;

	//*********************************** 
	 std::srand(std::time(NULL));
    QApplication app(argc,argv);
    Fenetre_Ajout F;
    F.show();
   return app.exec();
}


