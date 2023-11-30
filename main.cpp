#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include <cstring>
using namespace std;

int main()
{
    // char* deb = new char[2];  // Including null terminator
    // strcpy(deb, "A");

    // // Allocate memory for "B" and copy it to fin
    // char* fin = new char[2];  // Including null terminator
    // strcpy(fin, "B");

    // // Allocate memory for "T1" and copy it to moy
    // char* moy = new char[3];  // Including null terminator
    // strcpy(moy, "T1");
   
    TrajetSimple*traj=new TrajetSimple("A","B","T1");
    TrajetCompose trajC1=TrajetCompose("A","B");
    TrajetSimple*traj2=new TrajetSimple("B","C","T1");
    TrajetCompose trajC2=TrajetCompose("B","C");
    TrajetSimple*traj3=new TrajetSimple("A","C","T1");
    TrajetCompose trajC3=TrajetCompose("A","E");
    TrajetSimple*traj4=new TrajetSimple("E","C","T1");
    TrajetCompose trajC4=TrajetCompose("E","C");
    TrajetSimple*traj5=new TrajetSimple("B","E","T1");
    TrajetCompose trajC5=TrajetCompose("B","E");
    trajC1.Inserer(traj);
    Catalogue C=Catalogue();
    C.Inserer(traj);
    C.Inserer(traj2);
    C.Inserer(traj3);
    C.Inserer(traj4);
    C.Inserer(traj5); 
    C.ChercherB("A","C");

    // C.Creer();
    // TrajetSimple traj2(deb,fin,moy);
    //traj->Afficher();

    // delete[] deb;
    // delete[] fin;
    // delete[] moy;

    delete traj;
    
    delete traj2;
    
    delete traj3;
    
    delete traj4;
    
    delete traj5;
    
    
}