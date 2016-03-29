/****************************************************************************
* Fichier: Gestionnaire.h
* Auteur(s): Charles-Olivier Favreau et Stéphanie Leclerc
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
	* Description: Constructeur par défaut
	* Paramètres: aucun
	* Retour: aucun
	****************************************************************************/
	Gestionnaire() {};
	/****************************************************************************
	* Fonction: Gestionnaire::Gestionnaire
	* Description: Destructeurs
	* Paramètres: aucun
	* Retour: aucun
	****************************************************************************/
	~Gestionnaire() {};




	/****************************************************************************
	* Fonction: Gestionnaire::ajouterElement
	* Description: Ajoute un pointeur seulement s'il n'est pas dans le conteneur
	* Paramètres: - T objet: un pointeur d'objet
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
	* Paramètres: - T objet: un pointeur d'objet
	* Retour: (bool) true si l'objet est retiré, false sinon
	****************************************************************************/
	template <typename T>
	bool retirerElement(T* objet) {
		return listeObjets.remove(objet);
	};



	
	/****************************************************************************
	* Fonction: Gestionnaire::retirerContenu
	* Description: Retire l'objet ou les objets qui vérifient la condition
	* Paramètres: - predicate condition: une condition à vérifier
	* Retour: (bool) true si les objets sont retirés, false sinon
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
	* Description: Recherche l'objet qui vérifie le prédicat et retourne son pointeur
	* Paramètres: - predicate condition: une condition à vérifier
	* Retour: (T*) le pointeur de l'objet qui vérifie la condition
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
	* Paramètres: - T objet: un objet à trouver
	* Retour: (bool) true si l'objet a été trouvé, false sinon
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
	* Description: Recherche tous les objets qui vérifient une condition et retourne une liste de pointeurs
	* Paramètres: - predicate condition
	* Retour: (list <T*>) une liste de pointeurs des objets qui vérifient une condition
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