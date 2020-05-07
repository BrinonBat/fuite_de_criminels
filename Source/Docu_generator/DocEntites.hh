/** \file Entites.hh
*	\brief contient les classes présentes sur le terrain, qu'il s'agisse de joueurs ou d'objets.
*	\note ce fichier contient aussi les constantes et variables de classes nécessaires au fonctionnement des classes associées
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

	/**	\var Choix_Algo::haut
	*	\brief l'algorithme choisi déplace le Personnage vers le haut uniquement
	*/

	/**	\var Choix_Algo::bas
	*	\brief l'algorithme choisi déplace le Personnage vers le bas uniquement
	*/

	/**	\var Choix_Algo::gendarmes_chasseurs
	*	\brief l'algorithme choisi indique la position de l'ennemi le plus proche,
	*			permettant de le fuir ou de le poursuivre
	*/

/**	\class Position
*	\brief Correspond à une position, donc à des coordonnées.
*			Gére aussi les opérations associées aux positions (additions, comparaisons, multiplications)
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

	/**	\fn Position::operator*(double mult)
	*	\param mult facteur par lequel on multiplie la Position actuelle
	*	\return le produit de le position actuelle et du paramètre mult
	*/

	/**	\fn Position::operator==(Position const & pos)
	*	\param pos Position à laquelle comparer la position actuelle
	*	\return un booléen indiquant si oui ou non la position en paramètre est identique à l'instance acuelle
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


	/**
	*
	*/

/**
*
*/

/**
*
*/

/**
*
*/

/**
*
*/

/**
*
*/

/**
*
*/

/**
*
*/

/**
*
*/

/**
*
*/


/** \fn void Entite::setHitbox()
* 	\see TAILLE_HITBOX
*/
