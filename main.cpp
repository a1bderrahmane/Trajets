#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

using namespace std;
#include <iostream>
#include <cstring>

int main()
{
    cout << endl
         << "Bienvenue dans votre gestionnaire de trajets!" << endl;
    Catalogue C;
    while (1)
    {
        cout << endl
             << endl
             << endl;
        cout << "--------------------"
             << " MENU "
             << "--------------------";
        cout << endl;
        cout << "    1: Afficher le contenu du catalogue de trajets" << endl;
        cout << "    2: Ajouter un trajet simple au catalogue" << endl;
        cout << "    3: Ajouter un trajet composé au catalogue" << endl;
        cout << "    4: Chercher un parcours simple" << endl;
        cout << "    5: Chercher un parcours composé de plusieurs trajets différents" << endl;
        cout << "    6: Quitter l'application" << endl;
        int choix;
        cin >> choix;
        while (cin.fail() || choix > 6 || choix < 1)
        {
            cout << endl;
            cout << "Erreur de saisie, entrez un nombre entre 1 et 4" << endl;
            cin >> choix;
        }

        switch (choix)
        {
        case 1:
        {
            cout << endl
                 << endl;
            C.Afficher();
            break;
        }

        case 2:
        {
            cout << endl
                 << endl;
            char *dep = new char[100];
            char *arr = new char[100];
            char *MT = new char[100];
            cout << "Entrez une ville de départ: ";
            cin >> dep;
            cout << "Entrez une ville d'arrivée: ";
            cin >> arr;
            cout << "Entrez un moyen de transport: ";
            cin >> MT;
            TrajetSimple *T = new TrajetSimple(dep, arr, MT);
            C.Inserer(T);

            delete[] dep;
            delete[] arr;
            delete[] MT;
            break;
        }

        case 3:
        {
            cout << endl
                 << endl;
            char *dep = new char[100];
            char *arr = new char[100];
            char *MT = new char[100];

            TrajetCompose *TC;

            int i = 1;
            while (1)
            {
                cout << "Veuillez saisir le " << i << "ème"
                     << " trajet (Entrez 'FIN' pour terminer) : " << endl
                     << endl;
                cout << "Entrez une ville de départ: ";
                cin >> dep;
                if (!strcmp(dep, "FIN"))
                {
                    break;
                }
                cout << "Entrez une ville d'arrivée: ";
                cin >> arr;
                if (!strcmp(arr, "FIN"))
                {
                    break;
                }
                cout << "Entrez un moyen de transport: ";
                cin >> MT;
                if (!strcmp(MT, "FIN"))
                {
                    break;
                }
                cout << endl
                     << endl;

                if (i == 1)
                {
                    TC = new TrajetCompose(dep, arr, MT);
                    i++;
                    continue;
                }
                i++;
                if (!TC->AjouterTrajet(dep, arr, MT))
                {
                    cout << "Erreur, veuillez entrer un trajet ayant pour départ la même ville que l'arrivée du trajet précédent" << endl
                         << endl
                         << endl;
                    i--;
                }
            }
            if (TC->GetSize() == 0)
            {
                delete[] TC;
            }
            else
            {
                C.Inserer(TC);
            }
            delete[] dep;
            delete[] arr;
            delete[] MT;
            break;
        }

        case 4:
        {
            cout << endl
                 << endl;
            if (C.GetSize() == 0)
            {
                cout << "Le catalogue est vide, aucun parcours possible. Essayez d'ajouter des trajets." << endl;
                break;
            }
            char *dep = new char[100];
            char *arr = new char[100];
            cout << "Entrez la ville de départ de votre trajet: ";
            cin >> dep;
            cout << endl;

            cout << "Entrez la ville d'arrivée de votre trajet: ";
            cin >> arr;
            cout << endl;

            C.ChercherParcoursA(dep, arr);
            delete[] dep;
            delete[] arr;
            break;
        }

        case 5:
        {
            cout << endl
                 << endl;
            if (C.GetSize() == 0)
            {
                cout << "Le catalogue est vide, aucun parcours possible. Essayez d'ajouter des trajets" << endl;
                break;
            }
            char *dep = new char[100];
            char *arr = new char[100];

            cout << "Entrez la ville de départ de votre trajet: ";
            cin >> dep;
            cout << endl;

            cout << "Entrez la ville d'arrivée de votre trajet: ";
            cin >> arr;
            cout << endl;

            C.ChercherParcoursB(dep, arr);
            delete[] dep;
            delete[] arr;
            break;
        }

        case 6:
        {
            return 0;
        }

        default:
        {
            continue;
        }
        }
    }
    /* TrajetSimple *traj = new TrajetSimple("A", "B", "T1");
    TrajetCompose trajC1 = TrajetCompose("A", "B", "T2");
    TrajetSimple *traj2 = new TrajetSimple("B", "C", "T1");
    TrajetCompose trajC2 = TrajetCompose("B", "C", "T2");
    TrajetSimple *traj3 = new TrajetSimple("A", "C", "T1");
    TrajetCompose trajC3 = TrajetCompose("A", "E", "T2");
    TrajetSimple *traj4 = new TrajetSimple("E", "C", "T1");
    TrajetCompose trajC4 = TrajetCompose("E", "C", "T2");
    TrajetSimple *traj5 = new TrajetSimple("B", "E", "T1");
    TrajetCompose trajC5 = TrajetCompose("B", "E", "T2");
    trajC1.AjouterTrajet("A", "B", "T1");

    Catalogue C = Catalogue();
    C.Inserer(traj);
    C.Inserer(traj2);
    C.Inserer(traj3);
    C.Inserer(traj4);
    C.Inserer(&trajC5);
    C.ChercherParcoursB("A", "C"); */

    /* delete traj2;

    delete traj3;

    delete traj4;

    delete traj5;
    return 0;*/
}