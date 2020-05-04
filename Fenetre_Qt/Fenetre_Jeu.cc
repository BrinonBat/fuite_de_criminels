#include "Fenetre_Jeu.hh"
#include <string>


	Fenetre_Jeu::Fenetre_Jeu()
	:QWidget() {
		resize(810,810);
		_Scene = new QGraphicsScene();
		_View = new QGraphicsView(_Scene,this);
		_View->resize(810,810);
		_View->scale(1, -1);
		_View->setAlignment(Qt::AlignAbsolute);
		_View->setSceneRect(-400,-400,800,800); // Permet de bloquer le scroll-auto d'un GraphicScene
		 _View->fitInView(_Scene->sceneRect(), Qt::KeepAspectRatio);

	}
