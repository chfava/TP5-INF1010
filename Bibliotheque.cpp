#include "Bibliotheque.h"
#include "RechercheObjetEmpruntable.h"

using namespace std;

Bibliotheque::Bibliotheque(){
	
};

Bibliotheque::~Bibliotheque(){

};

Abonne* Bibliotheque::trouverAbonne(std::string& matricule) const{
	MemeObjet<Abonne, string> memeObjet(matricule);
	return gestAbonnes_.trouverElement(memeObjet);
};

ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(const std::string& cote) const{

};

std::string Bibliotheque::obtenirClasseObjet(std::string const& cote) const{

};

bool Bibliotheque::ajouterAbonne(Abonne& abonne){

};
bool Bibliotheque::retirerAbonne(const std::string& matricule){

};

bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet){

};

bool Bibliotheque::retirerObjetEmpruntable(const std::string& cote){

};

void Bibliotheque::rechercherObjetEmpruntable(const std::string& str) const{
	RechercheObjetEmpruntable foncteur;

};


bool Bibliotheque::emprunter(const std::string& matricule, const std::string& cote, unsigned int date){

};

bool Bibliotheque::retourner(const std::string& matricule, const std::string& cote){

};

void Bibliotheque::infoAbonne(const std::string& matricule) const{

};

Bibliotheque& Bibliotheque::operator+=(Abonne* abonne){
	ajouterAbonne(*abonne);
	return *this;
};

Bibliotheque& Bibliotheque::operator+=(ObjetEmpruntable* obj){
	ajouterObjetEmpruntable(obj);
	return *this;
};

Bibliotheque& Bibliotheque::operator-=(Abonne* abonne){
	retirerAbonne(abonne->obtenirMatricule());
	return *this;
};

Bibliotheque& Bibliotheque::operator-=(ObjetEmpruntable* obj){
	retirerObjetEmpruntable(obj->obtenirCote());
	return *this;
};

istream& operator>>(istream& in, const Bibliotheque& biblio){
	string mot;
	in >> mot;
	biblio.rechercherObjetEmpruntable(mot);
	return in;
};
