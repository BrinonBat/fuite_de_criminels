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
	bool Fermeture;

void closeEvent(QCloseEvent *event)
{
	if (!Fenetre_Apercu and Fermeture == false){
    QWidget::closeEvent(event);
	}
	else Fenetre_Apercu = false;

	if (Fermeture==	true)
	{
		QWidget::closeEvent(event);
		Fermeture = false;
	}
}

};