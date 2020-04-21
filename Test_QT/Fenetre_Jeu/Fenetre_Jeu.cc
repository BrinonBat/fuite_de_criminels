#include "Fenetre_Jeu.hh"
#include <string>

Fenetre_Jeu::Fenetre_Jeu()
	:QWidget() {
		resize(1000,1000);
		drawEllipse(QPointF(10,10), 30, 30);

}