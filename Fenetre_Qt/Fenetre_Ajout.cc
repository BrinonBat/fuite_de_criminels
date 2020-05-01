#include "Fenetre_Ajout.hh"
#include <string>


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

	Game = new Jeu(400,400);

	}

	// Ajout d'un joueur dans le JEU et modification du Label sur la fênetre de configuration pour voir les ajouts
	void Fenetre_Ajout::Ajouter_Joueur()
	{
		switch (_ChoixJoueur->currentIndex())
        {
            case 0:
            {	switch(_ChoixAlgo->currentIndex())
            	{
            		case 0:
            		{
            			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Random\n");
						this->Game->ajouter_voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::random));
            		}
            		break;
            		
            		case 1:
            		{
            			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le haut!\n");
						this->Game->ajouter_voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::haut));
            		}
            		break;

            		case 2:
            		{
            			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le bas!\n");
						this->Game->ajouter_voleur(Voleur(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::bas));
            		}
            		break;
            	}
            }
                break;

            case 1:
            {
            	switch(_ChoixAlgo->currentIndex())
            	{
            		case 0:
            		{
            			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Random\n");
						this->Game->ajouter_gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::random));
            		}
            		break;
            		
            		case 1:
            		{
            			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le haut!\n");
						this->Game->ajouter_gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::haut));
            		}
            		break;

            		case 2:
            		{
            			_Liste->setText(_Liste->text() + "Voleur:"+_NomJoueur->text()+"("+_PositionX->text()+","+_PositionY->text()+") Déplacement : Vers le bas!\n");
						this->Game->ajouter_gendarme(Gendarme(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,_NomJoueur->text().toStdString(),Choix_Algo::bas));
            		}
            		break;
            	}
            }
                break;
        }



	}

	// Ajout d'un Non_Joueur dans le JEU et modification du Label sur la fênetre de configuration pour voir les ajouts
	void Fenetre_Ajout::Ajouter_NonJoueur()
	{
		switch (_AutreChoix->currentIndex())
        {
            case 0:
            {

                // Voleur V1(Position(_PositionX->text().toDouble(),_PositionY->text().toDouble()),1.0,"V1");
                 _Liste->setText(_Liste->text() + "Sortie: ("+_PositionX2->text()+","+_PositionY2->text()+")\n");
				this->Game->ajouter_nonJoueur(NonJoueur(Position(_PositionX2->text().toDouble(),_PositionY2->text().toDouble()),Type::sortie));
            }
                break;

            case 1:
            {
            	// Pas encore de gestion de cachette.
                
            }
                break;
        }

	}

	void Fenetre_Ajout::Apercu()
	{

		Fenetre_Jeu *J = new Fenetre_Jeu();
		J->show();

		// Ajout de la couleur de l'item Rect de chaque entité et ajout sur la scène.
		for (auto i : this->Game->getListeVoleur())
		{
			i->getItem()->setBrush(QBrush(Qt::red));
			J->_Scene->addItem(i->getItem());
		}

		for (auto i : this->Game->getListeGendarme())
		{
			i->getItem()->setBrush(QBrush(Qt::blue));
			J->_Scene->addItem(i->getItem());
		}

		for (auto i : this->Game->getListeNonJoueur())
		{
			if (i->getType()==Type::sortie)
			{

			i->getItem()->setBrush(QBrush(Qt::green));
			J->_Scene->addItem(i->getItem());
			
			}
			else {

			i->getItem()->setBrush(QBrush(Qt::green));
			J->_Scene->addItem(i->getItem());
			}
		}
	}


	void Fenetre_Ajout::Lancer_Partie()
	{
		Fenetre_Jeu *J = new Fenetre_Jeu();
		J->show();

		// Ajout de la couleur de l'item Rect de chaque entité et ajout sur la scène.
		for (auto i : this->Game->getListeVoleur())
		{
			i->getItem()->setBrush(QBrush(Qt::red));
			J->_Scene->addItem(i->getItem());
		}

		for (auto i : this->Game->getListeGendarme())
		{
			i->getItem()->setBrush(QBrush(Qt::blue));
			J->_Scene->addItem(i->getItem());
		}

		for (auto i : this->Game->getListeNonJoueur())
		{
			if (i->getType()==Type::sortie)
			{

			i->getItem()->setBrush(QBrush(Qt::green));
			J->_Scene->addItem(i->getItem());
			
			}
			else {

			i->getItem()->setBrush(QBrush(Qt::green));
			J->_Scene->addItem(i->getItem());
			}

		}

		std::cout<<"Etat Initial"<<std::endl;
		this->Game->afficher();


		// Partie
	for(unsigned int nb_tour=1;!Game->estFini();nb_tour++){
		std::cout<<"\n TOUR "<<nb_tour<<" : \n";
		Game->Jouer_tour();
		for (auto i : Game->getListeVoleur())
		{
			i->setItem(i->getPosition());
		}

		for (auto i : Game->getListeGendarme())
		{
			i->setItem(i->getPosition());
		}

		QEventLoop loop;
		QTimer::singleShot(100, &loop, SLOT(quit()));
		loop.exec();

		Game->afficher();
		
		}


	}


	void Fenetre_Ajout::Choix_Exemple()
	{
		switch (_ChoixExemple->currentIndex())
        {
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



	void Fenetre_Ajout::Exemple1()
	{
		Fenetre_Jeu *J = new Fenetre_Jeu();
		J->show();

		Jeu Exemple1(400,400);

	//creation des entités
	NonJoueur Sortie(Position(38,38),Type::sortie);
	Voleur V1(Position(-150,-150),1.0,"V1",Choix_Algo::random);
	Voleur V2(Position(38,30),0.5,"V2",Choix_Algo::random);
	Gendarme G1(Position(-148,300),2.0,"G1",Choix_Algo::random);	
	Gendarme G2(Position(6,9),2.0,"G2",Choix_Algo::random);

	// ajout des entités au Jeu
	Exemple1.ajouter_voleur(V1);
	Exemple1.ajouter_gendarme(G1);
	Exemple1.ajouter_voleur(V2);
	Exemple1.ajouter_gendarme(G2);
	Exemple1.ajouter_nonJoueur(Sortie);

	for (auto i : Exemple1.getListeVoleur())
		{
			i->getItem()->setBrush(QBrush(Qt::red));
			J->_Scene->addItem(i->getItem());
		}

		for (auto i : Exemple1.getListeGendarme())
		{
			i->getItem()->setBrush(QBrush(Qt::blue));
			J->_Scene->addItem(i->getItem());
		}

		for (auto i : Exemple1.getListeNonJoueur())
		{
			if (i->getType()==Type::sortie)
			{

			i->getItem()->setBrush(QBrush(Qt::green));
			J->_Scene->addItem(i->getItem());
			
			}
			else {

			i->getItem()->setBrush(QBrush(Qt::green));
			J->_Scene->addItem(i->getItem());
			}

		}

	// Partie
	for(unsigned int nb_tour=1;!Exemple1.estFini();nb_tour++){
		std::cout<<"\n TOUR "<<nb_tour<<" : \n";
		Exemple1.Jouer_tour();
		for (auto i : Exemple1.getListeVoleur())
		{
			i->setItem(i->getPosition());
		}

		for (auto i : Exemple1.getListeGendarme())
		{
			i->setItem(i->getPosition());
		}

		QEventLoop loop;
		QTimer::singleShot(100, &loop, SLOT(quit()));
		loop.exec();

		Exemple1.afficher();
		
		}

	}

void Fenetre_Ajout::Exemple2()
	{
		// Exemple2
	}


void Fenetre_Ajout::Exemple3()
	{
		// Exemple3
	}

	