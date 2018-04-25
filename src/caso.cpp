#include "caso.h"
#include <bits/stdc++.h>
caso::caso()
{
      //ctor
}

void caso::set_drapeau(bool x)
      {
            drapeau=x;
      }
bool caso::get_drapeau()
      {
            return drapeau;
      }
bool caso::get_mine()
      {
            return mine;
      }
void caso::set_number(int x)
      {
            number=x;
      }
int caso::get_number()
      {
            return number;
      }
void caso::set_mine(bool x)
      {
            mine=x;
      }
caso::~caso()
{
      //dtor
}
