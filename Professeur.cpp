/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Fichier: Professeur.cpp
//	Auteur(s) : Charles - Olivier Favreau et Stéphanie Leclerc
//	Date de creation : 10 mars 2016
//	Date de modification : 10 mars 2016
//Description : Fonctions reliées à classe Professeur
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "Professeur.h"

using namespace std;

Professeur::Professeur() : Abonne()
{

}

Professeur::Professeur(const string& matricule, const string& nom, const string& prenom, unsigned int age, list<string> ecoles) :
	Abonne(matricule, nom, prenom, age), listEcoles_(ecoles)
{

}
Professeur::~Professeur()
{

}

list<string> Professeur::obtenirEcole() const
{
	return listEcoles_;
}

void Professeur::ajouterEcole(std::string const & ecole)
{
	bool present = false;
	// ajoute l'ecole que si elle n'est pas déjà présente dans le vecteur
	list<string>::iterator pos;
	for (pos = listEcoles_.begin(); pos != listEcoles_.end(); pos++)
	{
		if (*pos == ecole)
		{
			present = true;
		}
	}
	if (!present)
		listEcoles_.push_back(ecole);
}

bool Professeur::retirerEcole(std::string const & ecole)
{
	list<string>::iterator pos;
	for (pos = listEcoles_.begin(); pos != listEcoles_.end(); pos++)
	{
		// retire l'ecole que si elle est présente dans le vecteur

		if (*pos == ecole)
		{
			listEcoles_.erase(pos);
			return true;
		}
	}
	return false;
}

unsigned int Professeur::obtenirLimiteEmprunt() const
{
	return Abonne::obtenirLimiteEmprunt()*listEcoles_.size();
}


ostream & operator<<(ostream & o, Professeur & professeur)
{
	const Abonne* ab = &professeur;
	o << *ab 
	<< "Limite d'emprunts : " << professeur.obtenirLimiteEmprunt() << endl;;
		
	//Trier en ordre décroissant
	professeur.listEcoles_.sort();
	professeur.listEcoles_.reverse();
	
	o << "LISTE DES ECOLES : " ;

	// Affichage de la liste des ecoles
	list<string>::iterator pos;
	for (pos = professeur.listEcoles_.begin(); pos != professeur.listEcoles_.end(); pos++)
	{
		o << *pos << "; ";
	}
	o << endl;
	return o;
}