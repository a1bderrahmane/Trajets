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

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe abstraite permettant de gérer les attributs de base (depart et arrivee) d'un trajet,
// qu'il soit simple ou composé.

//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Méthode virtuelle pure pour redéfinir l'affichage

    char *GetArrivee() const;
    // Mode d'emploi :
    // Renvoie l'arrivée du trajet

    char *GetDepart() const;
    // Mode d'emploi :
    // Renvoie le depart du trajet

    void SetArrivee(const char *arr);
    // Mode d'emploi :
    // Affecte à l'attribut arrivee une valeur arr

    //-------------------------------------------- Constructeurs - destructeur
    Trajet(const char *dep, const char *arr);
    // Mode d'emploi :
    // Affecte les valeurs dep et arr aux attributs depart et arrivee

    virtual ~Trajet();
    // Mode d'emploi :
    // Libère la mémoire allouée pour depart et arrivee

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    char *depart;
    char *arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
