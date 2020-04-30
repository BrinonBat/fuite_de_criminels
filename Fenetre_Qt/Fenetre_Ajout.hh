#pragma once
#include <iostream>
#include <QtWidgets>
#include <QPainter>
#include <QPaintEvent>
#include <QApplication>
#include <QMenuBar>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QThread>
#include <unistd.h>

#include "Fenetre_Jeu.hh"
#include "Jeu.hh"

class Fenetre_Ajout : public QWidget {
	Q_OBJECT

public:
	Fenetre_Ajout();
private slots :

	void Ajouter_Joueur();
	void Ajouter_NonJoueur();

	void Lancer_Partie();
	
	void Choix_Exemple();
	void Exemple1();
	void Exemple2();
	void Exemple3();

private :

	QLabel * _Intro;
	QComboBox * _ChoixJoueur;
	QLineEdit * _NomJoueur;
	QLineEdit * _PositionX;
	QLineEdit * _PositionY;
	QPushButton * _Ajouter;

	QLabel * _Intro2;
	QComboBox * _AutreChoix;
	QLineEdit * _PositionX2;
	QLineEdit * _PositionY2;
	QPushButton * _Ajouter2;

	QPushButton * _Lancer;

	QLabel * _Intro3;
	QComboBox * _ChoixExemple;
	QPushButton * _Lancer2;

	QLabel * _Liste;

	Jeu * Game;

}; 





