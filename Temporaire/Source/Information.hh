#include "Entites.hh"

class Information_Gendarme {
public:
Information_Gendarme(const Gendarme &pG): G(pG),En_Chasse(false),Besoin_Aide(false),Protege_Sortie(false), Depart_Ronde(G.getPosition()), Arrivee_Ronde(G.getPosition()){}

	Information_Gendarme* clone() const {return new Information_Gendarme(*this);}

	Position Ma_Position() const {return G.getPosition();}
	Gendarme getGendarme() const {return G;}

	void setChasse(bool V) {En_Chasse=V;}
	void setAide(bool V) {Besoin_Aide=V;}
	void setAlerte(bool V, int Niveau) {Lance_Alerte=V; Niveau_Alerte=Niveau;}
	void setSortie(bool V) {Protege_Sortie=V;}
	
	void setRonde(Position Depart, Position Arrivee) {En_Ronde=true; Depart_Ronde=Depart; Arrivee_Ronde=Arrivee;}
	void Annule_Ronde() {En_Ronde=false;}

	Direction Aller_vers(Position P);
	Direction Effectue_Ronde();


	bool getChasse() const { return En_Chasse;}
	bool getAide() const { return Besoin_Aide;}
	bool getProtege() const {return Protege_Sortie;}	
	bool getAlerte() const {return Lance_Alerte;}
	bool getRonde() const {return En_Ronde;}

	Position getDepart() const {return Depart_Ronde;}
	Position  getArrivee() const {return Arrivee_Ronde;}

	Position Alerte_Zone(int niveau); // Lance une alerte à la postion du Gendarme pour alerter les autres qu'un évenement se déroule vers cette position
	// Différent niveaux d'alertes ? Premier niveau : Début de l'alerte si un gendarme est à une certaine distance il vient sinon reste à sa position 
	// second niveau : Le gendarme le plus proches le rejoint et troisième niveau : Les gendarmes présent dans une certaine zone viennent protéger cette position -> Dans le cas où plusieurs voleurs s'approchent d'une sortie

	// Direction Joue(Jeu *J);

private:
	Gendarme G;
	
	bool En_Chasse; // Si un gendarme est en chasse d'un voleur
	bool Besoin_Aide; // Si un gendarme à besoin de l'aide d'autre voleur
	bool Protege_Sortie; // Si un gendarme protége une sortie
	
	bool Lance_Alerte; // Lance une alerte vers une zone
	int Niveau_Alerte; // Niveau d'une alerte

	bool En_Ronde; // Si un Gendarme effectue une ronde entre deux positions
	Position Depart_Ronde; // Le gendarme effectue une ronde entre deux positions, il se deplace (librement ? / Chemin plus rapide ?) entre ces deux points
	Position Arrivee_Ronde; // et inversement une fois à l'arrivee -> Arrivée devient Depart et inversement
};



// On peut imaginer une communication d'informations entre deux gendarmes : 
// Dans la fonction qui calculera le déplacement : Communication peut être appelé avec le Gendarme le plus proche..
// 
// Première idées d'implémentation : Une liste (Vector? ou Stack d'informations) ce qui permet à G1 de parcourir les informations actuelles de G2 et inversement.
// 
// class Communication {

// public:
// 	Communication(Gendarme &pG1,Jeu pJ): G1(Information_Gendarme(pG1)),J(pJ) {}

// 	Information_Gendarme getInfo_G1() {return G1;}
// 	Jeu getInfo_Game() {return J;}

// 	Direction Joue();


// private:
// 	Information_Gendarme G1;
// 	Jeu &J;

// };




// std::vector<Gendarme*> Gendarmes_Ensemble;