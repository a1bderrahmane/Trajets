/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#define MAXB 1000

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Catalogue::Inserer(Trajet*ptr)
{

    if(allocated==filled){
        allocated*=2;
        Trajet** tab2=new Trajet*[allocated];
        for(int i=0;i<filled;i++){
            tab2[i]=Catal[i];
        }
        Catal=tab2;
        delete []tab2;
    }
    Catal[filled]=ptr;
    filled ++;
}
void Catalogue::Afficher(void)const
{
     for (int i=0;i<filled;i++){
        cout<<"Le trajet"<<i<<" est : "<<endl;
        Catal[i]->Afficher();
    }
}

void Catalogue::ChercherA(const char*deb,const char*fin)const
{
    for(int i=0;i<filled;i++)
    {
        if(strcmp(Catal[i]->getDepart(),deb)==1 && strcmp(Catal[i]->getArrivee(),fin))
        {
            Catal[i]->Afficher();
        }
    }
}
//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue()
// Algorithme :
//
{
    allocated=MAXB;
    filled=0;
    Catal=new Trajet*[sizeof(Trajet*)*allocated];
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
    delete[]Catal;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
