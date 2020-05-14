#include "Fenetre_Jeu.hh"
#include <string>

/// Constructeur fenetre jeu -> Pour l'affichage du jeu après lancement de la partie

	Fenetre_Jeu::Fenetre_Jeu():QWidget() {
		resize((TAILLE_TERRAIN*2)+10,(TAILLE_TERRAIN*2)+10);
		scene = new QGraphicsScene();
		view = new QGraphicsView(scene,this);
		view->resize((TAILLE_TERRAIN*2)+10,(TAILLE_TERRAIN*2)+10);
		view->scale(1, -1);
		view->setAlignment(Qt::AlignAbsolute);
		view->setSceneRect(-TAILLE_TERRAIN,-TAILLE_TERRAIN,(TAILLE_TERRAIN*2),(TAILLE_TERRAIN*2)); // Permet de bloquer le scroll-auto d'un GraphicScene
		 view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
		 fenetre_apercu = false;
		 fermeture = false;

		 

	}

/// Définition du closeEvent pour Fenetre_Jeu -> Prend en compte si c'est la fenetre aperçu/Lancer_Partie et effectue une action en cas de fermeture
	void Fenetre_Jeu::closeEvent(QCloseEvent *event){
		if (!fenetre_apercu and fermeture == false){

	    	QWidget::closeEvent(event);
		}
		else fenetre_apercu = false;

		if (fermeture==	true){
			QWidget::closeEvent(event);
			fermeture = false;
		}
	}
