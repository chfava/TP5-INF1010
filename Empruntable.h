
#ifndef EMPRUNTABLE_H
#define EMPRUNTABLE_H

#include <string>
#include "Abonne.h"
#include "ObjetEmpruntable.h"

class Empruntable
{
public:
	Empruntable(){
		
	};

	bool operator()(){
		
	};

private:
	std::string* matricule;
	std::string* cote;
	unsigned int compteur;
	bool booléen;

};
#endif