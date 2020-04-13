#include <iostream>
#include <string>
#include "Jeu.hh"



int main()
{

	// Ajout GRILLE
	Grille Test(20,20);
	// Ajout JOUEURS
	Voleur Voleur1("Voleur1",type::voleur,Position(6,5),0);
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";
	Gendarme Gendarme1("Gendarme1",type::gendarme,Position(10,5),1);
	std::cout<<"Gendarme1:"<<Gendarme1.Affiche_Position()<<"\n";	

	// Ajout JOUEURS sur GRILLE
	Test.ajouter_joueur(Voleur1);
	Test.ajouter_joueur(Gendarme1);

	// Ajout SORTIE
	Test.ajouter_sortie(Position(18,18));
	Test.ajouter_sortie(Position(13,13));


	// AFFICHAGE
	std::cout<<"-------------\n";
	Test.afficher();
	std::cout<<"-------------\n";
	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";
	std::cout<<"Voleur1:"<<Test.Liste_Joueur.at(0).Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";

	Test.deplacement(Voleur1,Direction::Droite);
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";



}