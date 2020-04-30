#include <iostream>
#include "Fenetre_Ajout.hh"
#include "Jeu.hh"

using namespace std;

int main(int argc, char *argv[])
{
	std::srand(std::time(NULL));
    QApplication app(argc,argv);
    Fenetre_Ajout F;
    F.show();
   return app.exec();
}


