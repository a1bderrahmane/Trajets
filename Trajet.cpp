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

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Trajet::SetArrivee(const char *arr)
// Algorithme :
//
{
    char *newArrivee = new char[strlen(arr) + 1];
    strcpy(newArrivee, arr);
    delete[] arrivee;
    arrivee = newArrivee;
} //----- Fin de Trajet

char *Trajet::GetDepart() const
// Algorithme :
//
{
    return depart;
} //----- Fin de Trajet

char *Trajet::GetArrivee() const
// Algorithme :
//
{
    return arrivee;
} //----- Fin de Trajet
Trajet::Trajet(){}
//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet(const char *dep, const char *arr)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    depart = new char[strlen(dep) + 1];
    arrivee = new char[strlen(arr) + 1];
    strcpy(depart, dep);
    strcpy(arrivee, arr);
} //----- Fin de Trajet

Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~Trajet