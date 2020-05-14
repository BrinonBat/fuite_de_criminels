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
    }
}

void Fenetre_Ajout::Exemple1(){
	// Exemple 1 : Par défaut
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
	// Exemple2 Grosse Partie
	Fenetre_Game->show();

	//creation des entités
	NonJoueur Sortie(Position(0,0),Type::sortie);
	Voleur V1(Position(-150,-150),1.0,"V1",Choix_Algo::IA_Facile);
	Voleur V2(Position(38,30),0.5,"V2",Choix_Algo::IA_Facile);
	Gendarme G1(Position(-148,300),2.0,"G1",Choix_Algo::IA_Facile);
	Gendarme G2(Position(6,9),2.0,"G2",Choix_Algo::IA_Facile);

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
		// Exemple3
	Fenetre_Game->show();

	//creation des entités
	NonJoueur Sortie(Position(38,38),Type::sortie);
	Voleur V1(Position(-150,-150),1.0,"V1",Choix_Algo::IA_Facile);
	Voleur V2(Position(38,30),0.5,"V2",Choix_Algo::IA_Facile);
	Gendarme G1(Position(-148,300),2.0,"G1",Choix_Algo::IA_Facile);
	Gendarme G2(Position(6,9),2.0,"G2",Choix_Algo::IA_Facile);

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
