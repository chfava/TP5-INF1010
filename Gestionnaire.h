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
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (condition(*pos)){
			pos = listeObjets.erase(pos);
			elementRetiré = true;
		}
	}
	return elementRetiré;
};

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

bool trouverElement(T objet)const {
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (*pos == objet){
			return true;
		}
	}
	return false;
}

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

