#include "Jeu.hh"

int main(){
	//initialisation
	Jeu Test(40,40);

	//creation des entités
	NonJoueur Sortie(Position(38,38),Type::sortie);
	Voleur V1(Position(7,5),0.8,"V1");
	Voleur V2(Position(38,36),0.8,"V2");
	Gendarme G1(Position(7,6),0.8,"G1");
	Gendarme G2(Position(6,8),1.0,"G2");

	//ajout des entités au Jeu
	Test.ajouter_joueur(V1);
	Test.ajouter_joueur(G1);
	Test.ajouter_joueur(V2);
	Test.ajouter_joueur(G2);
	Test.ajouter_nonJoueur(Sortie);

	Test.afficher();

	//tests verifiant une bonne initialisation:
	std::cout<<"test nbVoleurs résultat attendu: 2 -->"<<Test.getNbVoleurs()<<std::endl;
	std::cout<<"test nbCaptures résultat attendu: 0 -->"<<Test.getNbCaptures()<<std::endl;
	Test.deplacement(V2,V2.Joue_Deplacement());
	std::cout<<"test déplacement résultat attendu: (38,37) -->"<<V2.Affiche_Position()<<std::endl;
	//Test.Jouer_tour(); //!\ SEGFAULT
	Test.deplacement(V2,V2.Joue_Deplacement());// SEGFAULT AUSSI
	//std::cout<<"test nbCaptures résultat attendu: 1 -->"<<Test.getNbCaptures()<<std::endl;

	Test.afficher();
	Test.deplacement(G1,G1.Joue_Deplacement());
	Test.afficher();

}
