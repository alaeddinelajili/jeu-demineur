#include "partie.h"
#include "caso.h"
#include <bits/stdc++.h>

partie::partie()
{
      //ctor
}


void partie::saisir_nb_mines()
{     int nbm;
      cout<<"choisissez le Nombre de mines :";
      cin>>nbm;
      nb_mines=nbm ;
      nbM=nbm;
      }

void partie::saisir_nb_lignes()
{     int nbm;
      cout<<"choisissez le Nombre de lignes :";
      cin>>nbm;
      nb_lignes=nbm;
      }

void partie::saisir_nb_colonnes()
{     int nbm;
      cout<<"choisissez le Nombre de colonnes :";
      cin>>nbm;
      nb_colonnes=nbm ;
      cout<<endl;
      cout<<"******* c'est parti *******"<<endl;
      cout<<endl;
      }

void partie::placer_mines()
{

      do{
      int i= rand() % 99 + 1 ;
      int j= rand() % 99 + 1 ;
      if ((i<nb_lignes+1)&&(j<nb_colonnes+1))
            {
                  nb_mines--;
                  if (mat[i][j].get_mine() ==true) // pour dire case contienne une mine
                        nb_mines++;
                  else
                        mat[i][j].set_mine(true) ;
            }
      }
      while(nb_mines!=0);
      nb_mines=nbM;

}

void partie::placer_drapeaux( int x,int y)
{
      char k;
      if (mat[x][y].get_drapeau()==true)
            {
                  cout<<"cette cas contient deja un drapeau si vous voulez le supprimer tapez < S > si vous voulez le garder tapez < G > "<<endl;
                  cin>>k;
                  if (k=='S')
                        {     mat[x][y].set_drapeau(false);
                              nbM++;
                        }
                  else
                        return;
            }
      else
            {
                  mat[x][y].set_drapeau(true);
                  nbM--;            //a chaque drapeau placee le nombre de mines se decrimente dans laffichage
            }
}
void partie::devoiler_case(int i,int j)
{
      if (mat[i][j].get_mine()==true)
      {
            mat[i][j].set_number(0);
            lose=true;
      }
      else
            NUMBER(i,j);
}

void partie::affiche()
{
      cout<<"   ";
      for (int h=1;h<nb_colonnes+1;h++)
            cout<<h<<" ";
               cout<<endl;
            for (int k=1;k<nb_lignes+1;k++)
            {     if (k<10) cout<<k<<"  ";
                  else cout<<k<<" ";
                  for (int l=1;l<nb_colonnes+1;l++)
                        {
                              if ((mat[k][l].get_mine()==true)&&(mat[k][l].get_number()==0))       //getnumber=0 car lorsque je devoile une mine number=0 pour distinguer la mine decouverte et la mine cacher
                                    if (l<10)
                                          cout<< "\033[1;31m"<<'M'<<"\033[0m"<<' '; // mine en rouge
                                    else
                                           cout<< "\033[1;31m"<<'M'<<"\033[0m"<<' '<<' ';
                              else
                                          {
                                                if(mat[k][l].get_drapeau()==true)
                                                      if (l<10)
                                                            cout<<"\033[0;32m"<<'D'<<"\033[0m"<<' ';           //drapeau en vert
                                                      else
                                                            cout<<"\033[0;32m"<<'D'<<"\033[0m"<<' '<<' ';
                                                else
                                                      {
                                                      if (l<10)

                                                         {   switch(mat[k][l].get_number())
                                                            {
                                                                  case 10 :
                                                                        cout<<"# " ; //case non devoiler
                                                                        break;
                                                                  case 0 :
                                                                        cout<<"X "; //chercher un couleur pour cette case
                                                                        break;      //case vide
                                                                  default :
                                                                        cout<< "\033[1;35m"<<mat[k][l].get_number()<<"\033[0m"<<' ';      //number en mauve
                                                            }
                                                        }
                                                      else
                                                        {
                                                             switch(mat[k][l].get_number())
                                                            {
                                                                  case 10 :
                                                                        cout<<"#  " ; //case non devoiler
                                                                        break;
                                                                  case 0 :
                                                                        cout<<"X  "; //chercher un couleur pour cette case
                                                                        break;      //case vide
                                                                  default :
                                                                        cout<< "\033[1;35m"<<mat[k][l].get_number()<<"\033[0m"<<' '<<' ';      //number en mauve
                                                            }
                                                        }
                                                      }
                                          }

                       }
                  cout<<endl;
            }

}
void partie::my_delay(int i)    /*Pause l'application pour i seconds*/
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}
void partie::affiche_final() //pour voir les positions des mines et du blancs a la fin de la partie
{
cout<<"   ";
      for (int h=1;h<nb_colonnes+1;h++)
            cout<<h<<" ";
               cout<<endl;
            for (int k=1;k<nb_lignes+1;k++)
            {     if (k<10) cout<<k<<"  ";
                  else cout<<k<<" ";
                  for (int l=1;l<nb_colonnes+1;l++)
                        {
                              if (mat[k][l].get_mine()==true)
                                    if (l<10)
                                          cout<< "\033[1;31m"<<'M'<<"\033[0m"<<' '; // mine en rouge
                                    else
                                           cout<< "\033[1;31m"<<'M'<<"\033[0m"<<' '<<' ';
                              else
                                          {
                                                if (l<10)
                                                      cout<<"X ";
                                                else
                                                      cout<<"X  ";
                                          }
                       }
                  cout<<endl;
            }
}


bool partie::is_valid(int x,int y)
{
      if(x>nb_lignes || x<=0 || y>nb_colonnes || y<=0)
            return false;
      return true;
}

void partie::NUMBER(int i , int j)
{
      int dirX[8] = {1,-1, 0, 0,1,-1,-1,1} ;
      int dirY[8] = {0, 0, -1,1,1,-1,1,-1} ;
      int nb=0;
      if (mat[i][j].get_mine()==true) return;
      if (mat[i][j].get_drapeau()==true) return ;
      if(visited[i][j]==1)   return;
      visited[i][j]=1;
      nb_case_decouvertes++;
      for(int k=0; k<8; k++)
            {
                  if(is_valid(dirX[k]+i,dirY[k]+j))
                        {
                              if ( mat[dirX[k] +i][dirY[k]+j].get_mine()==true)
                                    nb++;
                        }
            }
      mat[i][j].set_number(nb); //mise a jour de la valeur number dans la case , number pour dire le nombre de mines dans lentourage de la cas
      if (mat[i][j].get_number()==0) //c'est à dire que l'entourage de tab[i][j] ne contient pas de mines
            {
                  for(int k=0; k<8; k++)
                        if(is_valid(dirX[k]+i,dirY[k]+j))
                              {
                                    NUMBER(dirX[k]+i,dirY[k]+j);
                              }
            }
}


void partie::gain()
{
      string ch;
      cout<<"votre score est :"<<score<<endl;
      cout<<"entrez votre nom pour sauvgarder votre score :";
      cin>>ch;
      ofstream fichier("score.txt", ios::app);  // on ouvre en lecture
      if(fichier)  // si l'ouverture a fonctionné
            {
                  fichier <<"player : "<<ch<<" score : "<<score<<endl;
                  fichier.close();
            }
}
void partie::affiche_scores()
{
      ifstream fichier("score.txt");
      if(fichier)
      {
            string ligne; //Une variable pour stocker les lignes lues
            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                  cout << ligne << endl;   //Et on l'affiche dans la console
            }
      }

}
void partie::game()
{
      char k;
      int ii,jj;
      int c;
      do
      {
            cout<<"nombre de mines :"<<nbM<<endl;
            cout<<"nombre de cases devoilees : "<<nb_case_decouvertes<<endl;
            cout<<endl;
            affiche();
            cout<<"tapez < M > si vous voulez marquer une case ou < D > pour dévoiler une case :"<<endl ;
            cin>>k;
            if (k=='D')
                  {
                        cout<<"choisir la case à dévoiler:"<<endl;
                        cin>>ii>>jj;
                        if(is_valid(ii,jj)==false)
                              {
                                    cout<<"case invalide"<<endl;
                                    my_delay(1);
                              }
                        else
                              devoiler_case(ii,jj);
                  }
            else
                  {
                        cout<<"choisir la case à marquer"<<endl;
                        cin>>ii>>jj;
                        if(is_valid(ii,jj)==false)
                              {
                                    cout<<"case invalide"<<endl;
                                    my_delay(1);
                              }
                        else
                              placer_drapeaux(ii,jj);
                  }
            c=(nb_colonnes*nb_lignes)-nb_mines; //nb de cases blancs
            score+=100;
            system("clear");
      }
      while((lose==false)&&(c>nb_case_decouvertes));
      affiche_final();
      if (lose==false)
            {
                  cout<<"************ félicitation vous avez gagné ************"<<endl;
                  gain();
                  affiche_scores();
            }
      else
            {
                  cout<<"vous avez perdu !!!!!"<<endl;
                  cout<<"la case ("<<ii<<","<<jj<<") contienne une mine."<<endl;
            }
}
partie::~partie()
{
      //dtor
}
