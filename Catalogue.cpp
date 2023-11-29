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
void Catalogue::ChercherB(const char*deb,const char*fin)
{
    Creer();
    int visited[filled];
    int path[filled];
    int pathIndex =0;
    for(int i=0;i<filled;i++)
    {
        visited[i]=0;
    }
    int start;
    int destination;
    for(int i=0;i<filled;i++)
    {
        if (!strcmp(Catal[i]->getArrivee(),fin))
        {
            destination=i;
            break;
        }
    }
    for(int i=0;i<filled;i++)
    {
        if(!strcmp(Catal[i]->getDepart(),deb))
        {
            start=i;
            printf("Trajets de %s à %s:\n", deb, fin);
            DFS(visited, start, destination, path, pathIndex);
            for(int i=0;i<filled;i++)
            {
                visited[i]=0;
            }
        }
    }
    
    
}
void Catalogue::DFS( int *visited, int current, int destination, int path[], int pathIndex) 
{
    visited[current] = 1;
    path[pathIndex] = current;
    pathIndex++;

    if (current == destination) {
        // Print the pathmatrice=NULL;
        for (int i = 0; i < pathIndex; i++) {
            printf("%s-> %s ", Catal[path[i]]->getDepart(),Catal[path[i]]->getArrivee());
        }
        printf("\n");
    } else {
        for (int i = 0; i <filled; i++) {
            if (matrice[current][i] == 1 && !visited[i]) {
                DFS( visited, i, destination, path, pathIndex);
            }
        }
    }
    visited[current] = 0; // Backtrack
}

//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue()
// Algorithme :
//
{
    allocated=MAXB;
    filled=0;
    Catal=new Trajet*[sizeof(Trajet*)*allocated];
    Creer();

#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
    if (matrice !=NULL)
    {
        for(int i=0;i<filled;i++)
        {
            delete[]matrice[i];
        }
        delete []matrice;
    }
    delete[]Catal;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

void Catalogue::Creer(void)
{
    matrice=(int **)new int*[sizeof(int*)*filled];
    for(int i=0;i<filled;i++)
    {
        matrice[i]=new int[sizeof(int)*filled];
    }
    for(int i=0;i<filled;i++)
    {
        for(int j=0;j<filled;j++)
        {
            if(!strcmp(Catal[i]->getArrivee(),Catal[j]->getDepart()))
            {
                matrice[i][j]=1;
                
            }
            else
            {
                matrice[i][j]=0;
            }
        }
    }
    
}




//----------------------------------------------------- Méthodes protégées
