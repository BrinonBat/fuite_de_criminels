#include "Fenetre_Jeu.hh"
#include <string>


	Fenetre_Jeu::Fenetre_Jeu()
	:QWidget() {
		resize((TAILLE_TERRAIN*2)+10,(TAILLE_TERRAIN*2)+10);
		_Scene = new QGraphicsScene();
		_View = new QGraphicsView(_Scene,this);
		_View->resize((TAILLE_TERRAIN*2)+10,(TAILLE_TERRAIN*2)+10);
		_View->scale(1, -1);
		_View->setAlignment(Qt::AlignAbsolute);
		_View->setSceneRect(-TAILLE_TERRAIN,-TAILLE_TERRAIN,(TAILLE_TERRAIN*2),(TAILLE_TERRAIN*2)); // Permet de bloquer le scroll-auto d'un GraphicScene
		 _View->fitInView(_Scene->sceneRect(), Qt::KeepAspectRatio);
		 Fenetre_Apercu = false;
		 Fermeture = false;

	}

