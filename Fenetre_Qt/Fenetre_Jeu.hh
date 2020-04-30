#pragma once
#include <iostream>
#include <QtWidgets>

class Fenetre_Jeu : public QWidget {
	Q_OBJECT

public:
	Fenetre_Jeu();

	QGraphicsScene * _Scene;
	QGraphicsView * _View;

};