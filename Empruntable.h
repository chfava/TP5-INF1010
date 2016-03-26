
#ifndef EMPRUNTABLE_H
#define EMPRUNTABLE_H

#include <string>
#include "Abonne.h"

using namespace std;



class Empruntable
{
public:
	Empruntable(Abonne& abonne){};
	bool operator()(){};

private:
	string matricule;
	string cote;
	unsigned int conmpteur;
	bool booléen;

};
#endif