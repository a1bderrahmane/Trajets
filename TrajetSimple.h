/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques
  void Afficher() const;
  // Mode d'emploi :
  // Affichage de base d'un trajet avec départ, arrivée et moyen de transport
  // Contrat :
  // Ne modifie pas les attributs de la classe

  //-------------------------------------------- Constructeurs - destructeur
  TrajetSimple(const char *MT, const char *dep, const char *arr);
  // Mode d'emploi :
  // Créer un trajet avec un départ (dep) et une arrivée (arr) et alloue de la mémoire
  // pour copier le paramètre MT dans l'attribut moyenTransport

  virtual ~TrajetSimple();
  // Mode d'emploi :
  // Libére la mémoire allouée dynamiquement pour l'attribut moyenTransport

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées

  //----------------------------------------------------- Attributs protégés
  char *moyenTransport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
