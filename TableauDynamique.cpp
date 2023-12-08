/*************************************************************************
                           TableauDynamique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TableauDynamique> (fichier TableauDynamique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TableauDynamique.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TableauDynamique::Ajouter(Trajet *&Tr)
// Algorithme :
//
//
{
    tabTrajets[filled] = Tr;
    filled++;
    if (filled == allocated)
    {
        Agrandir(allocated * 2);
    }
} //----- Fin de Méthode

int TableauDynamique::GetSize() const
{
    return filled;
} //----- Fin de Méthode

Trajet *&TableauDynamique::operator[](int index) const
// Algorithme s:
//
//
{
    if (index > filled)
    {
        throw out_of_range("Index du tableau out of range");
    }
    return tabTrajets[index];
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
TableauDynamique::TableauDynamique()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif
    tabTrajets = new Trajet *[sizeof(Trajet *)];
    filled = 0;
    allocated = 1;
} //----- Fin de TableauDynamique

TableauDynamique::~TableauDynamique()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TableauDynamique>" << endl;
#endif
    int i;
    for (i = 0; i < filled; i++)
    {
        // cout << "Destruction d'un trajet de tableau dynamique" << tabTrajets[i]->GetDepart() << "-> " << tabTrajets[i]->GetArrivee() << endl;
        delete tabTrajets[i];
    }
    // cout << "Fin de suppression tableau dynamique" << endl;
    delete[] tabTrajets;
} //----- Fin de ~TableauDynamique

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void TableauDynamique::Agrandir(int taille)
// Algorithme :
//
//
{
    Trajet **newTabTrajets = new Trajet *[taille * sizeof(Trajet)];
    int i;
    for (i = 0; i < filled; i++)
    {
        newTabTrajets[i] = tabTrajets[i];
    }
    delete[] tabTrajets;
    tabTrajets = newTabTrajets;
    allocated = taille;
} //----- Fin de Méthode
