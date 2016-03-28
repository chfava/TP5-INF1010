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

	bool operator()(T objet2){
		return (objet2 == *objet1)
	}
private:
	P* objet1_
};

#endif