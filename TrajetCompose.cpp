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
#define MAX 1000
//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Inserer(Trajet*tr)
{
    if(allocated==filled){
        allocated*=2;
        Trajet** tab2=new Trajet*[allocated];
        for(int i=0;i<filled;i++){
            tab2[i]=tab[i];
        }
        tab=tab2;
        delete []tab2;
    }
    tab[filled]=tr;
    filled ++;
}

void TrajetCompose::Afficher(void)const
{
    for (int i=0;i<filled;i++){
        cout<<"Le trajet intermédiaire "<<i<<" est : "<<endl;
        tab[i]->Afficher();
    }
}


//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose(const char*dep,const char*arr):Trajet(dep,arr)
{
    allocated=MAX;
    filled=0;
    tab = new Trajet*[sizeof(Trajet*)*allocated];
    
    
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
delete[]tab;
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
