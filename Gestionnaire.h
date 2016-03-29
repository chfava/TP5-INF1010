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

	Gestionnaire() {};

	~Gestionnaire() {};


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

	template <typename predicate>
	bool retirerContenu(predicate& condition) {
	bool elementRetiré;
	std::list<T*>::iterator pos;
	pos = find_if(listeObjets.begin(), listeObjets.end(), condition);
	if (*pos != nullptr){
		listeObjets.erase(pos);
		return true;
	}
	else
		return false;
};

template <typename predicate>
T* trouverElement(predicate& condition)const {
	std::list<T*>::const_iterator pos;
	pos = find_if(listeObjets.begin(), listeObjets.end(), condition);
	if (pos != listeObjets.end())
		return *pos;
	else
		return nullptr;
	
}


bool trouverElement(T* objet1)const {
	std::list<T*>::const_iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (*pos == *objet1){
			return true;
		}
	}
	return false;
}

template <typename predicate>
std::list<T*> trouverContenu(predicate& condition)const{
	std::list <T*> liste;
	std::list<T*>::const_iterator pos;
	do{
		pos = find_if(listeObjets.begin(), listeObjets.end(), condition);
			liste.push_back(*pos);
	} while (*pos != nullptr);
	return liste;
};

private: 
	std::list <T*> listeObjets;
};
#endif

