#include <iostream>
#include "caso.h"
#include "partie.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
      int k;
      partie p;
      while (1)
      {
      cout<<"\033[1;36m"<<"        ****************************************************************\n"
                         "        *                                                              *\n"
                         "        *      **      **                               **      **      *\n"
                         "        **   **  **  **  **      1. Nouvelle partie      **  **  **  ***\n"
                         "        *  **      **      **                              **      **  *\n"
                         "        *                                                              *\n"
                         "        *                                                              *\n"
                         "        *      **      **                      **      **      **      *\n"
                         "        **   **  **  **  **      2. Scores       **  **  **  **  **  ***\n"
                         "        *  **      **      **                      **      **      **  *\n"
                         "        *                                                              *\n"
                         "        ****************************************************************\n" <<"\033[0m"<<endl;
      cin>>k;

      if(k==1)
      {
            p.saisir_nb_mines();
            p.saisir_nb_lignes();
            p.saisir_nb_colonnes();
            p.placer_mines();
            p.game();
            break;
      }
      else
            {
                  p.affiche_scores();
                  p.my_delay(2);
                  system("clear");
            }
      }
    //  cout << "Hello world!" << endl;
      return 0;
}
