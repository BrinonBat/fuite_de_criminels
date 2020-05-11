#include <iostream>
#include "Fenetre_Ajout.hh"
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	 std::srand(std::time(NULL));
    QApplication app(argc,argv);
    Fenetre_Ajout F;
    F.show();
   return app.exec();

	// Voleur V1(Position(0,0),1.0,"V1",Choix_Algo::random);
	// Voleur V2(Position(-10,0),0.5,"V2",Choix_Algo::random);

	// std::cout<<"Distance :"<<V1.getDistance_From(V2);

	// Direction result = V1.Se_Rapprocher(V2);
	// V1.setDestination(V1.getPosition()+result);
	// std::cout<<V1.Affiche_Position();

	// Direction result2 = V1.Se_Rapprocher(V2);
	// V1.setDestination(V1.getPosition()+result2);
	// std::cout<<V1.Affiche_Position();

	// std::cout<<"\n\n";

	// Jeu Exemple2(400,400);

	// for (int i=0;i<30;++i)
	// {
	// 	Voleur V(Position(-350+(i*20),300),1.0,"V"+std::to_string(i),Choix_Algo::bas);
	// 	Exemple2.ajouter_voleur(V);
	// }


	// std::cout<<"Test Communication Gendarmes : \n";

	// Gendarme G1(Position(-50,0),2.0,"G1",Choix_Algo::IA_Facile);
	// Exemple2.ajouter_gendarme(G1);

	// std::cout<<G1.Voleur_Plus_Proche(Exemple2.getListeVoleur()).getNom();

	// Direction result3 = V1.Se_Rapprocher(V2);
	// G1.setDestination(G1.getPosition()+result3);
	// std::cout<<G1.Affiche_Position()<<"\n";

	// Exemple2.calcule_deplacement(G1);
	// std::cout<<G1.Affiche_Position();

	// Information_Gendarme Info_G1(G1);
	// std::cout<<Info_G1.Ma_Position().getX()<<"\n";

	// Exemple2.calcule_deplacement(G1);
	// std::cout<<G1.Affiche_Position();
	// std::cout<<Info_G1.Ma_Position().getX();

	// std::cout<<"\nG2\n";
	// Gendarme G2(Position(-40,0),2.0,"G2",Choix_Algo::random);
	// Exemple2.ajouter_gendarme(G2);
	// Exemple2.calcule_deplacement(G2);
	// std::cout<<G2.Affiche_Position()<<"\n";

	// Information_Gendarme Info_G2(G2);

	// // Communication C1(G1,Exemple2);
	
	// std::cout<<"Information Communication entre G1/G2 : Position G1\n";
	// std::cout<<Info_G1.getGendarme().Affiche_Position();
	
	// std::cout<<"\nDéplacement G1 pour voir si aucun problème de fuite de mémoire : \n";
	// Exemple2.calcule_deplacement(G1);
	// std::cout<<G1.Affiche_Position();
	// std::cout<<Info_G1.Ma_Position().getX();

	// std::cout<<" \n Information Communication entre G1/G2 : Position G1\n";
	// std::cout<<Info_G1.getGendarme().Affiche_Position()<<"\n";

	// // Test ronde
	// Exemple2.calcule_deplacement(G1);
	// std::cout<<G1.Affiche_Position();


}
