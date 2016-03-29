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
	bool ajouterElement(T* objet) {
		std::list<T*>::iterator pos;
		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
			if (*pos == objet){
				return false;
			}
		}
		listeObjets.push_back(objet);
		return true;
	};
	/****************************************************************************
	* Fonction: Gestionnaire::retirerElement
	* Description: Retire un pointeur d'un conteneur
	* Paramètres: - T objet: un pointeur d'objet
	* Retour: (bool) true si l'objet est retiré, false sinon
	****************************************************************************/
	bool retirerElement(T* objet) {
		std::list<T*>::iterator pos;
		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
			if (*pos == objet){
				pos = listeObjets.erase(pos);
				return true;
			}
		}
		return false;
	};
	/****************************************************************************
	* Fonction: Gestionnaire::retirerContenu
	* Description: Retire l'objet ou les objets qui vérifient la condition
	* Paramètres: - predicate condition: une condition à vérifier
	* Retour: (bool) true si les objets sont retirés, false sinon
	****************************************************************************/
	template <typename predicate>
	bool retirerContenu(predicate& condition) {
	bool elementRetiré;
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (condition(*pos)){
			pos = listeObjets.erase(pos);
			elementRetiré = true;
		}
	}
	return elementRetiré;
	};
	/************************************************************************************
	* Fonction: Gestionnaire::trouverElement
	* Description: Recherche l'objet qui vérifie le prédicat et retourne son pointeur
	* Paramètres: - predicate condition: une condition à vérifier
	* Retour: (T*) le pointeur de l'objet qui vérifie la condition
	*************************************************************************************/
	template <typename predicate>
	T* trouverElement(predicate& condition)const {
		std::list<T*>::iterator pos;
		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
			if (condition(*pos)){
				return *pos;
			}
		}
		return nullptr;
	
	}
	/****************************************************************************
	* Fonction: Gestionnaire::trouverElement
	* Description: Recherche l'objet
	* Paramètres: - T objet: un objet à trouver
	* Retour: (bool) true si l'objet a été trouvé, false sinon
	****************************************************************************/
	bool trouverElement(T objet)const {
		std::list<T*>::iterator pos;
		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
			if (*pos == objet){
				return true;
			}
		}
		return false;
	}
	/***********************************************************************************************************
	* Fonction: Gestionnaire::trouverContenu
	* Description: Recherche tous les objets qui vérifient une condition et retourne une liste de pointeurs
	* Paramètres: - predicate condition
	* Retour: (list <T*>) une liste de pointeurs des objets qui vérifient une condition
	***********************************************************************************************************/
	template <typename predicate>
	std::list<T*> trouverContenu(predicate condition)const{
		std::list <T*> liste;
		std::list<T*>::iterator pos;
		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
			if (condition){
				liste.push_back(*pos);
			}
		}
		return liste;
	}

private: 
	std::list <T*> listeObjets;
};
#endif

