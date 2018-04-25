#ifndef CASO_H
#define CASO_H
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class caso
{
      public:
            caso();
            void set_drapeau(bool x);
            void set_mine(bool x);
            bool get_mine();
            bool get_drapeau();
            void set_number(int x);
            int get_number();
            virtual ~caso();

      protected:
      bool drapeau=false;
      bool mine=false;
      int number=10; //number pour dire le nombre de mines dans lentourage de la cas
      private:          //la valeur initiale de number est 10 puisque number est toujours =<8
};

#endif // CASO_H
