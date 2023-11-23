/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

void TrajetSimple::Afficher()const
{
    cout<<"départ : "<<Trajet::depart<<endl;
    cout<<"arrivée : "<<Trajet::arrivee<<endl;
    cout<<"moyen de transport : "<<moyenTransport<<endl;
}
//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple(const char* deb,const char*arr,const char*moy):Trajet(deb,arr)
// Algorithme :
//
{
moyenTransport=new char[strlen(moy)+1];
strcpy(moyenTransport,moy);
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
};//----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme :
//
{
delete []moyenTransport;

#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
