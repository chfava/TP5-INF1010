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
				listeObjets.erase(pos);
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
T* trouverElement(predicate& condition) {
	return *(find_if(listeObjets.begin(), listeObjets.end(), condition));
}

bool trouverElement(T objet){
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (*pos == objet){
			return true;
		}
	}
	return false;
}

template <typename predicate>
std::list<T*> trouverContenu(predicate condition){
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
	list <T*> listeObjets;
};
#endif
