/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ChercherParcoursB(const char *deb, const char *fin);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Inserer(Trajet *Tr);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetSize();
    // Mode d'emploi :
    //
    // Contrat :
    //

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
    void DFS(int *visited, int current, int destination, int path[], int pathIndex, bool *found);

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
