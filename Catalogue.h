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
//
//
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void ChercherParcoursA(const char *deb, const char *fin) const;
    //Parametres formels:
    //deb:fait reference au depart 
    //fin:fait reference à la destionation
    // Mode d'emploi :
    //chercher tous les trajets possibles directs entre ces 
    //deux points dans le catalogue. 
    //Si aucun trajet n'est trouvé, un message d'erreur est affiché.
    

    void ChercherParcoursB(const char *deb, const char *fin);
    //Parametres formels:
    //deb:fait reference au depart 
    //fin:fait reference à la destionation
    // Mode d'emploi :
    // Chercher tous les trajets possibles entre ces deux points dans le catalogue.
    // Si aucun trajet n'est trouvé, un message d'erreur est affiché.
    

    void Afficher() const;
    // Mode d'emploi :
    //Afficher tous les trajets contenus dans le catalogue.
    

    void Inserer(Trajet *Tr);
    //Parametres formels:
    //Tr:pointeur sur un objet de la classe Trajet

    int GetSize() const;
    // Mode d'emploi :
    //Retourne le nombre de trajets qu'il contient.
    

    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    TableauDynamique Catal;
    int **matrice;

private:
    void Creer(void);
    // Mode d'emploi :
    //Cree la matrice d'adjacence pour representer le graphe 
    
    
    void DFS(int *visited, int current, int destination, int path[], int pathIndex, bool *found);
    //Parametres formels:
    //visited: Un tableau d'entiers qui indique si chaque sommet a été visité ou non.
    //current: L'index du sommet courant.
    //destination: L'index du sommet de destination.
    //path: Un tableau d'entiers qui stocke le chemin actuel.
    //pathIndex: L'index actuel dans le tableau path.
    //found: Un pointeur vers un booléen qui indique si un chemin a été trouvé ou non.

    // Mode d'emploi :
    //Implémente l'algorithme de recherche en profondeur  pour trouver tous les chemins possibles entre deux points dans un graphe.
    

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
