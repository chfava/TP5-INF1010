
#ifndef EMPRUNTABLE_H
#define EMPRUNTABLE_H

#include <string>
#include "Abonne.h"
#include "ObjetEmpruntable.h"

//À terminer !

class Empruntable
{
public:
	Empruntable(const std::string matricule, const std::string cote, unsigned int &compteur, bool &estEmprunte);
	bool operator () (Emprunt* emprunt);


private:
	std::string matricule_;
	std::string cote_;
	unsigned int* compteur_;
	bool* estEmprunte_;

};

Empruntable::Empruntable(const std::string matricule, const std::string cote, unsigned int &compteur, bool &estEmprunte) :matricule_(matricule), cote_(cote), compteur_(&compteur), estEmprunte_(&estEmprunte) {};

bool Empruntable::operator () (Emprunt* emprunt) {
	if (*estEmprunte_) {
		if (matricule_ == *emprunt)
			(*compteur_)++;
		if (cote_ == *(emprunt->obtenirObjetEmpruntable()))
			*estEmprunte_ = false;
	}
	return *estEmprunte_;
}
#endif