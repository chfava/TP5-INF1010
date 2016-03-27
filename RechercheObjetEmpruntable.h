#ifndef RECHERCHEOBJETEMPRUNTABLE_H
#define RECHERCHEOBJETEMPRUNTABLE_H

#include <string>
#include "Gestionnaire.h"
#include "ObjetEmpruntable.h"



class RechercheObjetEmpruntable
{
public:
	RechercheObjetEmpruntable(std::string mot){
		mot_ = mot;
	};
	bool operator()(ObjetEmpruntable& objet){
		return objet.recherche(mot_);
	}
private:
	std::string mot_;
};


#endif
