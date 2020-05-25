/** \file Entites.hh
*	\brief contient les classes présentes sur le terrain, qu'il s'agisse de joueurs ou d'objets.
*	\note ce fichier contient aussi les constantes et variables de classes nécessaires au fonctionnement des classes associées
* 	\author Baptiste Brinon
*	\author	Nicolas Martinez
*/


	/** \def TAILLE_HITBOX
	*	\brief constante déterminant le diamètre des entités
	*/

	/** \def TAILLE_TERRAIN
	*	\brief 	constante déterminant la taille du terrain utilisé durant la partie.
	*			Elle est notamment utilisée pour définir le cadre du jeu.
	*/

	/** \enum Type
	*	\brief les variables de ce type servent à définir quel rôle a l'entité la contenant.
	*/

		/** \var Type::sortie
		*	\brief si un Type a cette valeur, c'est que le NonJoueur correspondant est une sortie.
		*/

		/**	\var Type::cachette
		*	\brief si un Type a cette valeur, c'est que le NonJoueur correspondant est une cachette.
		*/

	/**	\enum Choix_Algo
	*	\brief les variables de ce type servent à définir l'algorithme qui sera utilisé pour calculer les déplacements du Personnage
	*	\see Jeu::calcule_deplacement()
	*/

		/**	\var Choix_Algo::random
		*	\brief l'algorithme choisi génére un déplacement aléatoire
		*/


		/**	\var Choix_Algo::gendarmes_chasseurs
		*	\brief l'algorithme choisi indique la position de l'ennemi le plus proche,
		*			permettant de le fuir ou de le poursuivre
		*/

		/**	\var Choix_Algo::IA_Facile
		*	\brief l'algorithme choisi correspond au choix d'une IA de niveau facile
		*/

		/**	\var Choix_Algo::IA_Moyen
		*	\brief l'algorithme choisi correspond au choix d'une IA de niveau moyen
		*/

	/**	\class Position
	*	\brief Correspond à une position, donc à des coordonnées.
	*			Gére aussi les opérations associées aux positions (additions, soustraction, comparaisons, multiplications)
	*/

		/**	\fn Position::Position(double const & x, double const & y)
		*	\brief constructeur d'une Position à partir d'un x et d'un y
		*	\param x un double correspondant à la position de l'Entite sur l'axe X
		*	\param y un double correspondant à ka position de l'Entite sur l'axe Y
		*/

		/**	\fn Position::getX()
		*	\brief getter de la variable x
		*	\return la valeur de la variable x
		*/

		/**	\fn Position::getY()
		*	\brief getter de la variable y
		*	\return la valeur de la variable y
		*/

		/**	\fn Position::setX(double const & x)
		*	\brief attribue une nouvelle valeur à la variable x
		*	\param x nouvelle valeur de la variable x
		*/

		/**	\fn Position::setY(double const & y)
		*	\brief attribue une nouvelle valeur à la variable y
		*	\param y nouvelle valeur de la variable y
		*/

		/**	\fn Position::operator+(Position const & pos)
		*	\param pos Position à ajouter à la position actuelle
		*	\return le somme de le position actuelle et du paramètre pos
		*/

		/**	\fn Position::operator-(Position const & pos)
		*	\param pos Position que l'on soustrait à la position actuelle
		*	\return le résultat de la soustraction de la position actuelle par la position prise en paramètre
		*/

		/**	\fn Position::operator*(double mult)
		*	\param mult facteur par lequel on multiplie la Position actuelle
		*	\return le produit de le position actuelle et du paramètre mult
		*/

		/**	\fn Position::operator==(Position const & pos)
		*	\param pos Position à laquelle comparer la position actuelle
		*	\return un booléen indiquant si oui ou non la position en paramètre est identique à l'instance acuelle
		*/

		/**	\var Position::x
		*	\brief double correspondant au positionnement sur l'axe X du terrain
		*/

		/**	\var Position::y
		*	\brief double correspondant au positionnement sur l'axe Y du terrain
		*/


	/**	\class Hitbox
	*	\brief Correspond à la taille de l'entité associé, celle-ci étant définie par TAILLE_HITBOX
	*	\see TAILLE_HITBOX
	*/

		/** \fn Hitbox::Hitbox()
		*	\brief constructeur d'une Hitbox
		*/

		/**	\fn Hitbox::setH(double const & nouv)
		*	\brief attribue une nouvelle valeur à la variable haut
		*	\param nouv nouvelle valeur de la variable haut
		*/

		/**	\fn Hitbox::setB(double const & nouv)
		*	\brief attribue une nouvelle valeur à la variable bas
		*	\param nouv nouvelle valeur de la variable bas
		*/

		/**	\fn Hitbox::setG(double const & nouv)
		*	\brief attribue une nouvelle valeur à la variable gauche
		*	\param nouv nouvelle valeur de la variable gauche
		*/

		/**	\fn Hitbox::setD(double const & nouv)
		*	\brief attribue une nouvelle valeur à la variable droite
		*	\param nouv nouvelle valeur de la variable droite
		*/

		/**	\fn Hitbox::getH()
		*	\brief getter de la variable haut
		*	\return la valeur de la variable haut
		*/

		/**	\fn Hitbox::getB()
		*	\brief getter de la variable bas
		*	\return la valeur de la variable bas
		*/

		/**	\fn Hitbox::getG()
		*	\brief getter de la variable gauche
		*	\return la valeur de la variable gauche
		*/

		/**	\fn Hitbox::getD()
		*	\brief getter de la variable droite
		*	\return la valeur de la variable droite
		*/

		/** \var Hitbox::haut
		*	\brief double indiquant la place occupée par l'Entite associée vers le haut à partir de sa Position
		*/

		/** \var Hitbox::bas
		*	\brief double indiquant la place occupée par l'Entite associée vers le bas à partir de sa Position
		*/

		/** \var Hitbox::gauche
		*	\brief double indiquant la place occupée par l'Entite associée vers la gauche à partir de sa Position
		*/

		/** \var Hitbox::droite
		*	\brief double indiquant la place occupée par l'Entite associée vers la droite à partir de sa Position
		*/

	/**	\class Entite
	*	\brief Il s'agit de toute chose pouvant être placé sur le terrain, que ce soit animé(Joueur) ou non(NonJoueur)
	*	\see Voleur Gendarme NonJoueur
	*/

		/** \fn Entite::Entite(Position const & pos)
		*	\param pos emplacement de l'entité lors de sa création
		*	\see  Voleur Gendarme NonJoueur Entite::compteur
		*/

		/**	\fn Entite::~Entite()
		*	\brief on passe le destructeur en virtual pour que la classe devienne abstraite et que les destructeurs utilisés soient ceux des fils
		*	\see Joueur::~Joueur()
		*/

		/**	\fn Entite::getId()
		*	\brief getter permettant de récupérer la valeur de id
		*	\return l'entier non-signé id
		*/

		/**	\fn Entite::getPosition()
		*	\brief getter permettant de récupérer la variable emplacement
		*	\return la Position emplacement
		*/

		/**	\fn Entite::getHitbox()
		*	\brief getter permettant de récupérer la hitbox de l'Entite
		*	\return la hitbox de l'Entite
		*/

		/**	\fn Entite::double getDistance_From (Entite E)
		*	\param E Entite dont on veut connaître la distance par rapport à l'instance actuelle
		*	\return la distance entre l'instance actuelle et l'Entite prise en paramètre
		*/

		/**	\fn Entite::getItem()
		*	\returns l'item graphique de l'Entite utilisé pour le GUI
		*	\brief Getter permettant de récupérer l'item graphique de l'Entite
		*	\see Fenetre_Ajout Fenetre_Jeu
		*/

		/**	\fn Entite::setPosition(Position nouv)
		*	\brief setter permettant d'attribuer une nouvelle valeur à la variable emplacement
		*	\param nouv nouvelle valeur qui va être attribuée à emplacement
		*/

		/** \fn void Entite::setHitbox()
		* 	\see TAILLE_HITBOX
		*/

		/** \fn Entite::setItem()
		*	\brief place l'item graphique à la Position de l'Entite
		*/

		/**	\fn Entite::Affiche_Position()
		*	\brief affiche la Position à laquelle se trouve l'Entite
		*	\returns une chaine de caractère de la forme "(x,y)"
		*/

		/** \fn Entite::Affiche_Hitbox()
		*	\returns une chaine de caractère de la forme "Hitbox: (G,D,H,B)"
		*/

		/**	\fn Entite::Hitbox_touche(Entite &E)
		*	\param E Entite dont on veut verifier le contact avec l'instance actuelle
		*	\return un booléen indiquant si oui ou non les deux Entite se touchent
		*/


		/**	\var Entite::emplacement
		*	\brief Position à laquelle se trouve l'Entite
		*	\see Position
		*/

		/**	\var Entite:id
		*	\brief entier non-signé permettant de dissocier les Entite et les traiter indépendamment de Jeu
		*	\see Jeu.hh
		*/

		/**	\var Entite::compteur
		*	\brief compteur permettant de savoir combien d'Entité ont été créées, et ainsi donner des ID uniques à chacun.
		*			Sa valeur commence à 0, et est incrémentée lors de la creation de Joueur ou NonJoueur
		*/

		/** \var HB
		*	\brief Hitbox de l'Entite
		*	\see Hitbox
		*/

		/** \var item
		*	\brief pointeur sur l'objet graphique associé à l'Entite
		*	\see Entite::getItem()
		*/

	/** \class NonJoueur
	*	\brief Il s'agit de toutes les Entites sur le terrain qui ne sont pas des Joueurs.
	* 			Il peut s'agir de cachettes, de sorties ou de n'importe quel autre Type précisé dans l'enumeration dédiée.
	*	\see Type
	*/

		/** \fn NonJoueur::NonJoueur(Position const & pos,Type const & t)
		*	\brief constructeur de NonJoueur
		*	\param pos Position à laquelle se trouve l'objet
		*	\param t Type d'objet qu'est le NonJoueur, conformément a l'enumeration associé
		*/

		/** \fn NonJoueur::getType()
		*	\brief Getter permettant d'accéder au Type de NonJoueur
		*	\return le Type d'objet qu'est l'instance actuelle
		*/

		/**	\var NonJoueur::type
		*	\brief Type correspondant à l'objet qu'est le NonJoueur, permettant de lui associer un comportement
		*	\see Jeu::Jouer_tour()
		*/

	/** \class Joueur
	*	\brief Correspond à toutes les entités "vivantes" du Jeu, pouvant se mouvoir et accomplir des objectifs.
	*			Il s'agit entre-autres de Voleur et Gendarme
	*/

		/**	\fn Joueur::Joueur(Position const & pos,double speed,std::string nom,Choix_Algo choix)
		*	\brief constructeur de Joueur,
		*			basé sur Entite en y ajoutant des variable lui permettant de se mouvoir et atteindre ses objectifs.
		*	\param pos Position de départ du Joueur
		*	\param speed vitesse à laquelle va se déplacer le Joueur
		*	\param nom Chaine de caractère correspondant au nom du Joueur
		*	\param choix element de Choix_Algo désignant l'IA associée au Joueur
		*	\see Choix_Algo
		*/

		/** \fn Joueur::getSpeed()
		*	\brief	getter permettant d'accéder à la variable speed
		*	\return un double correspondant à la vitesse du Joueur
		*/

		/** \fn Joueur::getNom()
		*	\brief	getter permettant d'accéder à la variable nom
		*	\return une chaine de caractère correspondant au nom du Joueur
		*/

		/** \fn Joueur::getDestination()
		*	\brief	getter permettant d'accéder à la variable destination
		*	\return une Position correspondant à l'endroit où se dirige le Joueur
		*/

		/** \fn Joueur::getAlgo()
		*	\brief	getter permettant d'accéder à la variable Algo
		*	\return un Choix_Algo correspondant à l'IA qu'utilise le Joueur
		*	\see Choix_Algo
		*/

		/** \fn Joueur::setDestination(Position const &pos)
		*	\brief setter permettant de donner une nouvelle destination au Joueur
		*	\param pos nouvelle destination que va atteindre le Joueur à la fin du tour
		*	\see Jeu::Jouer_tour()
		*/

		/** \fn Joueur::Deplacement()
		*	\see Jeu::Calcule_Deplacement()
		*/

		/** \fn Joueur::Se_Rapprocher(Joueur const & J)
		*	\param J Joueur dont on souhaite se rapprocher
		*	\return Direction dans laquelle on doit se diriger pour se rapprocher du Joueur
		*/

		/**	\fn Joueur::Fuir(Joueur const & J)
		*	\param J Joueur dont on souhaite s'éloigner
		*	\return Direction dans laquelle on doit se diriger pour s'éloigner du Joueur
		*/

		/** \fn Joueur::Gendarme_Plus_Proche(std::vector<Gendarme*> liGen)
		*	\param liGen liste de Gendarme parmi lesquels il faut trouver le plus proche
		*	\return le Gendarme le plus proche de l'instance actuelle
		*	\see Position
		*/

		/** \fn Joueur::Sortie_Plus_Proche(std::vector<NonJoueur*> liNonJ)
		*	\param liNonJ liste de NonJoueur parmi lesquels il faut trouver la sortie la plus proche
		*	\return le NonJoueur de Type sortie le plus proche de l'instance actuelle
		*	\see Position
		*/

		/** \var Joueur::speed
		*	\brief double correspondant à la distance que peut parcourir le Joueur lors d'un tour.
		*/

		/** \var Joueur::nom
		*	\brief Chaine de caractère correspondant au nom du Joueur
		*/

		/** \var Joueur::destination
		*	\brief Position que va atteindre le Joueur aprés s'être déplacé via la méthode associée
		*	\see Jeu::Calcule_Deplacement() Joueur::Deplacement()
		*/

		/** \var Joueur::Algo
		*	\brief il s'agit d'un element Choix_Algo qui correspond à l'IA utilisée pour calculer le déplacement via les méthodes associées
		*	\see Jeu::Calcule_Deplacement()
		*/

	/**	\class Voleur
	*	\brief Il s'agit des voleurs. Ils ont pour objectif d'atteindre la sortie sans se faire attraper par les gendarmes.
	*	\see Gendarme
	*/

		/**	\fn Voleur::Voleur(Position const & pos,double speed,std::string nom, Choix_Algo choix)
		*	\brief Constructeur de Voleur héritant de Joueur
		*	\param pos Position de départ du Voleur
		*	\param speed vitesse à laquelle va se déplacer le Voleur
		*	\param nom Chaine de caractère correspondant au nom du Voleur
		*	\param choix element de Choix_Algo désignant l'IA associée au Voleur
		*	\see Choix_Algo
		*/

		/** \fn Voleur::clone()
		*	\brief constructeur virtuel permettant de traiter le Voleur comme un Joueur
		*	\return un pointeur sur un Voleur
		*/

		/** \fn Voleur::Evite_Murs(Direction const & dirActuelle);
		*	\param dirActuelle Direction dans laquelle compte se diriger le Voleur
		*	\return la Direction modifiée de manière à éviter le mur.
		*/


	/**	\class Gendarme
	*	\brief Il s'agit des gendarmes. Ils ont pour objectif d'attraper les voleurs
	*	\see Voleur
	*/

		/**	\fn Gendarme::Gendarme(Position const & pos,double speed,std::string nom,Choix_Algo choix)
		*	\brief Constructeur de Gendarme héritant de Joueur
		*	\param pos Position de départ du Gendarme
		*	\param speed vitesse à laquelle va se déplacer le Gendarme
		*	\param nom Chaine de caractère correspondant au nom du Gendarme
		*	\param choix element de Choix_Algo désignant l'IA associée au Gendarme
		*	\see Choix_Algo
		*/

		/** \fn Gendarme::clone()
		*	\brief constructeur virtuel permettant de traiter le Gendarme comme un Joueur
		*	\return un pointeur sur un Gendarme
		*/

		/** \fn Gendarme::Voleur_Plus_Proche(std::vector<Voleur*> liVol)
		*	\param liVol liste de Voleur parmis lesquels il faut trouver le plus proche
		*	\return le Voleur le plus proche de l'instance actuelle
		*	\see Position
		*/
