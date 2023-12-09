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
#include "TrajetSimple.h"
#include "TableauDynamique.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// La classe TrajetCompose hérite publiquement de Trajet 
// Un trajet composé est un trajet dont la ville d'arrivée d'un trajet simple doit
// correspondre à la ville de départ du trajet suivant

//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    //----------------------------------------------------- Méthodes publiques
    void Afficher() const;
    // Mode d'emploi :
    // Parcours de Tabtrajets des trajetsSimple composants un trajetCompose
    // pour les afficher un à un sur la sortie standard avec leurs
    // caractéristiques (villes d'arrivée, de départ, et transport)
    

    int GetSize() const;
    // Mode d'emploi :
    // Récuperer la taille de Tabtrajets

    int AjouterTrajet(const char *MT, const char *dep, const char *arr);
    // Mode d'emploi :
    //Ajout d'un trajetSimple à Tabtrajets pour composer un trajetCompose
    
    
    //-------------------------------------------- Constructeurs - destructeur
    TrajetCompose(const char *MT, const char *dep, const char *arr);
    // Mode d'emploi :
    // Crée un trajet compose à partir de trajet simple 
    // avec un départ , une arrivée , et un moyen de transport
    

    virtual ~TrajetCompose();
    // Mode d'emploi :   
    // Libére la mémoire allouée dynamiquement aux attributs de la classe

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    TableauDynamique tabTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
