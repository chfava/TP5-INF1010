#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include <list>

template <typename T>
class Gestionnaire {
public:
	template <typename T>
	Gestionnaire() {};
	template <typename T>
	Gestionnaire~() {};
	
	template <typename T>
	bool ajouterElement(T* objet) {
		Node* newnode = new Node(objet);
		list <T*>::iterator end = listeObjets.end();
		bool ajout = false;
		for (list<T*>::iterator it = listeObjets.begin(); it != end && it != find (listeObjets.begin(),end, *objet) ; it++) {
			listeObjets.insert(objet);
			ajout = true; 

		}
		return ajout;

	};

	template <typename T>
	bool retirerElement(T* objet) {
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








	


private: 
	list <*T> listeObjets;
};
#endif
