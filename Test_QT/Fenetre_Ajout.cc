#include "Fenetre_Ajout.hh"
#include <string>

Fenetre_Ajout::Fenetre_Ajout()
	:QWidget() {
		resize(500,400);

	// Ajout de Joueurs
	_Intro = new QLabel("	Veuillez choisir un type de joueurs, son nom, sa position :\n 	(Nom attaché de préférence comme G1,G2 ..)",this);

	_ChoixJoueur = new QComboBox(this);
	_ChoixJoueur->addItem("Voleur",1);
	_ChoixJoueur->addItem("Gendarme",2);
	_ChoixJoueur->setGeometry(0,40,100,20);

	_NomJoueur = new QLineEdit("Nom Joueur",this);
	_NomJoueur->setGeometry(100,40,100,20);

	_PositionX = new QLineEdit("Position X",this);
	_PositionX->setGeometry(200,40,100,20);
	_PositionY = new QLineEdit("Position Y",this);
	_PositionY->setGeometry(300,40,100,20);

	_Ajouter = new QPushButton("Ajouter",this);
	_Ajouter->setGeometry(400,40,60,20);

	// Ajout des "autres" paramètres
	_Intro2 = new QLabel("	Veuillez choisir un type(Sortie,Cachette),sa position :\n ",this);
	_Intro2->move(0,65);

	_AutreChoix = new QComboBox(this);
	_AutreChoix->addItem("Sortie",1);
	_AutreChoix->addItem("Cachette",2);
	_AutreChoix->setGeometry(0,100,100,20);

	_PositionX2 = new QLineEdit("Position X",this);
	_PositionX2->setGeometry(100,100,100,20);
	_PositionY2 = new QLineEdit("Position Y",this);
	_PositionY2->setGeometry(200,100,100,20);

	_Ajouter2 = new QPushButton("Ajouter",this);
	_Ajouter2->setGeometry(300,100,60,20);
	
	// Lancement de partie
	_Lancer = new QPushButton("Lancer la partie!",this);
	_Lancer->setGeometry(150,150,150,50);


	// Partie configuré - exemple (3)
	_Intro3 = new QLabel("	Sinon vous pouvez lancer une partie avec\n\t3 exemples déja configuré :\n ",this);
	_Intro3->move(0,220);

	_ChoixExemple = new QComboBox(this);
	_ChoixExemple->addItem("Exemple1",1);
	_ChoixExemple->addItem("Exemple2",2);
	_ChoixExemple->addItem("Exemple3",3);
	_ChoixExemple->setGeometry(0,280,100,20);

	_Lancer2 = new QPushButton("Lancer la partie!",this);
	_Lancer2->setGeometry(100,280,150,20);

	}