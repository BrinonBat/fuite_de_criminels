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
	connect(_Lancer,SIGNAL(released()),this,SLOT(Lancer_Partie()));

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



	void Fenetre_Ajout::Lancer_Partie()
	{
		Fenetre_Jeu *J = new Fenetre_Jeu();
		J->show();
		
		// QGraphicsRectItem* item2 = new QGraphicsRectItem(20,20,4,4);
		// item2->setBrush(QBrush(Qt::blue));
		// J->_Scene->addItem(item2);

		Jeu Test(400,400);

	//creation des entités
	NonJoueur Sortie(Position(38,38),Type::sortie);

	QGraphicsRectItem* item1 = new QGraphicsRectItem(-2,-2,4,4);
		item1->setPos(38,38);
		item1->setBrush(QBrush(Qt::green));
		J->_Scene->addItem(item1);

	Voleur V1(Position(-150,-150),1.0,"V1");

	QGraphicsRectItem* item2 = new QGraphicsRectItem(-2,-2,4,4);
		item2->setPos(-150,-150);
		item2->setBrush(QBrush(Qt::red));
		J->_Scene->addItem(item2);

	Voleur V2(Position(38,30),0.5,"V2");

	QGraphicsRectItem* item3 = new QGraphicsRectItem(-2,-2,4,4);
		item3->setPos(38,30);
		item3->setBrush(QBrush(Qt::red));
		J->_Scene->addItem(item3);

	Gendarme G1(Position(-148,300),2.0,"G1");

	QGraphicsRectItem* item4 = new QGraphicsRectItem(-2,-2,4,4);
		item4->setPos(-148,300);
		item4->setBrush(QBrush(Qt::blue));
		J->_Scene->addItem(item4);

	Gendarme G2(Position(6,9),2.0,"G2");

	QGraphicsRectItem* item5 = new QGraphicsRectItem(-2,-2,4,4);
		item2->setPos(6,9);
		item5->setBrush(QBrush(Qt::blue));
		J->_Scene->addItem(item5);

	// ajout des entités au Jeu
	Test.ajouter_voleur(V1);
	Test.ajouter_gendarme(G1);
	Test.ajouter_voleur(V2);
	Test.ajouter_gendarme(G2);
	Test.ajouter_nonJoueur(Sortie);


	std::cout<<"Etat Initial"<<std::endl;
	Test.afficher();
	std::cout<<"\n EXEMPLE_EXECUTION : \n ";
	Test.getVoleur(0);



	// Partie
	for(unsigned int nb_tour=1;!Test.estFini();nb_tour++){
		std::cout<<"\n TOUR "<<nb_tour<<" : \n";
		Test.Jouer_tour();
		for (auto i : Test.getListeVoleur())
		{
			if (i->getNom()=="V1")
			{
				item2->setPos(i->getPosition().getX(),i->getPosition().getY());
				// std::cout<<"V1"<<(int)Test.getVoleur(0).getDestination().getX()<<","<<(int)Test.getVoleur(0).getPosition().getY();
			}
			if (i->getNom()=="V2")
			{
				item3->setPos(i->getPosition().getX(),i->getPosition().getY());
				// std::cout<<"V1"<<(int)Test.getVoleur(0).getDestination().getX()<<","<<(int)Test.getVoleur(0).getPosition().getY();
			}
		}

		for (auto i : Test.getListeGendarme())
		{
			if (i->getNom()=="G1")
			{
				item4->setPos(i->getPosition().getX(),i->getPosition().getY());
				// std::cout<<"V1"<<(int)Test.getVoleur(0).getDestination().getX()<<","<<(int)Test.getVoleur(0).getPosition().getY();
			}
			if (i->getNom()=="G2")
			{
				item5->setPos(i->getPosition().getX(),i->getPosition().getY());
				// std::cout<<"V1"<<(int)Test.getVoleur(0).getDestination().getX()<<","<<(int)Test.getVoleur(0).getPosition().getY();
			}
		}

		// item3->setPos((int)V2.getPosition().getX(),(int)V2.getPosition().getY());
		// item4->setPos((int)G1.getPosition().getX(),(int)G1.getPosition().getY());
		// item5->setPos((int)G2.getPosition().getX(),(int)G2.getPosition().getY());
		QEventLoop loop;
		QTimer::singleShot(100, &loop, SLOT(quit()));
		loop.exec();

		Test.afficher();
	}


		// for (int i=20;i<100;i++)
		// {
		// 	// QThread::msleep(20);
		// 	item2->setPos(i,i);
		// 	item3->setPos(i,i);
		// 	item4->setPos(i,i);
		// 	item5->setPos(i,i);

			
		// 	QEventLoop loop;
		// 	QTimer::singleShot(100, &loop, SLOT(quit()));
		// 	loop.exec();
		// }
		

	}
