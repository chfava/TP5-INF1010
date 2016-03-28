#ifndef TRIEPARTITRE_H
#define TRIEPARTITRE_H

#include "ObjetEmpruntable.h"




class TrieParTitre
{
public:
	TrieParTitre(ObjetEmpruntable& objet1){
		objet1_ = objet1;
	};
	bool operator()(ObjetEmpruntable& objet2){
		return !(objet1_.obtenirTitre().compare(objet2.obtenirTitre()));
	};
	
private:
	ObjetEmpruntable& objet1_;
};


#endif
