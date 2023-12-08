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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::ChercherParcoursA(const char *deb, const char *fin) const
// Algorithme :
//
{
    int i;
    int res = 0;
    cout << "--------------------" << endl
         << "Liste des trajets du catalogue permettant d'aller de " << deb << " à " << fin << ":" << endl
         << endl;

    for (i = 0; i < Catal.GetSize(); i++)
    {
        if (!strcmp(Catal[i]->GetDepart(), deb) && !strcmp(Catal[i]->GetArrivee(), fin))
        {
            res = 1;
            cout << endl;
            Catal[i]->Afficher();
        }
    }
    if (res == 0)
    {
        cout << endl
             << "Aucun parcours possible avec les trajets du catalogue, essayez d'ajouter des trajets ou d'effectuer une recherche avancée." << endl;
    }
} //----- Fin de Méthode

void Catalogue::Afficher() const
// Algorithme :
//
{
    if (Catal.GetSize() == 0)
    {
        cout << endl
             << "Le catalogue de trajets est vide, essayez d'ajouter de nouveaux trajets." << endl
             << endl;
    }
    else
    {
        cout << "--------------------" << endl
             << "Liste des trajets contenues dans le catalogue: " << endl;
        for (int i = 0; i < Catal.GetSize(); i++)
        {
            cout << endl;
            cout << "    ";
            cout << "- ";
            Catal[i]->Afficher();
            cout << "        --" << endl;
        }
    }
} //----- Fin de Méthode

void Catalogue::Inserer(Trajet *Tr)
// Algorithme :
//
{
    Catal.Ajouter(Tr);
} //----- Fin de Méthode

int Catalogue::GetSize()
// Algorithme :
//
{
    return Catal.GetSize();
} //----- Fin de Méthode

void Catalogue::ChercherParcoursB(const char *deb, const char *fin)
{
    cout << "--------------------" << endl
         << "Liste des combinaisons de trajets de catalogue permettant d'aller de " << deb << " à " << fin << ":" << endl;
    Creer();
    int *visited = new int[Catal.GetSize()];
    int *path = new int[Catal.GetSize()];
    int pathIndex = 0;
    bool found = false;
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        visited[i] = 0;
    }
    int start;
    int destination;
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        if (!strcmp(Catal[i]->GetArrivee(), fin))
        {
            destination = i;
            for (int i = 0; i < Catal.GetSize(); i++)
            {
                if (!strcmp(Catal[i]->GetDepart(), deb))
                {
                    start = i;
                    DFS(visited, start, destination, path, pathIndex, &found);
                    for (int i = 0; i < Catal.GetSize(); i++)
                    {
                        visited[i] = 0;
                    }
                }
            }
        }
    }
    if (!found)
    {
        cout << "Aucun parcours possible avec les trajets du catalogue, essayez d'ajouter des trajets." << endl;
    }
    delete[] visited;
    delete[] path;
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    matrice = (int **)new int *[sizeof(int *)];
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    if (matrice != NULL)
    {
        for (int i = 0; i < Catal.GetSize(); i++)
        {
            delete[] matrice[i];
        }
        delete[] matrice;
    }
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE
void Catalogue::Creer(void)
// Algorithme :
//
{
    delete[] matrice;
    matrice = (int **)new int *[sizeof(int *) * Catal.GetSize()];
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        matrice[i] = new int[sizeof(int) * Catal.GetSize()];
    }
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        for (int j = 0; j < Catal.GetSize(); j++)
        {
            if (!strcmp(Catal[i]->GetArrivee(), Catal[j]->GetDepart()))
            {
                matrice[i][j] = 1;
            }
            else
            {
                matrice[i][j] = 0;
            }
        }
    }
} // Fin de Creer

void Catalogue::DFS(int *visited, int current, int destination, int path[], int pathIndex, bool *found)
// Algorithme :
//
{
    visited[current] = 1;
    path[pathIndex] = current;
    pathIndex++;

    if (current == destination)
    {
        if (!(*found))
        {
            *found = true;
        }
        // Print the pathmatrice=NULL;
        cout << endl;
        for (int i = 0; i < pathIndex; i++)
        {
            cout << "    ";
            cout << "- ";
            Catal[path[i]]->Afficher();
        }
        cout << "        --" << endl;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < Catal.GetSize(); i++)
        {
            if (matrice[current][i] == 1 && !visited[i])
            {
                DFS(visited, i, destination, path, pathIndex, found);
            }
        }
    }
    visited[current] = 0; // Backtrack
} // Fin de DFS
//----------------------------------------------------- Méthodes protégées
