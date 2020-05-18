#include "Fenetre_Ajout.hh"

void Fenetre_Ajout::Choix_Exemple(){
	switch (_ChoixExemple->currentIndex()){
        case 0:
            Exemple1();
            break;

        case 1:
            Exemple2();
            break;

        case 2:
        	Exemple3();
        	break;

		case 3:
			Exemple4();
			break;

		case 4:
			Exemple5();
			break;
    }
}

void Fenetre_Ajout::Exemple1(){
	// Exemple 1 : aléatoire
	Fenetre_Game->show();

	//creation des entités
	NonJoueur Sortie(Position(38,38),Type::sortie);
	Voleur V1(Position(-150,-150),1.0,"V1",Choix_Algo::random);
	Voleur V2(Position(38,30),0.5,"V2",Choix_Algo::random);
	Gendarme G1(Position(-148,300),2.0,"G1",Choix_Algo::random);
	Gendarme G2(Position(6,9),2.0,"G2",Choix_Algo::random);

	// ajout des entités au Jeu
	Game->ajouter_Voleur(V1);
	Game->ajouter_Gendarme(G1);
	Game->ajouter_Voleur(V2);
	Game->ajouter_Gendarme(G2);
	Game->ajouter_nonJoueur(Sortie);

	// Configuration et Lancement d'une partie
	Configuration_Partie();
	Jouer_Partie();
}

void Fenetre_Ajout::Exemple2(){
	// Exemple2 : éviter les murs
	Fenetre_Game->show();

	//creation des entités
	NonJoueur Sortie(Position(0,0),Type::sortie);
	Voleur V1(Position(-150,0),2.0,"V1",Choix_Algo::IA_Facile);
	Gendarme G1(Position(-130,0),2.0,"G1",Choix_Algo::IA_Facile);
	Voleur V2(Position(245,0),2.0,"V2",Choix_Algo::IA_Facile);
	Gendarme G2(Position(230,0),2.0,"G2",Choix_Algo::IA_Facile);

	// ajout des entités au Jeu
	Game->ajouter_Voleur(V1);
	Game->ajouter_Gendarme(G1);
	Game->ajouter_Voleur(V2);
	Game->ajouter_Gendarme(G2);
	Game->ajouter_nonJoueur(Sortie);

	// Configuration et Lancement d'une partie
	Configuration_Partie();
	Jouer_Partie();
}


void Fenetre_Ajout::Exemple3(){
	// Exemple3 : sortie contre le mur, gendarme garde la sortie
	Fenetre_Game->show();

	//creation des entités
	NonJoueur Sortie(Position(200,299),Type::sortie);
	Voleur V1(Position(100,150),3.0,"V1",Choix_Algo::IA_Facile);
	Voleur V2(Position(38,30),3.0,"V2",Choix_Algo::IA_Facile);
	Gendarme G1(Position(100,100),3.0,"G1",Choix_Algo::IA_Facile);
	Gendarme G2(Position(6,9),3.0,"G2",Choix_Algo::IA_Facile);

	// ajout des entités au Jeu
	Game->ajouter_Voleur(V1);
	Game->ajouter_Gendarme(G1);
	Game->ajouter_Voleur(V2);
	Game->ajouter_Gendarme(G2);
	Game->ajouter_nonJoueur(Sortie);

	// Configuration et Lancement d'une partie
	Configuration_Partie();
	Jouer_Partie();

}

void Fenetre_Ajout::Exemple4(){
	// Exemple4 : Voleur cerné
	Fenetre_Game->show();

	//creation des entités
	NonJoueur Sortie(Position(0,0),Type::sortie);
	Voleur V1(Position(150,0),2.0,"V1",Choix_Algo::IA_Moyen);
	Gendarme G1(Position(200,0),2.0,"G1",Choix_Algo::IA_Facile);
	Gendarme G2(Position(40,0),2.0,"G2",Choix_Algo::IA_Facile);
	Gendarme G3(Position(10,-10),2.0,"G3",Choix_Algo::IA_Facile);

	// ajout des entités au Jeu
	Game->ajouter_Voleur(V1);
	Game->ajouter_Gendarme(G1);
	Game->ajouter_Gendarme(G2);
	Game->ajouter_Gendarme(G3);
	Game->ajouter_nonJoueur(Sortie);

	// Configuration et Lancement d'une partie
	Configuration_Partie();
	Jouer_Partie();

}

void Fenetre_Ajout::Exemple5(){
	// Exemple5 : grosse partie
	Fenetre_Game->show();

	// Configuration et Lancement d'une partie
	Configuration_Partie();
	Jouer_Partie();
}
