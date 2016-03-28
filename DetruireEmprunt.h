#ifndef DETRUIREEMRUNT_H
#define DETRUIREEMRUNT_H

#include "Gestionnaire.h"
#include "Emprunt.h"



//À terminer !

class DetruireEmprunt
{
public:
	DetruireEmprunt(Gestionnaire<Emprunt> gestionnaire){
		gestionnaire_ = gestionnaire;
	};
	void operator()(){
		
	};
private:
	Gestionnaire<Emprunt> gestionnaire_;
};


#endif
