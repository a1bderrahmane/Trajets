/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Afficher(void)const;
    void Inserer(Trajet*tr);
    //------------------------------------------------- Surcharge d'opérateurs


    //-------------------------------------------- Constructeurs - destructeur
    
    TrajetCompose(const char*dep,const char*arr);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Trajet **tab ;
    int filled;
    int allocated;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
