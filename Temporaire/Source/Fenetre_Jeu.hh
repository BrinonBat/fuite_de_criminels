#pragma once
#include <iostream>
#include <QtWidgets>
#include <QCloseEvent>
#include "Entites.hh"

class Fenetre_Jeu : public QWidget {
	Q_OBJECT

public:

	//constructeur
	Fenetre_Jeu();

	//méthodes
	void closeEvent(QCloseEvent *event);

	//variables
	QGraphicsScene * scene;
	QGraphicsView * view;
	bool fenetre_apercu;
	bool fermeture;


};
