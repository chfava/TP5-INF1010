/****************************************************************************
* Fichier: Bibliotheque.cpp
* Auteur(s): Charles-Olivier Favreau et St�phanie Leclerc
* Date de creation: 27 mars 2016
* Date de modification: 28 mars 2016
* Description: Fonctions reli�es � la classe Bibliotheque
****************************************************************************/
#include "Bibliotheque.h"
#include "RechercheObjetEmpruntable.h"

using namespace std;
/****************************************************************************
* Fonction: Bibliotheque::Bibliotheque
* Description: Constructeur par d�faut
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
Bibliotheque::Bibliotheque(){
	
};
/****************************************************************************
* Fonction: Bibliotheque::~Bibliotheque
* Description: Destructeur
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
Bibliotheque::~Bibliotheque(){
	DetruireEmprunt detruireEmprunt();
	gestEmprunts_.retirerContenu(detruireEmprunt);
};
/*********************************************************************************
* Fonction: Bibliotheque::trouverAbonne
* Description: Retourne le pointeur de l'abonne qui correspond au matricule
* Param�tres: - string matricule: un matricule � chercher dans le gestAbonnes_
* Retour: (Abonne*) un pointeur d'abonne
**********************************************************************************/
Abonne* Bibliotheque::trouverAbonne(std::string& matricule) const{
	MemeObjet<Abonne, string> memeObjet(matricule);
	return gestAbonnes_.trouverElement(memeObjet);
};
/*****************************************************************************************
* Fonction: Bibliotheque::ajouterAbonne
* Description: Verifie si un abonne a �t� ajout� a la bibliotheque
* Param�tres: - Abonne abonne: un abonne a ajouter
* Retour: (bool) true si l'abonne est ajout�, false s'il est deja dans le gestAbonnes_
*****************************************************************************************/
bool Bibliotheque::ajouterAbonne(Abonne& abonne){
	return gestAbonnes_.ajouterElement(&abonne);
};
/****************************************************************************
* Fonction: Bibliotheque::retirerAbonne
* Description: Verifie si un abonne a ete retire
* Param�tres: - string matricule: le matricule d'un abonne (OUT)
* Retour: (bool) true si l'abonne a ete retire, false sinon
****************************************************************************/
bool Bibliotheque::retirerAbonne(std::string& matricule){
	MemeObjet<Abonne, string> memeObjet(matricule);
	bool retourEmprunt = true;
	while (retourEmprunt){
		retourEmprunt = gestEmprunts_.retirerContenu(memeObjet);
	}
	gestAbonnes_.retirerContenu(memeObjet);
};
/*************************************************************************************
* Fonction: Bibliotheque::trouverObjetEmpruntable
* Description: Retourne le pointeur d'un objet empruntable qui correspond � la cote
* Param�tres: - string cote: une cote � trouver (OUT)
* Retour: (ObjetEmpruntable*) un pointeur d'un objet empruntable
*************************************************************************************/
ObjetEmpruntable* Bibliotheque::trouverObjetEmpruntable(std::string& cote) const{
	MemeObjet<ObjetEmpruntable, string> memeObjet(cote);
	return gestObj_.trouverElement(memeObjet);
};
/************************************************************************************************************************
* Fonction: Bibliotheque::ajouterObjetEmpruntable
* Description: Verifie si un objet empruntable a ete ajoute et ajoute un pointeur ObjetEmpruntable a la Bibliotheque
* Param�tres: - ObjetEmpruntable* objet: le pointeur d'un objet a ajouter (OUT)
* Retour: (bool) true si l'objet a ete ajoute, false sinon
*************************************************************************************************************************/
bool Bibliotheque::ajouterObjetEmpruntable(ObjetEmpruntable* objet){
	return gestObj_.ajouterElement(objet);
};
/******************************************************************************************************
* Fonction: Bibliotheque::retirerObjetEmpruntable
* Description: Verifie si un objet empruntable a ete retire et retire cet objet a la bibliotheque
* Param�tres: - string cote: la cote de l'objet empruntable a retirer (OUT)
* Retour: (bool) true si l'objet a ete retire, false sinon
*******************************************************************************************************/
bool Bibliotheque::retirerObjetEmpruntable(std::string& cote){
	MemeObjet<ObjetEmpruntable, string> memeObjet(cote);
	
	if (gestObj_.trouverElement(memeObjet)->obtenirNbDisponibles() == gestObj_.trouverElement(memeObjet)->obtenirNbExemplaires()){
		return gestObj_.retirerContenu(memeObjet);
	}
	else
		return false;
};
/****************************************************************************
* Fonction: Bibliotheque::rechercherObjetEmpruntable
* Description: Recherche une chaine de mots dans les attributs d'un objet empruntable
* Param�tres: - string str: la chaine de mots � chercher (OUT)
* Retour: aucun
****************************************************************************/
void Bibliotheque::rechercherObjetEmpruntable(const std::string& str) const{
	RechercheObjetEmpruntable predicatRecherche(str);
	

	list <ObjetEmpruntable*> listeObjets = gestObj_.trouverContenu(predicatRecherche);
	std::list<ObjetEmpruntable*>::iterator pos;
	if (listeObjets.size() != 0) {
		TrieParTitre predicatTrie();
		listeObjets.sort(predicatTrie);


		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos)
			cout << *(*pos) << endl;
	}
	else
		cout << "Il n'y a pas d'objet empruntable dans la bibliotheque contenant " << str << endl; 

};
/*******************************************************************************************
* Fonction: Bibliotheque::emprunter
* Description: Ajoute l'objet empruntable au gestEmprunts_
* Param�tres: - string matricule: le matricule de l'abonne qui veut faire l'emprunt (OUT)
*             - string cote: la cote de l'objet empruntable (OUT)
*             - unsigned int date: la date de retour pour l'emprunt (IN)
* Retour: (bool) true si l'emprunt est fait, false sinon
*******************************************************************************************/
bool Bibliotheque::emprunter(std::string& matricule, std::string& cote, unsigned int date){
	Abonne* abonne = trouverAbonne(matricule);
	ObjetEmpruntable* objetEmpruntable = trouverObjetEmpruntable(cote);
	
	unsigned int nLivresEmpruntes = 0;
	bool estEmprunte = true;

	gestObj_.trouverContenu(Empruntable(matricule, cote, nLivresEmpruntes, estEmprunte));

	if (abonne->obtenirLimiteEmprunt() < nLivresEmpruntes && estEmprunte && objetEmpruntable->obtenirNbDisponibles() > 0 && 
		objetEmpruntable->obtenirAgeMinimal() <= abonne->obtenirAge()) {
		Emprunt* emprunt = new Emprunt(matricule, objetEmpruntable, date);
		gestEmprunts_.ajouterElement(emprunt);
		objetEmpruntable->modifierNbDisponibles((objetEmpruntable->obtenirNbDisponibles() - 1));
	}
	else
		estEmprunte = false;
	return estEmprunte;
};
/**********************************************************************************************
* Fonction: Bibliotheque::retourner
* Description: Retourne un emprunt et enl�ve l'objet empruntable du gestEmprunts_
* Param�tres: - string matricule: le matricule de l'abonne qui retourne l'objet empruntable
*             - string cote: la cote de l'objet empruntable qui est retourne
* Retour: (bool) true le retour est fait, false sinon
**********************************************************************************************/
bool Bibliotheque::retourner(std::string& matricule, std::string& cote){
	pair<string, string>emprunt = {matricule, cote};
	
	MemeObjet<Emprunt, pair<string,string>> memeObjet(emprunt);
	
	if (gestEmprunts_.trouverElement(memeObjet) != nullptr){
		gestEmprunts_.retirerContenu(memeObjet);
		gestObj_.trouverElement(memeObjet)->modifierNbDisponibles(gestObj_.trouverElement(memeObjet)->obtenirNbDisponibles() + 1);
		return true;
	}
	
};
/*****************************************************************************************
* Fonction: Bibliotheque::infoAbonne
* Description: Affiche les informations de l'abonne qui correspond au matricule donne
* Param�tres: - string matricule: le matricule de l'abonne (OUT)
* Retour: aucun
*****************************************************************************************/
void Bibliotheque::infoAbonne(std::string matricule) const{
	
	MemeObjet<Abonne, string> predicat(matricule);
	//On doit v�rifier que tous les vecteurs sont parcourus
	Abonne* ab = gestAbonnes_.trouverElement(predicat);

	if (ab != nullptr)
	{
		if (typeid(*ab).name() == typeid(Abonne).name()) {
			const Abonne  *abonne = dynamic_cast <const Abonne*> (ab);
			cout << *abonne;
		}
		if (typeid(*ab).name() == typeid(Etudiant).name()) {
			const Etudiant *etudiant = dynamic_cast <const Etudiant*> (ab);
			cout << *etudiant;
		}
		if (typeid(*ab).name() == typeid(EtudiantBaccalaureat).name()) {
			const EtudiantBaccalaureat *etudiantBac = dynamic_cast <const EtudiantBaccalaureat*> (ab);
			cout << *etudiantBac;
		}
		if (typeid(*ab).name() == typeid(Professeur).name()) {
			const Professeur *professeur = dynamic_cast <const Professeur*> (ab);
			cout << *professeur;
		}
	}
	else
	{
		cout << "Abonne - " << matricule << " - non trouve" << endl;
	}
};
/****************************************************************************************
* Fonction: Bibliotheque::operator+=
* Description: Ajoute un abonne
* Param�tres: - Abonne* abonne: un pointeur d'abonne � ajouter � la bibliotheque(OUT)
* Retour: (Bibliotheque) la bibliotheque avec le nouvel abonne
*****************************************************************************************/
Bibliotheque& Bibliotheque::operator+=(Abonne* abonne){
	ajouterAbonne(*abonne);
	return *this;
};
/**************************************************************************************************************
* Fonction: Bibliotheque::operator+=
* Description: Ajoute un objet empruntable
* Param�tres: - ObjetEmpruntable* obj : un pointeur d'un objet empruntable a ajouter a la bibliotheque (OUT)
* Retour: (Bibliotheque) la bibliotheque avec le nouvel objet empruntable
**************************************************************************************************************/
Bibliotheque& Bibliotheque::operator+=(ObjetEmpruntable* obj){
	ajouterObjetEmpruntable(obj);
	return *this;
};
/********************************************************************************************
* Fonction: Bibliotheque::operator-=
* Description: Retire un abonne
* Param�tres: - Abonne* abonne: un pointeur d'abonne a retirer de la bibliotheque (OUT)
* Retour: (Bibliotheque) la bibliotheque sans l'abonne retire
********************************************************************************************/
Bibliotheque& Bibliotheque::operator-=(Abonne* abonne){
	retirerAbonne(abonne->obtenirMatricule());
	return *this;
};
/**************************************************************************************************************
* Fonction: Bibliotheque::operator-=
* Description: Retire un objet empruntable
* Param�tres: - ObjetEmpruntable* obj: un pointeur d'un objet empruntable a retirer de la bibliotheque (OUT)
* Retour: (Bibliotheque) la bibliotheque sans l'objet empruntable retire
**************************************************************************************************************/
Bibliotheque& Bibliotheque::operator-=(ObjetEmpruntable* obj){
	retirerObjetEmpruntable(obj->obtenirCote());
	return *this;
};
/***************************************************************************************************
* Fonction: operator >>
* Description: Recherche un mot fourni par l'utilisateur dans la bibliotheque
* Param�tres: - istream in: un param�tre d'entr�e (IN)
*             - Bibliotheue biblio: une bibliotheque pour trouver le in fourni par l'utilisateur
* Retour: (istream) la valeur de in
****************************************************************************************************/
istream& operator>>(istream& in, const Bibliotheque& biblio){
	string mot;
	in >> mot;
	biblio.rechercherObjetEmpruntable(mot);
	return in;
};

std::string Bibliotheque::obtenirClasseObjet(std::string const& cote) const{

};
/***************************************************************************************************
* Fonction: Bibliotheuqe::trierEmprunt
* Description: Trie les emprunts en ordre alphab�tique selon les titres des objets emprunt�s
* Param�tres: - Abonne abonne: un abonne � trier la liste d'emprunts (OUT)
* Retour: (map <string, Emprunt*>) la valeur de map
****************************************************************************************************/
map<string, Emprunt*> Bibliotheque::trierEmprunt(Abonne * abonne) const{
	MemeObjet <ObjetEmpruntable, string> memeObjet(abonne->obtenirMatricule());

	list <Emprunt*> listeEmprunts = gestEmprunts_.trouverContenu(memeObjet);
	map <string, Emprunt*> map;

	std::list<Emprunt*>::iterator pos;
	for (pos = listeEmprunts.begin(); pos != listeEmprunts.end(); ++pos)
		map.insert(make_pair((*pos)->obtenirObjetEmpruntable()->obtenirTitre(), *pos));
	return map;

};