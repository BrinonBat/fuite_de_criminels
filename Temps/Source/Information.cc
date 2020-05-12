#include "Information.hh"

Position Information_Gendarme::Alerte_Zone(int niveau) {
	setAide(true);
	setAlerte(true,niveau);
	return Ma_Position();
}

Direction Information_Gendarme::Aller_vers(Position P)
{

	//déclarations
	double x,y;

	//traitement de X
	if (Ma_Position().getX()<P.getX()) x=1;
	else if (Ma_Position().getX()>P.getX()) x=-1;
	else x=0;

	//traitement de Y
	if (Ma_Position().getY()<P.getY()) y=1;
	else if (Ma_Position().getY()>P.getY()) y=-1;
	else y=0;

	//retourne la direction à emprunter
	return Direction(x,y);

}

Direction Information_Gendarme::Effectue_Ronde()
{
	if (getRonde()==false)
	{
		setRonde(Ma_Position(),Position(30,30));
		return Aller_vers(getArrivee());
	}
	

}

// Direction Information_Gendarme::Joue(Jeu *J)
// {

// 	// Repère un voleur
// 	Voleur V = G.Voleur_Plus_Proche(J->getListeVoleur());
// 	if (G.getDistance_From(V)>30)
// 	{	
// 		setAide(false);
// 		setChasse(false);

// 		Effectue_Ronde();
// 	}
// 	else if (G.getDistance_From(V)<=30)
// 	{
// 		setAide(true);
// 		setChasse(true);
// 		Annule_Ronde();
// 		return Aller_vers(V.getPosition());
// 	}





// 	// // Commence par effectuer une ronde
// 	// if (getChasse()==false)
// 	// {

// 	// (setRonde(Ma_Position(),Position(300,300)));

// 	// return Aller_vers(Position(300,300));

// 	// }

// 	// if (Ma_Position()==Position(300,300))
// 	// {
// 	// 	return Aller_vers(Position(30,30));
// 	// }


// 	//Defaut

// 	return Effectue_Ronde();


// }





// // Direction Communication::Joue()
// // {

// // 	// Commence par effectuer une ronde
// // 	if (!getInfo_G1().getChasse())
// // 	{

// // 	(getInfo_G1().setRonde(getInfo_G1().Ma_Position(),Position(50,50)));

// // 	return getInfo_G1().Aller_vers(getInfo_G1().getArrivee());

// // 	}




// // }
