/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TableauDynamique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet de stocker les différents trajets simples et trajets composés et de les gérer en effectuant des
// opérations d'affichage, d'ajout et de recherche.

//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void ChercherParcoursA(const char *deb, const char *fin) const;
    // Parametres formels:
    // deb:fait reference au depart
    // fin:fait reference à la destionation
    //  Mode d'emploi :
    //  Recherche et affiche les trajets du catalogue permettant d'aller de deb à fin.
    //  Prends le départ et l'arrivée du parcours à chercher en paramètre.
    //  Contrat :
    //  La méthode ne modifie pas les attributs de la classe. Le catalogue ne doit pas être vide.

    void ChercherParcoursB(const char *deb, const char *fin);
    // Parametres formels:
    // deb:fait reference au depart
    // fin:fait reference à la destionation
    // Mode d'emploi :
    // Affiche les combinaisons de trajets du catalogue permettant d'aller de deb à fin.
    // Prends le départ et l'arrivée du parcours à chercher en paramètre.
    // Contrat :
    // La méthode ne modifie pas l'attribut Catal de la classe mais seulement l'attribut matrice.
    // Le catalogue ne doit pas être vide.

    void Afficher() const;
    // Mode d'emploi :
    // Affiche tous les trajets contenus dans le catalogue.
    // Contrat :
    // La méthode ne modifie pas les attributs de la classe.

    void Inserer(Trajet *Tr);
    // Parametres formels:
    // Tr:pointeur sur un objet de la classe Trajet
    // Mode d'emploi :
    // Insère un trajet simple ou composé passé en paramètre dans le catalogue.

    int GetSize() const;
    // Mode d'emploi :
    // Retourne le nombre de trajets qu'il contient.

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi :
    // Constructeur de Catalogue

    virtual ~Catalogue();
    // Mode d'emploi :
    // Destructeur de Catalogue

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
    TableauDynamique Catal;
    int **matrice;

private:
    //----------------------------------------------------- Méthodes protégées
    void Creer(void);
    // Mode d'emploi :
    // Cree la matrice d'adjacence pour representer le graphe

    void DFS(int *visited, int current, int destination, int path[], int pathIndex, bool *found);
    // Parametres formels:
    // visited: Un tableau d'entiers qui indique si chaque sommet a été visité ou non.
    // current: L'index du sommet courant.
    // destination: L'index du sommet de destination.
    // path: Un tableau d'entiers qui stocke le chemin actuel.
    // pathIndex: L'index actuel dans le tableau path.
    // found: Un pointeur vers un booléen qui indique si un chemin a été trouvé ou non.

    // Mode d'emploi :
    // Implémente l'algorithme de recherche en profondeur pour trouver tous les chemins possibles entre deux points dans un graphe.
};
#endif // CATALOGUE_H
