/** \file Jeu.hh
*	\brief contient une seule classe, Jeu, qui est en charge du bon déroulement du Jeu et de la gestion du terrain
*	\note ce fichier contient aussi les IA permettant aux joueurs de se déplacer
* 	\author Baptiste Brinon
*	\author	Nicolas Martinez
*	\see Joueur Choix_Algo
*/

	/**	\class Jeu
	*	\brief Classe chargée du bon déroulement de la partie et de la gestion du terrain durant celle-ci
	*/

			/** \fn Jeu::Jeu(double plargeur, double phauteur)
			*	\brief constructeur de Jeu à partir de la taille du terrain
			*	\param plargeur Double correspondant à la largeur du Terrain
			*	\param phauteur Double correspondant à la hauteur du Terrain
			*	\note  en l'état, la hauteur et la largeur sont determiné par TAILLE_TERRAIN
			*	\see TAILLE_TERRAIN Entites.hh
			*/

			/**	\fn Jeu::Jeu(Jeu const & jeuCopier)
			*	\brief constructeur par recopie
			*	\param jeuCopier Jeu qui va être copié dans la nouvelle instance
			*/

			/**	\fn Jeu::getVoleur(std::size_t num)
			*	\brief getter permettant d'accéder au Voleur associé au numero saisi
			*	\param num indice correspondant à la position du Voleur recherché dans la liste de voleurs
			*	\return le Voleur correspondant au numero
			*/

			/** \fn Jeu::getNbVoleurs()
			*	\brief getter indiquant le nombre total de voleurs qui participent (ou ont participés) à la partie
			*	\return un entier non-signé correspondant au nombre total de voleurs
			*	\see Voleur
			*/

			/**	\fn Jeu::getListeVoleurs()
			*	\brief getter permettant l'accés à toute la liste de Voleur
			*	\return une liste de pointeurs sur des voleurs
			*/

			/**	\fn Jeu::getNbVoleursSortis()
			*	\brief getter indiquant le nombre de voleurs qui ont atteint la sortie
			*	\return un entier non-signé correspondant au nombe de voleurs sortis
			*/

			/**	\fn Jeu::ajouter_Voleur(Voleur const &V)
			*	\param V Voleur à ajouter à la liste
			*/

			/**	\fn Jeu::ajoutUnVoleur()
			*	\brief augmente le nombre total de voleurs. Utilisé pour incrémenter la variable nbVoleurs
			*	\see Jeu::getNbVoleurs() Jeu::ajouter_Voleur() Voleur
			*/

			/**	\fn Jeu::supprimer_Voleur(Voleur  &V)
			*	\param V Voleur qui doit être supprimé de la liste et
			*/

			/**	\fn Jeu::getGendarme(std::size_t num)
			*	\brief getter permettant d'accéder au Gendarme associé au numero saisi
			*	\param num indice correspondant à la position du Gendarme recherché dans la liste de gendarmes
			*	\return le Gendarme correspondant au numero
			*/

			/**	\fn Jeu::getNbGendarmes()
			*	\brief getter indiquant le nombre total de gendarmes qui participent (ou ont participés) à la partie
			*	\return un entier non-signé correspondant au nombre total de gendarmes
			*	\note contrairement à getNbVoleurs(), on ne retourne pas une variable enregistrée dans la classe,
			*			mais la taille du vecteur de Gendarmes. En effet, vu qu'aucun gendarme ne peut être tué,
			*			on considère qu'on ne va jamais supprimer de gendarmes et donc la taille de la liste de gendarmes suffit.
			*	\see Gendarme
			*/

			/**	\fn Jeu::getListeGendarmes()
			*	\brief getter permettant l'accés à toute la liste de Gendarme
			*	\return une liste de pointeurs sur des gendarmes
			*/

			/**	\fn Jeu::ajouter_Gendarme(Gendarme const &G)
			*	\param Gendarme à ajouter à la liste
			*/

			/**	\fn Jeu::getObject(std::size_t num)
			*	\brief getter permettant d'accéder au nonJoueur associé au numero saisi
			*	\param num indice correspondant à la position du NonJoueur recherché dans la liste d'objets'
			*	\return le NonJoueur correspondant au numero
			*/

			/**	\fn Jeu::getListeNonJoueurs()
			*	\brief	getter permettant l'accés à toute la liste de NonJoueur
			*	\return une liste de pointeurs sur des nonJoueurs
			*/

			/**	\fn Jeu::ajouter_nonJoueur(NonJoueur const &nJ)
			*	\param NonJoueur à ajouter à la liste
			*/

			/**	\fn Jeu::getNbCaptures()
			*	\brief getter permettant de connaître le nombre de Voleur capturés
			*	\return un entier non-signé correspondant au nombre de voleurs capturés
			*/

			/**	\fn Jeu::ajoutUneCapture()
			*	\brief	ajoute 1 à la liste de voleurs capturés
			*/

			/**	\fn Jeu::getLargeur()
			*	\brief	getter permettant d'accéder à la largeur du terrain
			*	\return un double correspondant à la largeur du terrain
			*/

			/**	\fn Jeu::getHauteur()
			*	\brief	getter permettant d'accéder à la hauteur du terrain
			*	\return un double correspondant à la hauteur du terrain
			*/

			/**	\fn Jeu::estFini()
			*	\return un booléen indiquant si la partie est terminée
			*	\note il retourne en vérité la réponse à "la liste de Voleurs en jeu est-elle vide?"
			*			mais comme on considère que la partie n'est terminée
			*			que lorsqu'il n'y a plus de voleurs sur le terrain, ça revient au même
			*/

			/**	\fn Jeu::Calcule_Deplacement(Voleur &V)
			*	\param V Voleur dont on calcule la prochaine Position
			*	\note	la Position est directement enregistrée dans la variable destination
			*	\see Voleur Jeu::setDestination()
			*/

			/**	\fn Jeu::Calcule_Deplacement(Gendarme &G)
			*	\param G Gendarme dont on calcule la prochaine Position
			*	\note la Position est directement enregistrée dans la variable destination
			*	\see Gendarme Jeu::setDestination()
			*/

			/** \var Jeu::nbVoleurs
			*	\brief entier non-signé correspondant au nombre total de voleurs ayant été présent dans la partie
			*	\note on ne peut qu'augmenter sa valeur, et non la diminuer. En effet, il s'agit d'un plafond.
			*			cette variable est notamment utilisée pour déduire le nombre de voleurs enfuis
				\see Jeu::getNbVoleursSortis
			*/

			/** \var Jeu::nbCaptures
			*	\brief entier non-signé représentant le nombre de Voleur capturés par les Gendarme
			*/

			/** \var Jeu::largeur
			*	\brief double correspondant à la largeur du terrain
			*/

			/** \var Jeu::hauteur
			*	\brief double correspondant à la hauteur du terrain
			*/

			/** \var Jeu::listeVoleurs
			*	\brief Vecteur de pointeurs sur des Voleurs regroupant les Voleur actuellement en Jeu
			*/

			/** \var Jeu::listeGendarmes
			*	\brief Vecteur de pointeurs sur des Gendarmes regroupant les Gendarme actuellement en Jeu
			*/

			/** \var Jeu::listeObjets
			*	\brief Vecteur de pointeurs sur des NonJoueurs regroupant les NonJoueur actuellement en Jeu
			*/

	/**	\fn double fRand(double fMin, double fMax);
	*	\param fMin double correspondant au nombre minimum obtenable
	*	\param fMax double correspondant au nombre minimum obtenable
	*	\retourn un doubl aléatoire situé entre fMin et fMax
	*/
