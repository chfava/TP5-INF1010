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

	template <typename T>
	bool ajouterElement(T* objet) {
		if (std::find(listeObjets.begin(), listeObjets.end(), objet) == listeObjets.end()){
			listeObjets.push_back(objet);
			return true;
		}
		else
			return false;
	};

	template <typename T>
	bool retirerElement(T* objet) {
		return listeObjets.remove(objet);
	};


	template <typename T, typename predicate>
	bool retirerContenu(predicate& condition) {
	bool elementRetiré;
	std::list<T*>::iterator pos;
	pos = std::find_if(listeObjets.begin(), listeObjets.end(), condition);
	if (pos != listeObjets.end()){
		listeObjets.erase(pos);
		return true;
	}
	else
		return false;
};

template <typename T, typename predicate>
T* trouverElement(predicate& condition)const {
	auto pos = std::find_if(listeObjets.begin(), listeObjets.end(), condition);
	if (pos != listeObjets.end())
		return *pos;
	else
		return nullptr;
	
}

template<typename T>
bool trouverElement(T& objet1)const {
	auto pos = std::find(listeObjets.begin(), listeObjets.end(), objet1)
	{
		if (pos != listeObjets.end()){
			return true;
		}
	}
	return false;
}


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

