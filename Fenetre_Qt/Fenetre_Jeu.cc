#include "Fenetre_Jeu.hh"
#include <string>


	Fenetre_Jeu::Fenetre_Jeu()
	:QWidget() {
		resize(810,810);
		_Scene = new QGraphicsScene();


		
		// QGraphicsRectItem* item1 = new QGraphicsRectItem(0,0,4,4);
		// item1->setBrush(QBrush(Qt::red));
		// _Scene->addItem(item1);


		// QGraphicsRectItem* item2 = new QGraphicsRectItem(10,10,4,4);
		// item2->setBrush(QBrush(Qt::blue));
		// _Scene->addItem(item2);


		// _Scene->addText("HelloWorld!");
		

		_View = new QGraphicsView(_Scene,this);
		_View->resize(810,810);
		_View->setAlignment(Qt::AlignAbsolute);
		// _View->setSceneRect(0,0,400,400); // Permet de bloquer le scroll-auto d'un GraphicScene
		_View->setSceneRect(-400,-400,800,800);
		 _View->fitInView(_Scene->sceneRect(), Qt::KeepAspectRatio);
		
		// _View->scale(5,5);
	}

	void Fenetre_Jeu::paintEvent(QPaintEvent *event)
{
    // QPainter painter;
    // painter.begin(this);
    // painter.fillRect(event->rect(), Qt::white);
    // QWidget::paintEvent(event);
    // painter.end();
}

