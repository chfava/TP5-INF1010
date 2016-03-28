#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <list>
<<<<<<< HEAD
#include <cstdlib>

template <typename T>
class Gestionnaire {

public: 
	Gestionnaire();
	~Gestionnaire();
	bool ajouterElement(T* objet);
	bool retirerElement(T* objet);
	bool retirerContenu(T objet);
	T* trouverElement(T* objet);
	bool trouverElement(T objet);
	list <T*> trouverContenu(T* objet);

private:
	list <T*> listeObjets;
};

template <typename T>
Gestionnaire <T>::Gestionnaire() {
};

template <typename T>
Gestionnaire <T>::~Gestionnaire() {
};

template <typename T>
bool Gestionnaire<T>::ajouterElement(T* objet) {
	Node* newnode = new Node(objet);
	list <T*>::iterator end = listeObjets.end();
	bool ajout = false;
	for (list<T*>::iterator it = listeObjets.begin(); it != end && it != find(listeObjets.begin(), end, *objet); it++) {
		listeObjets.insert(objet);
		ajout = true;
	}
	return ajout;
};

template <typename T>
bool Gestionnaire<T>::retirerElement(T* objet) {
	list <T*>::iterator end = listeObjets.end();
	bool trouve = false;
	bool retrait = false;
	for (list<T*>::iterator it = listeObjets.begin(); it != end && trouve == false; it++) {
		if (it = find(listeObjets.begin(), end, *objet)) {
			trouve = true;
			listeObjets.erase(it);
		}
	}
	if (trouve == true) {
		retrait = true;
	}
	return retrait;
};

template <typename T>
bool Gestionnaire<T>::retirerContenu(bool predicat) {
	bool retire = false;
	bool trouve = false;
	for (list<T*>::iterator it = listeObjets.begin(); it != end && trouve == false && predicat == true; it++) {
		if (it = find(listeObjets.begin(), end, *objet)) {
			if (listeObjets.retirerElement(&T) == true) {
				retire = true;
			}
		}
	}
	return retire; 
};

template <typename T>
T* Gestionnaire<T>::trouverElement(T* objet) {
	bool trouve = false; 
	for (list<T*>::iterator it = listeObjets.begin(); it != end && trouve == false; it++) {
		if (it = find(listeObjets.begin(), end, *objet)) {
			trouve = true;
		}
	}
	if (trouve == true) {
		return objet;
	}
	return nullptr;
};

template <typename T>
bool Gestionnaire<T>::trouverElement(T objet) {
	bool trouve = false;
	for (list<T*>::iterator it = listeObjets.begin(); it != end && trouve == false; it++) {
		if (it = find(listeObjets.begin(), end, *objet)) {
			trouve = true;
		}
	}
	return trouve; 
};

template <typename T>
list <T*> Gestionnaire<T>::trouverContenu(bool predicat) {
	bool trouve = false;
	for (list<T*>::iterator it = listeObjets.begin(); it != end && trouve == false && predicat == true; it++) {
		if (it = find(listeObjets.begin(), end, *objet)) {
			trouve = true;
			return listeObjets;
		}
	} 
};







#endif
=======
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
>>>>>>> origin/master
