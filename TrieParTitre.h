/****************************************************************************
* Fichier: TrieParTitre
* Auteur(s): Charles-Olivier Favreau et Stéphanie Leclerc
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
	TrieParTitre(ObjetEmpruntable& objet1):objet1_(objet1) {
		
	};
	bool operator()(ObjetEmpruntable& objet2){
		return !(objet1_.obtenirTitre().compare(objet2.obtenirTitre()));
	};
	
private:
	ObjetEmpruntable& objet1_;
};


#endif
