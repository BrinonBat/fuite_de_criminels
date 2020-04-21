#include <iostream>
#include "Fenetre_Jeu.hh"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Fenetre_Jeu F;
    F.show();
   return app.exec();
}
