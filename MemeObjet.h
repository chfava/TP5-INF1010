/****************************************************************************
* Fichier: MemeObjet.h
* Auteur(s): Charles-Olivier Favreau et Stéphanie Leclerc
* Date de creation: 25 mars 2016
* Date de modification: 28 mars 2016
* Description: Description du foncteur MemeObjet
****************************************************************************/
#ifndef MEMEOBJET_H
#define MEMEOBJET_H

#include <string>
#include "ObjetEmpruntable.h"

using namespace std;

template<typename T, typename P>
class MemeObjet{

public:
	MemeObjet(P& objet1){
		*objet1_ = objet1;
	};

	bool operator()(T* objet2){
		return (*objet1 == *objet2)
	}
private:
	P* objet1_;
};

#endif