#include "Fenetre_Ajout.hh"

/// Constructeur d'une fenetre qui permet d'ajouter des joueurs/sorties avec différents paramètres
Fenetre_Ajout::Fenetre_Ajout()
	:QWidget() {
		resize(620,600);

	// Ajout de Joueurs
	_Intro = new QLabel("	Veuillez choisir un type de joueurs, son nom, sa position et son algo:\n 	(Nom attaché de préférence comme G1,G2 ..)",this);

	_ChoixJoueur = new QComboBox(this);
	_ChoixJoueur->addItem("Voleur",0);
	_ChoixJoueur->addItem("Gendarme",1);
	_ChoixJoueur->setGeometry(0,40,100,20);

	_NomJoueur = new QLineEdit("Nom Joueur",this);
	_NomJoueur->setGeometry(100,40,100,20);

	_PositionX = new QLineEdit("Position X",this);
	_PositionX->setGeometry(200,40,100,20);
	_PositionY = new QLineEdit("Position Y",this);
	_PositionY->setGeometry(300,40,100,20);

	_ChoixAlgo = new QComboBox(this);
	_ChoixAlgo->addItem("Random",0);
	_ChoixAlgo->addItem("Vers le haut!",1);
	_ChoixAlgo->addItem("Vers le bas!",2);
	_ChoixAlgo->addItem("Gendarme Chasseur",3);
	_ChoixAlgo->addItem("IA Facile",4);
	_ChoixAlgo->setGeometry(400,40,140,20);

	_Ajouter = new QPushButton("Ajouter",this);
	_Ajouter->setGeometry(540,40,60,20);
	connect(_Ajouter,SIGNAL(released()),this,SLOT(Ajouter_Joueur()));

	// Ajout des "autres" paramètres
	_Intro2 = new QLabel("	Veuillez choisir un type(Sortie,Cachette),sa position :\n ",this);
	_Intro2->move(0,65);

	_AutreChoix = new QComboBox(this);
	_AutreChoix->addItem("Sortie",0);
	_AutreChoix->addItem("Cachette",1);
	_AutreChoix->setGeometry(0,100,100,20);

	_PositionX2 = new QLineEdit("Position X",this);
	_PositionX2->setGeometry(100,100,100,20);
	_PositionY2 = new QLineEdit("Position Y",this);
	_PositionY2->setGeometry(200,100,100,20);

	_Ajouter2 = new QPushButton("Ajouter",this);
	_Ajouter2->setGeometry(300,100,60,20);
	connect(_Ajouter2,SIGNAL(released()),this,SLOT(Ajouter_NonJoueur()));

	// Lancement de partie
	_Lancer = new QPushButton("Lancer la partie!",this);
	_Lancer->setGeometry(150,150,150,50);
	connect(_Lancer,SIGNAL(released()),this,SLOT(Lancer_Partie()));

	_Apercu = new QPushButton("Apercu",this);
	_Apercu->setGeometry(300,150,150,50);
	connect(_Apercu,SIGNAL(released()),this,SLOT(Apercu()));

	_FinPartie = new QPushButton("Fin Partie",this);
	_FinPartie->setGeometry(450,150,150,50);
	connect(_FinPartie,SIGNAL(released()),this,SLOT(Fin()));

	// Partie configuré - exemple (3)
	_Intro3 = new QLabel("	Sinon vous pouvez lancer une partie avec\n\t3 exemples déja configuré :\n ",this);
	_Intro3->move(0,220);

	_ChoixExemple = new QComboBox(this);
	_ChoixExemple->addItem("Exemple1",0);
	_ChoixExemple->addItem("Exemple2",1);
	_ChoixExemple->addItem("Exemple3",2);
	_ChoixExemple->setGeometry(0,280,100,20);

	_Lancer2 = new QPushButton("Lancer la partie!",this);
	_Lancer2->setGeometry(100,280,150,20);
	connect(_Lancer2,SIGNAL(released()),this,SLOT(Choix_Exemple()));

	_Liste = new QLabel("",this);
	_Liste->setGeometry(0,310,600,300);

	Game = new Jeu(TAILLE_TERRAIN,TAILLE_TERRAIN);
	Fenetre_Game = new Fenetre_Jeu();

}

/// Ajout d'un joueur dans le JEU et modification du Label sur la fênetre de configuration pour voir les ajouts
void Fenetre_Ajout::Ajouter_Joueur(){
	switch (_ChoixJoueur->currentIndex()){
    	case 0:{
			switch(_ChoixAlgo->currentIndex()){
        		case 0:{
        			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Random\n");
					this->Game->ajouter_Voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::random));
        		}break;

        		case 1:{
        			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le haut!\n");
					this->Game->ajouter_Voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::haut));
        		}break;

        		case 2:{
        			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le bas!\n");
					this->Game->ajouter_Voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::bas));
        		}break;

        		case 3:{
        			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Fuyard!\n");
					this->Game->ajouter_Voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::gendarmes_chasseurs));
        		}break;

        		case 4:{
        			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : IA Facile\n");
					this->Game->ajouter_Voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::IA_Facile));
        		}break;
        	}
        }break;

        case 1:{
        	switch(_ChoixAlgo->currentIndex()){
        		case 0:{
        			_Liste->setText(_Liste->text() + "Gendarme:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Random\n");
					this->Game->ajouter_Gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::random));
        		}break;

        		case 1:{
        			_Liste->setText(_Liste->text() + "Gendarme:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le haut!\n");
					this->Game->ajouter_Gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::haut));
        		}break;

        		case 2:{
        			_Liste->setText(_Liste->text() + "Gendarme:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le bas!\n");
					this->Game->ajouter_Gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::bas));
        		}break;

        		case 3:{
        			_Liste->setText(_Liste->text() + "Gendarme:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Chasseur!\n");
					this->Game->ajouter_Gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::gendarmes_chasseurs));
        		}break;

        		case 4:{
        			_Liste->setText(_Liste->text() + "Gendarme:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : IA Facile\n");
					this->Game->ajouter_Gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::IA_Facile));
        		}break;
        	}
        }break;
    }
}

/// Ajout d'un Non_Joueur dans le JEU et modification du Label sur la fênetre de configuration pour voir les ajouts
void Fenetre_Ajout::Ajouter_NonJoueur(){
	switch (_AutreChoix->currentIndex()){
        case 0:{
            // Voleur V1(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,"V1");
             _Liste->setText(_Liste->text() + "Sortie: ("+_PositionX2->text()+","+_PositionY2->text()+")\n");
			this->Game->ajouter_nonJoueur(NonJoueur(Position(_PositionX2->text().toDouble(),_PositionY2->text().toDouble()),Type::sortie));
        }break;

        case 1:{
        	// Pas encore de gestion de cachette.

        }break;
    }

}



/// Ajout de la couleur de l'item Rect de chaque entité et ajout sur la scène.
void Fenetre_Ajout::Configuration_Partie(){
	for (auto i : this->Game->getListeVoleurs()){
		i->getItem()->setBrush(QBrush(Qt::red));
		Fenetre_Game->scene->addItem(i->getItem());
	}

	for (auto i : this->Game->getListeGendarmes()){
		i->getItem()->setBrush(QBrush(Qt::blue));
		Fenetre_Game->scene->addItem(i->getItem());
	}

	for (auto i : this->Game->getListeNonJoueurs()){
		if (i->getType()==Type::sortie){
			i->getItem()->setBrush(QBrush(Qt::green));
			Fenetre_Game->scene->addItem(i->getItem());
		}
		else {
			i->getItem()->setBrush(QBrush(Qt::green));
			Fenetre_Game->scene->addItem(i->getItem());
		}
	}
}

/// Fonction qui permet de Jouer une partie
void Fenetre_Ajout::Jouer_Partie(){
	std::cout<<"Etat Initial"<<std::endl;
	Game->Afficher();
	// Lancement TIMER
	auto start = high_resolution_clock::now();
	// Partie
	while (Fenetre_Game->fermeture == false){
		for(unsigned int nb_tour=1;!Game->estFini();nb_tour++){
			std::cout<<"\n TOUR "<<nb_tour<<" : \n";
			Game->Jouer_tour();
			for (auto i : Game->getListeVoleurs()){
				i->setItem();
			}
			for (auto i : Game->getListeGendarmes()){
				i->setItem();
			}
			QEventLoop loop;
			QTimer::singleShot(100, &loop, SLOT(quit()));
			loop.exec();
			Game->Afficher();
		}
		if (Game->estFini())Fenetre_Game->fermeture = true;
	}

	// Fin TIMER
	auto stop = high_resolution_clock::now();
	auto duree = duration_cast<seconds>(stop - start);

	// Ecriture en fin de partie
	int resultat_duree= duree.count();
	Ecriture_Resultats(resultat_duree);
	
	// Reset en fin de partie
	Game = new Jeu(TAILLE_TERRAIN,TAILLE_TERRAIN);
	Fenetre_Game = new Fenetre_Jeu();

}
/// Fenetre d'apercu avant lancement de partie
void Fenetre_Ajout::Apercu(){
	Fenetre_Game->fenetre_apercu = true; // Pour gérer la fermeture de la fenetre Apercu, vue que le jeu une fois lancé si on quitte, arrête la partie
	Fenetre_Game->show();
	// Configuration_Partie() pour avoir un aperçu
	Configuration_Partie();
}

/// Fonction qui permet d'écrire les resultats de la partie une fois terminés dans "Resultat.txt"
void Fenetre_Ajout::Ecriture_Resultats(int duree){

	//déclaration
	std::ofstream Resultats;

	Resultats.open ("Resultats.txt",std::ios::app);
	Resultats << "------------------------------\n Résultat de la partie : \n Temps : "<<
	std::to_string(duree)<<" secondes \n Nombre de voleur(s): "<<std::to_string(Game->getNbVoleurs())<<"\n Nombre de gendarme(s): "<<std::to_string(Game->getNbGendarmes())<<"\nVoleur(s) Capturé(s) : "<<std::to_string(Game->getNbCaptures())<<
	" sur "<<std::to_string(Game->getNbVoleurs())<<" \n Voleur(s) Sortie(s) :"<<std::to_string(Game->getNbVoleursSortis())<<" sur "<<std::to_string(Game->getNbVoleurs())<<
	" \n Algorithme utilisé : AFAIRE \n Autres informations : AFAIRE \n------------------------------\n";

	Resultats.close();
}

/// Fonction qui lance une partie -> Configuration puis lancement.
void Fenetre_Ajout::Lancer_Partie(){

	// Affichage de la fenetre Jeu
	Fenetre_Game->show();

	// Configuration et Lancement d'une partie
	Configuration_Partie();
	Jouer_Partie();
}


/// Bouton de Fin de partie
void Fenetre_Ajout::Fin(){
	Game = new Jeu(TAILLE_TERRAIN,TAILLE_TERRAIN);
	Fenetre_Game = new Fenetre_Jeu();
	_Liste->setText("");
}
