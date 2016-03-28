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

bool Bibliotheque::ajouterAbonne(Abonne& abonne){
	gestAbonnes_.ajouterElement(&abonne);
};

bool Bibliotheque::retirerAbonne(std::string& matricule){
	MemeObjet<Abonne, string> memeObjet(matricule);
	bool retourEmprunt = true;
	while (retourEmprunt){
		retourEmprunt = gestEmprunts_.retirerContenu(memeObjet);
	}
	gestAbonnes_.retirerContenu(memeObjet);
};

ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(std::string& cote) const{
	MemeObjet<ObjetEmpruntable, string> memeObjet(cote);
	return gestObj_.trouverElement(memeObjet);
};

bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet){
	return gestObj_.ajouterElement(objet);
};

bool Bibliotheque::retirerObjetEmpruntable(std::string& cote){
	MemeObjet<ObjetEmpruntable, string> memeObjet(cote);
	
	if (gestObj_.trouverElement(memeObjet)->obtenirNbDisponibles() == gestObj_.trouverElement(memeObjet)->obtenirNbExemplaires()){
		return gestObj_.retirerContenu(memeObjet);
	}
	else
		return false;
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

std::string Bibliotheque::obtenirClasseObjet(std::string const& cote) const{

};

map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const{

};