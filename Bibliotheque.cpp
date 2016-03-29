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
	return gestAbonnes_.ajouterElement(&abonne);
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

bool Bibliotheque::retourner(std::string& matricule, std::string& cote){
	pair<string, string>emprunt = {matricule, cote};
	
	MemeObjet<Emprunt, pair<string,string>> memeObjet(emprunt);
	
	if (gestEmprunts_.trouverElement(memeObjet) != nullptr){
		gestEmprunts_.retirerContenu(memeObjet);
		gestObj_.trouverElement(memeObjet)->modifierNbDisponibles(gestObj_.trouverElement(memeObjet)->obtenirNbDisponibles() + 1);
		return true;
	}
	
};

void Bibliotheque::infoAbonne(std::string matricule) const{
	
	MemeObjet<Abonne, string> predicat(matricule);
	//On doit vérifier que tous les vecteurs sont parcourus
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