/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
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
// Cherche tous les trajets possibles entre deux points donnés dans le catalogue.
// Si aucun trajet n'est trouvé, un message d'erreur est affiché.
{
    int i;
    int res = 0;
    cout << "--------------------" << endl
         << "Liste des trajets du catalogue permettant d'aller de " << deb << " à " << fin << ":" << endl
         << endl;

    // Parcourir tous les trajets du catalogue
    for (i = 0; i < Catal.GetSize(); i++)
    {
        // Si le trajet est entre les deux points donnés en parametres
        if (!strcmp(Catal[i]->GetDepart(), deb) && !strcmp(Catal[i]->GetArrivee(), fin))
        {
            // Marquer que le trajet est trouvé
            res = 1;

            cout << endl;
            Catal[i]->Afficher();
        }
    }
    // Si aucun trajet n'est trouvé
    if (res == 0)
    {
        // Afficher un message d'erreur
        cout << endl
             << "Aucun parcours possible avec les trajets du catalogue, essayez d'ajouter des trajets ou d'effectuer une recherche avancée." << endl;
    }
} //----- Fin de Méthode

void Catalogue::Afficher() const
// Algorithme :
// Affiche tous les trajets contenus dans le catalogue.
// Si le catalogue est vide, un message d'erreur est affiché.
{
    // Vérifier si le catalogue est vide
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

        // Parcourir tous les trajets du catalogue
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
// Utilise la méthode Ajouter de la classe TableauDynamique
{
    Catal.Ajouter(Tr);
} //----- Fin de Méthode

int Catalogue::GetSize() const
// Algorithme :
// Utilise la méthode GetSize de la classe TableauDynamique
{
    return Catal.GetSize();
} //----- Fin de Méthode

void Catalogue::ChercherParcoursB(const char *deb, const char *fin)
// Algorithme :
// Cherche tous les parcours possibles entre deux points donnés dans le catalogue.
// Elle utilise la méthode DFS (Depth-First Search) pour trouver tous les chemins possibles entre ces deux points.
{
    // Afficher un message pour indiquer le début de la recherche
    cout << "--------------------" << endl
         << "Liste des combinaisons de trajets de catalogue permettant d'aller de " << deb << " à " << fin << ":" << endl;

    // Créer la matrice d'adjacence pour représenter le graphe
    Creer();
    // Allocation de la mémoire au tableau visited pour marquer les nœuds visités
    int *visited = new int[Catal.GetSize()];

    // Allocation de la mémoire au tableau path pour stocker le chemin actuel
    int *path = new int[Catal.GetSize()];

    // Initialiser un index pathIndex pour suivre l'index actuel dans le chemin
    int pathIndex = 0;

    // Initialiser un booléen found pour indiquer si un chemin est trouvé
    bool found = false;

    // Marquer tous les nœuds comme non visités
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        visited[i] = 0;
    }

    int start;
    int destination;

    // Parcourir tous les nœuds du catalogue
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        // Si le nœud est l'arrivee
        if (!strcmp(Catal[i]->GetArrivee(), fin))
        {
            // Enregistrer l'index du nœud comme destination
            destination = i;
            for (int i = 0; i < Catal.GetSize(); i++)
            {
                // Si le nœud est le depart
                if (!strcmp(Catal[i]->GetDepart(), deb))
                {
                    // Enregistrer l'index du nœud comme debut
                    start = i;

                    // Appeler la fonction DFS pour trouver tous les chemins possibles entre le départ et la destination
                    DFS(visited, start, destination, path, pathIndex, &found);

                    // Marquer tous les nœuds comme non visités pour la prochaine recherche
                    for (int i = 0; i < Catal.GetSize(); i++)
                    {
                        visited[i] = 0;
                    }
                }
            }
        }
    }
    // Si aucun chemin n'est trouvé, afficher un message d'erreur
    if (!found)
    {
        cout << "Aucun parcours possible avec les trajets du catalogue, essayez d'ajouter des trajets." << endl;
    }
    // Libérer la mémoire allouée pour le tableau visited et le tableau path
    delete[] visited;
    delete[] path;
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    matrice = nullptr;
} //----- Fin de Catalogue

Catalogue::~Catalogue()
// Algorithme :
//    Si la matrice n'est pas nulle, alors pour chaque ligne de la matrice, libérer la mémoire allouée pour cette ligne.
//    Après avoir libéré toutes les lignes, libérer la mémoire allouée pour la matrice.
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    if (matrice)
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
// Crée une matrice d'adjacence pour représenter un graphe.
// Chaque élément de la matrice indique si il y a une arête entre deux nœuds.
// Les nœuds sont représentés par les éléments du catalogue.
// Les arêtes sont représentées par les relations entre les départs et les arrivées des éléments du catalogue.
{
    // Allouer de la mémoire pour la matrice
    matrice = (int **)new int *[sizeof(int *) * Catal.GetSize()];
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        matrice[i] = new int[sizeof(int) * Catal.GetSize()];
    }
    // Parcourir chaque paire de nœuds dans le catalogue
    for (int i = 0; i < Catal.GetSize(); i++)
    {
        for (int j = 0; j < Catal.GetSize(); j++)
        {
            // Si la destination de l'élément i est égale au départ de l'élément j
            if (!strcmp(Catal[i]->GetArrivee(), Catal[j]->GetDepart()))
            {
                matrice[i][j] = 1;
            }
            else
            {
                // Il n'y a pas d'arête entre les deux nœuds, donc mettre 0 dans la matrice
                matrice[i][j] = 0;
            }
        }
    }
} // Fin de Creer

void Catalogue::DFS(int *visited, int current, int destination, int path[], int pathIndex, bool *found) const
// Algorithme :
//    Marquer le nœud courant comme visité.
//    Ajouter le nœud courant au chemin.
//    Si le nœud courant est la destination, alors afficher le chemin.
//    Sinon, pour chaque nœud adjacent au nœud courant qui n'a pas encore été visité, appeler récursivement l'algorithme DFS.
//    Après avoir visité tous les nœuds adjacents, retourner le nœud courant à l'état non visité pour la recherche en profondeur.
{
    // Marquer le nœud courant comme visité
    visited[current] = 1;
    // Ajouter le nœud courant au chemin
    path[pathIndex] = current;
    pathIndex++;
    // Si le nœud courant est la destination
    if (current == destination)
    {
        if (!(*found))
        {
            // Définir la destination comme trouvée
            *found = true;
        }
        // Afficher le chemin
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
        // Parcourir tous les nœuds adjacents
        for (int i = 0; i < Catal.GetSize(); i++)
        {
            // Si le nœud adjacent n'a pas encore été visité
            if (matrice[current][i] == 1 && !visited[i])
            {
                // Appeler la fonction DFS récursivement pour le nœud adjacent
                DFS(visited, i, destination, path, pathIndex, found);
            }
        }
    }
    // Retourner le nœud courant à l'état non visité pour la recherche en profondeur
    visited[current] = 0; // Backtrack
} // Fin de DFS
//----------------------------------------------------- Méthodes protégées
