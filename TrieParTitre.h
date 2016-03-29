/****************************************************************************
* Fichier: TrieParTitre
* Auteur(s): Charles-Olivier Favreau et St�phanie Leclerc
* Date de creation: 26 mars 2016
* Date de modification: 28 mars 2016
* Description: Description du foncteur TrieParTitre
****************************************************************************/
#ifndef TRIEPARTITRE_H
#define TRIEPARTITRE_H

#include "ObjetEmpruntable.h"

class TrieParTitre
{
public:
	TrieParTitre() {};

	bool operator()(const ObjetEmpruntable* objet1, const ObjetEmpruntable* objet2){
		std::string titre1 = objet1->obtenirTitre();
		std::string titre2 = objet2->obtenirTitre();
		objet1->convertirMinuscule(titre1);
		objet2->convertirMinuscule(titre2);

		return (titre1 < titre2);
	};
};


#endif
