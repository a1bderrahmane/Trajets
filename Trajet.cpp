/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
char* Trajet::getDepart()const
{
    return depart;
}
char* Trajet::getArrivee()const
{
    return arrivee;
}
//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


Trajet::Trajet(const char *dep,const char *arr) 
// Algorithme :
//
{
depart=new char[strlen(dep)+1];
strcpy(depart,dep);

arrivee=new char[strlen(arr)+1];
strcpy(arrivee,arr);
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

Trajet::~Trajet()
// Algorithme :
//
{
delete []depart;
delete []arrivee;

#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
