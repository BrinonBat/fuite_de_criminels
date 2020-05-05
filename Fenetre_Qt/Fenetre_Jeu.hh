#pragma once
#include <iostream>
#include <QtWidgets>
#include <QCloseEvent>

class Fenetre_Jeu : public QWidget {
	Q_OBJECT

public:
	Fenetre_Jeu();

	QGraphicsScene * _Scene;
	QGraphicsView * _View;

void closeEvent(QCloseEvent *event)
{
    exit(1);
    QWidget::closeEvent(event);
}

};
