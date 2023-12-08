/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const
// Algorithme :
//
//
{
    cout << "Trajet composé: " << endl;
    int i;
    for (i = 0; i < tabTrajets.GetSize(); i++)
    {
        cout << "    "
             << "- ";
        tabTrajets[i]->Afficher();
    }
} //----- Fin de Méthode

int TrajetCompose::GetSize() const
// Algorithme :
//
//
{
    return tabTrajets.GetSize();
} //----- Fin de Méthode

int TrajetCompose::AjouterTrajet(const char *dep, const char *arr, const char *MT)
// Algorithme :
//
//
{
#ifdef MAP
    cout << "Ajout d'un trajet à <TrajetCompose>" << endl;
#endif
    if (tabTrajets.GetSize() != 1)
    {
        if (strcmp(tabTrajets[tabTrajets.GetSize() - 1]->GetArrivee(), dep))
        {
            return 0; // Pas de correspondance du départ avec l'arrivée du trajet précédent.}
        }
    }
    Trajet *ts = new TrajetSimple(dep, arr, MT);
    tabTrajets.Ajouter(ts);
    SetArrivee(arr);
    return 1;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const char *dep, const char *arr, const char *MT) : Trajet(dep, arr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    Trajet *ts = new TrajetSimple(dep, arr, MT);
    tabTrajets.Ajouter(ts);
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
