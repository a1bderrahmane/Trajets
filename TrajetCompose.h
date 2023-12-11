/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TableauDynamique.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// La classe TrajetCompose hérite publiquement de Trajet
// Un trajet composé est un trajet composé de trajets simples dont la ville d'arrivée
// de chaque trajet simple doit correspondre à la ville de départ du trajet suivant

//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
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
    // Ajout d'un trajetSimple à Tabtrajets pour composer un trajetCompose

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
    //----------------------------------------------------- Attributs protégés
    TableauDynamique tabTrajets;
};

#endif // TRAJETCOMPOSE_H
