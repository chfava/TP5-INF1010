/****************************************************************************
* Fichier: Bibliotheque.h
* Auteur(s): Charles-Olivier Favreau et Stéphanie Leclerc
* Date de creation: 27 mars 2016
* Date de modification: 28 mars 2016
* Description: Description de la classe Bibliotheque
****************************************************************************/
#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <string>
#include <map>
#include "Abonne.h"
#include "ObjetEmpruntable.h"
#include "Emprunt.h"
#include "Gestionnaire.h"
#include "MemeObjet.h"
#include "RechercheObjetEmpruntable.h"
#include "TrieParTitre.h"
#include "DetruireEmprunt.h"
#include "Etudiant.h"
#include "Empruntable.h"
#include "EtudiantBaccalaureat.h"
#include "Professeur.h"
#include <iostream>


class Bibliotheque
{
public:

	Bibliotheque();
	~Bibliotheque();

	Abonne* trouverAbonne(std::string& matricule) const;

	ObjetEmpruntable* trouverObjetEmpruntable(const std::string& cote) const;

	std::string obtenirClasseObjet(std::string const& cote) const;

	bool ajouterAbonne(Abonne& abonne);
	bool retirerAbonne(const std::string& matricule);

	bool ajouterObjetEmpruntable(ObjetEmpruntable* objet);
	
	bool retirerObjetEmpruntable(const std::string& cote);
	void rechercherObjetEmpruntable(const std::string& str) const;

	
	bool emprunter(const std::string& matricule, const std::string& cote, unsigned int date);
	bool retourner(const std::string& matricule, const std::string& cote);

	void infoAbonne(const std::string matricule) const;

	Bibliotheque& operator+=(Abonne* abonne);
	Bibliotheque& operator+=(ObjetEmpruntable* obj);
	Bibliotheque& operator-=(Abonne* abonne);
	Bibliotheque& operator-=(ObjetEmpruntable* obj);

	friend std::istream& operator>>(std::istream& in, const Bibliotheque& biblio);

	/// ____ TP5 ___
	map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const;

private:

	/// ____ TP5 ___
	Gestionnaire<Abonne> gestAbonnes_;
	Gestionnaire<Emprunt> gestEmprunts_;
	Gestionnaire<ObjetEmpruntable>gestObj_;
};

#endif