#include "Bibliotheque.h"

using namespace std;

Bibliotheque::Bibliotheque(){
	
};

Bibliotheque::~Bibliotheque(){

};

Abonne* Bibliotheque::trouverAbonne(const std::string& matricule) const{
	Abonne abonne1;
	abonne1.modifierMatricule(matricule);
	MemeObjet<Abonne, Abonne> (abonne1&);
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

};


bool Bibliotheque::emprunter(const std::string& matricule, const std::string& cote, unsigned int date){

};

bool Bibliotheque::retourner(const std::string& matricule, const std::string& cote){

};

void Bibliotheque::infoAbonne(const std::string& matricule) const{

};

Bibliotheque& Bibliotheque::operator+=(Abonne* abonne){

};

Bibliotheque& Bibliotheque::operator+=(ObjetEmpruntable* obj){

};

Bibliotheque& Bibliotheque::operator-=(Abonne* abonne){

};

Bibliotheque& Bibliotheque::operator-=(ObjetEmpruntable* obj){

};

istream& operator>>(istream& in, const Bibliotheque& biblio){

};
