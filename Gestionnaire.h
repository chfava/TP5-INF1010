/****************************************************************************
* Fichier: Gestionnaire.h
* Auteur(s): Charles-Olivier Favreau et St�phanie Leclerc
* Date de creation: 10 mars 2016
* Date de modification: 28 mars 2016
* Description: Description de la classe Gestionnaire
****************************************************************************/
#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <list>
#include <algorithm>

#include "Abonne.h"
#include "Emprunt.h"
#include "ObjetEmpruntable.h"

template <typename T>
class Gestionnaire {
public:
	/****************************************************************************
	* Fonction: Gestionnaire::Gestionnaire
	* Description: Constructeur par d�faut
	* Param�tres: aucun
	* Retour: aucun
	****************************************************************************/
	Gestionnaire() {};
	/****************************************************************************
	* Fonction: Gestionnaire::Gestionnaire
	* Description: Destructeurs
	* Param�tres: aucun
	* Retour: aucun
	****************************************************************************/
	~Gestionnaire() {};




	/****************************************************************************
	* Fonction: Gestionnaire::ajouterElement
	* Description: Ajoute un pointeur seulement s'il n'est pas dans le conteneur
	* Param�tres: - T objet: un pointeur d'objet
	* Retour: (bool) true si l'ajout est fait, false sinon
	****************************************************************************/
	template <typename T>
	bool ajouterElement(T* objet) {
		if (std::find(listeObjets.begin(), listeObjets.end(), objet) == listeObjets.end()){
			listeObjets.push_back(objet);
			return true;
		}
		else
			return false;
	};

	
	/****************************************************************************
	* Fonction: Gestionnaire::retirerElement
	* Description: Retire un pointeur d'un conteneur
	* Param�tres: - T objet: un pointeur d'objet
	* Retour: (bool) true si l'objet est retir�, false sinon
	****************************************************************************/
	template <typename T>
	bool retirerElement(T* objet) {
		return listeObjets.remove(objet);
	};



	
	/****************************************************************************
	* Fonction: Gestionnaire::retirerContenu
	* Description: Retire l'objet ou les objets qui v�rifient la condition
	* Param�tres: - predicate condition: une condition � v�rifier
	* Retour: (bool) true si les objets sont retir�s, false sinon
	****************************************************************************/
	template <typename T, typename predicate>
	bool retirerContenu(predicate& condition) {
	std::list<T*>::iterator pos;
	pos = std::find_if(listeObjets.begin(), listeObjets.end(), condition);
	if (pos != listeObjets.end()){
		listeObjets.erase(pos);
		return true;
	}
	else
		return false;
	};
	/************************************************************************************
	* Fonction: Gestionnaire::trouverElement
	* Description: Recherche l'objet qui v�rifie le pr�dicat et retourne son pointeur
	* Param�tres: - predicate condition: une condition � v�rifier
	* Retour: (T*) le pointeur de l'objet qui v�rifie la condition
	*************************************************************************************/
	template <typename T, typename predicate>
	T* trouverElement(predicate& condition)const {
		auto pos = std::find_if(listeObjets.begin(), listeObjets.end(), condition);
		if (pos != listeObjets.end())
			return *pos;
		else
			return nullptr;
	
	}
	/****************************************************************************
	* Fonction: Gestionnaire::trouverElement
	* Description: Recherche l'objet
	* Param�tres: - T objet: un objet � trouver
	* Retour: (bool) true si l'objet a �t� trouv�, false sinon
	****************************************************************************/
template<typename T>
bool trouverElement(T& objet1)const {
	auto pos = std::find(listeObjets.begin(), listeObjets.end(), objet1)
	{
		if (pos != listeObjets.end()){
			return true;
		}
		return false;
	}
}

	/***********************************************************************************************************
	* Fonction: Gestionnaire::trouverContenu
	* Description: Recherche tous les objets qui v�rifient une condition et retourne une liste de pointeurs
	* Param�tres: - predicate condition
	* Retour: (list <T*>) une liste de pointeurs des objets qui v�rifient une condition
	***********************************************************************************************************/
template <typename T, typename predicate>
std::list<T*> trouverContenu(predicate& condition)const{
	std::list <T*> liste;
	std::copy_if(listeObjets.begin(), listeObjets.end(), back_inserter(liste) ,condition);
	return liste;
};

private: 
	std::list <T*> listeObjets;
};

#endif