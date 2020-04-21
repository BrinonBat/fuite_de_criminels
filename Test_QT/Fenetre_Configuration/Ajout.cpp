#include <iostream>
#include "Fenetre_Ajout.hh"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Fenetre_Ajout F;
    F.show();
   return app.exec();
}
