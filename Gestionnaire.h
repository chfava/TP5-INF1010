#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <list>
#include <algorithm>
#include "Abonne.h"
#include "Emprunt.h"
#include "ObjetEmpruntable.h"

template <typename T, typename predicate>
class Gestionnaire {

public: 
	Gestionnaire();
	~Gestionnaire();
	bool ajouterElement(T* objet);
	bool retirerElement(T* objet);
	bool retirerContenu(predicate& predicat);
	T* trouverElement(predicate& predicat);
	bool trouverElement(T objet);
	std::list <T*> trouverContenu(predicate& predicat);

private:
	std::list <T*> listeObjets;
};

template <typename T, typename predicate>
Gestionnaire<T>::Gestionnaire() {};

template <typename T, typename predicate>
Gestionnaire<T>::~Gestionnaire() {};

template <typename T, typename predicate>
bool Gestionnaire<T, predicate>::ajouterElement(T* objet) {
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (*pos == objet){
			return false;
		}
	}
	listeObjets.push_back(objet);
	return true;
};

template <typename T, typename predicate>
bool Gestionnaire<T, predicate>::retirerElement(T* objet) {
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (*pos == objet){
			pos = listeObjets.erase(pos);
			return true;
		}
	}
	return false;
};

template <typename T, typename predicate>
bool Gestionnaire<T, predicate>::retirerContenu(predicate& condition) {
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

template <typename T, typename predicate>
T* Gestionnaire<T, predicate>::trouverElement(predicate& condition) {
	return *(find_if(listeObjets.begin(), listeObjets.end(), condition));
}

template <typename T, typename predicate>
bool Gestionnaire<T, predicate>::trouverElement(T objet){
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (*pos == objet){
			return true;
		}
	}
	return false;
}

template <typename T, typename predicate>
std::list<T*> Gestionnaire<T, predicate>::trouverContenu(predicate& condition){
	std::list <T*> liste;
	std::list<T*>::iterator pos;
	for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos) {
		if (condition){
			liste.push_back(*pos);
		}
	}
	return liste;
}

#endif
