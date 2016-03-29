#include "Bibliotheque.h"
#include "RechercheObjetEmpruntable.h"

using namespace std;

Bibliotheque::Bibliotheque(){
	
};

Bibliotheque::~Bibliotheque(){
	DetruireEmprunt detruireEmprunt();
	gestEmprunts_.retirerContenu(detruireEmprunt);
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
	RechercheObjetEmpruntable predicatRecherche(str);
	TrieParTitre predicatTrie;

	list <ObjetEmpruntable*> listeObjets = gestObj_.trouverContenu(predicatRecherche);
	std::list<T*>::iterator pos;
	if (listeObjets.size() != 0) {

		listeObjets.sort(predicatTrie);

		for (pos = listeObjets.begin(); pos != listeObjets.end(); ++pos)
			cout << *(*pos) << endl; 
	}

};


bool Bibliotheque::emprunter(const std::string& matricule, const std::string& cote, unsigned int date){
	Abonne* abonne = trouverAbonne(matricule);

	ObjetEmpruntable* objetEmpruntable = trouverObjetEmpruntable(cote);

	bool 
};

bool Bibliotheque::retourner(const std::string& matricule, const std::string& cote){
	int empruntPos = -1;
	bool estRetourne = false;

	for (unsigned int i = 0; i < vecEmprunts_.size(); i++)
	{
		if ((vecEmprunts_[i]->obtenirMatricule() == matricule) &&
			(*(vecEmprunts_[i]->obtenirObjetEmpruntable()) == cote))
			empruntPos = i;
	}


	if (empruntPos != -1)
	{
		Emprunt* emprunt = vecEmprunts_[emPos];
		ObjetEmpruntable* obj = emprunt->obtenirObjetEmpruntable();
		Abonne* abonne = trouverAbonne(matricule);

		estRetourne = abonne->estEmprunte(*obj);
		if (estRetourne)
		{
			abonne->retirerEmprunt(obj);
			vecEmprunts_[empruntPos] = vecEmprunts_.back();
			vecEmprunts_.pop_back();
			delete emprunt;
			obj->modifierNbDisponibles(obj->obtenirNbDisponibles() + 1);
		}
	}
	return estRetourne;
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
	MemeObjet <ObjetEmpruntable, string> memeObjet(abonne->obtenirMatricule());

	list <Emprunt*> listeEmprunts = gestEmprunts_.trouverContenu(memeObjet);
	map <string, Emprunt*> map;

	std::list<Emprunt*>::iterator pos;
	for (pos = listeEmprunts.begin(); pos != listeEmprunts.end(); ++pos)
		map.insert(make_pair((*pos)->obtenirObjetEmpruntable()->obtenirTitre(), *pos));
	return map;

};