/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const = 0;
    // Mode d'emploi :
    //Affichage d'un trajet
    

    char *GetArrivee() const;
    // Mode d'emploi :
    //Renvoie l'arrivée du trajet
    

    char *GetDepart() const;
    // Mode d'emploi :
    //renvoie le depart du trajet
    

    void SetArrivee(const char *arr);
    // Mode d'emploi :
    // affecte à l'attribut arrivée une valeur arr

    //-------------------------------------------- Constructeurs - destructeur
    Trajet(const char *dep, const char *arr);
    // Mode d'emploi :
    //Constructeur de la classe trajet
    

    virtual ~Trajet();
    // Mode d'emploi :
    //Destructeur de Trajet
    

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    char *depart;
    char *arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
