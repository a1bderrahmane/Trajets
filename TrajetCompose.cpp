/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par DRAVET Eléonore, BOUZIANE Abderrahmane, WIRANE Hamza, VIALLETON Rémi
    e-mail               : eleonore.dravet@insa-lyons.fr
                           abderrahmane.bouziane@insa-lyon.fr
                           hamza.wirane@insa-lyon.fr
                           remi.vialleton@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

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
        cout << "    ";
        tabTrajets[i]->Afficher();
    }
} //----- Fin de Méthode

int TrajetCompose::GetSize() const
// Algorithme :
// Utilise la méthode GetSize() de la classe TableauDynamique pour avoir le nombre d'éléments de tabTrajets
//
{
    return tabTrajets.GetSize();
} //----- Fin de Méthode

int TrajetCompose::AjouterTrajet(const char *dep, const char *arr, const char *MT)
// Algorithme :
// Ajoute un nouveau trajet à la fin de la liste de trajets.
// Si la liste contient plus qu'un trajet,elle vérifie si l'arrivée du nouveau trajet correspond à l'arrivée du dernier trajet de la liste.
// Si la correspondance est trouvée, ajoute le nouveau trajet à la liste et met à jour l'arrivée de l'objet `TrajetCompose`.
// Si la correspondance n'est pas trouvée, la méthode retourne 0 sans ajouter le nouveau trajet.
// Si la liste est vide, ajoute le nouveau trajet sans vérifier la correspondance.
// Retourne 1 si le nouveau trajet a été ajouté avec succès
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
