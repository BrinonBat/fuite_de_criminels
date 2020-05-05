#pragma once
#include <iostream>
#include <QtWidgets>
#include <QCloseEvent>
#include "Entites.hh"

class Fenetre_Jeu : public QWidget {
	Q_OBJECT

public:
	Fenetre_Jeu();

	QGraphicsScene * _Scene;
	QGraphicsView * _View;
	bool Fenetre_Apercu;

void closeEvent(QCloseEvent *event)
{
	if (!Fenetre_Apercu){
    exit(0);
    QWidget::closeEvent(event);
	}
	Fenetre_Apercu = false;

}

};