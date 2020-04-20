// ici les différentes fonctions avec leurs anciens codes et autres tentatives de fonctionnment

/*******************  main ***************/ 


	// Ajout GRILLE
	Jeu Test(20,20);
	// Ajout JOUEURS
	Voleur Voleur1(Position(6,5),0.3,"Voleur1");
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";
	Gendarme Gendarme1(Position(10,5),0.3,"Gendarme1");
	std::cout<<"Gendarme1:"<<Gendarme1.Affiche_Position()<<"\n";

	// Ajout JOUEURS sur GRILLE
	Test.ajouter_joueur(Voleur1);
	Test.ajouter_joueur(Gendarme1);

	// Ajout SORTIE
	Test.ajouter_nonJoueur(NonJoueur(Position(18,18),Type::sortie));
	Test.ajouter_nonJoueur(NonJoueur(Position(13,13),Type::sortie));


	// AFFICHAGE
	std::cout<<"-------------\n";
	Test.afficher();
	std::cout<<"-------------\n";
	Test.deplacement(Voleur1,Voleur1.jouer());
	Test.afficher();
	std::cout<<"Voleur1:"<<Voleur1.Affiche_Position()<<"\n";
	// méthode me paraissant inutile, je l'ai supp  std::cout<<"Voleur1:(Dans le vector)"<<Test.getJoueur(0)->Affiche_Position()<<"\n";

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


	// TEST

	// double a,b;
	// a=3.28;
	// b=7.37;
	// std::cout<<"Position P"<<"("<<a<<";"<<b<<")";

	// double VD_x,VD_y,speed;
	// VD_x=2;
	// VD_y=3.20;
	// speed=0.5;

	// a=a+(VD_x*speed*0.4);
	// b=b+(VD_y*speed*0.4);
	// std::cout<<"Position P"<<"("<<a<<";"<<b<<")";

	// a=a+(VD_x*speed*0.4);
	// b=b+(VD_y*speed*0.4);
	// std::cout<<"Position P"<<"("<<a<<";"<<b<<")";