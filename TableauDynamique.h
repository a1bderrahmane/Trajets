/*************************************************************************
                           Tableaudynamique  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Tableaudynamique> (fichier Tableaudynamique.h) ----------------
#if !defined(TABLEAUDYNAMIQUE_H)
#define TABLEAUDYNAMIQUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TableauDynamique>
// La classe tableau dynamique implémente une structure de tableau dynamique, utilisée par Catalogue et par TrajetCompose
//------------------------------------------------------------------------

class TableauDynamique
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void Ajouter(Trajet *&Tr);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetSize() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    // ------------------------------------------- Surcharge d'opérateurs
    Trajet *&operator[](int index) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    TableauDynamique();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TableauDynamique();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void Agrandir(int newTaille);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    Trajet **tabTrajets;
    int filled;
    int allocated;
};

//-------------------------------- Autres définitions dépendantes de <TableauDynamique>

#endif // TABLEAUDYNAMIQUE_H
