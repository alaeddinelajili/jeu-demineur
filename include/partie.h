#ifndef PARTIE_H
#define PARTIE_H
#include "caso.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class partie : public caso
{
      caso mat[99][99];
      int visited[99][99];
      int nb_mines;
      int nbM;
      int nb_colonnes;
      int nb_lignes;
      bool lose=false;
      int nb_case_decouvertes=0;
      int score=0;
      int i;
      int j;
      public:
            partie();
            virtual ~partie();
            void my_delay(int i);
            void saisir_nb_mines ();
            void saisir_nb_lignes ();
            void saisir_nb_colonnes ();
            void placer_mines();
            void placer_drapeaux( int x,int y);
            bool is_valid(int x,int y);
            void NUMBER(int x,int y);
            void devoiler_case(int i,int j);
            void game();
            void affiche();
            void affiche_final();
            void gain();
            void affiche_scores();
      protected:
      private:
};

#endif // PARTIE_H
