#include "Bst.h"
#include<bits/stdc++.h>

      int echipe(int nr)
        {
            int po=0;

            while(nr != 1)
              { nr = nr/2;
                po++;
                }

            return po;
        }

    void read(char *argv[] , Team **te)
        {ifstream inf(argv[2]);
        int nr_echipe;

        inf>>nr_echipe;
        Team *team_pointer;

         for(int i=0 ; i <nr_echipe ; i++)
        {team_pointer = new Team;
        inf>>team_pointer;
        team_pointer->point_at_next(*te);
        *te = team_pointer;

          }
        }


    void write_1(char *argv[] ,Team *te)
        {
            ofstream out(argv[3]);
            out<<te;
        }

      double putere(int n)
            {double i;
                i = ceil(log2(n)) - floor(log2(n));
                return i;
            }

        void Delete_Min(Team **L)
    {
        Team *p, *minp;

        p = new Team;
        minp = new Team;

        p = (*L)->get_next();
        minp = *L;

        while (p->get_next() != NULL)
        {
            if ((p->get_next())->get_punctaj() < minp->get_next()->get_punctaj())
            {

			minp = p;
            }

            p = p->get_next();

	   }

	if(minp->get_next()->get_punctaj() > (*L)->get_punctaj())
    {
        (*L) = (*L)->get_next();
    }

        else{
            p = minp->get_next();
            minp->point_at_next(p->get_next());
        }
	}


    void losers(char *argv[] , Team **te)
        {int n;

        ifstream inf(argv[2]);
        inf>>n;
            while(putere(n) != 0)
            {
                Delete_Min(te);
                n--;

            }

        }





        Team* lupta(Team *te ,int nr_echipe , ofstream &out,int runda)
            {

                while(putere(nr_echipe) != 0)
                    nr_echipe--;

                Team *aux;
                Meciuri *meci;
                Coada *coada_meciuri;

                aux = new Team;


                coada_meciuri = new Coada;

            aux = te;
            if(runda == 1)
            out<<endl<<"--- ROUND NO:"<<runda;

            else
                out<<endl<<endl<<"--- ROUND NO:"<<runda;

            for(int c=0 ; c < nr_echipe/2  ; c++)
                {
                    meci = new Meciuri;

                    meci->set_First(aux);

                    aux = aux->get_next();

                    meci->set_Second(aux);

                    aux = aux->get_next();

                    meci->point_at_next(NULL);

                    coada_meciuri->new_meci(meci);

                    out<<endl;
                    out<<left<<setw(30)<<meci->get_First()->get_name()<<"   -   "<<right<<setw(30)<<meci->get_Second()->get_name();
                }



            Team *win , *lose;

            win = new Team;

            lose = new Team;

            coada_meciuri->exec(&win , &lose , nr_echipe/2 , out);

            aux = win;


            out<<endl<<endl<<"WINNERS OF ROUND NO:"<<runda;

            for(int zu = 0 ; zu<nr_echipe/2 ; zu++)
            {
            aux->win();

            out<<endl;
            out<<left<<setw(30)<<aux->get_name();
            out<<"    -  "<<fixed<<setprecision(2)<<aux->get_punctaj(runda);

            aux = aux->get_next();
            }

            return win;

            }



         Bst* LUPTE(Team *te , char *argv[] )
        {ifstream inf(argv[2]);
                int nr_echipe;
                inf>>nr_echipe;
               int nr = nr_echipe;

                while(putere(nr) != 0)
                    nr--;

               int aux_nr = echipe(nr_echipe);

               Team* win_aux;
               win_aux = new Team;

                Bst* bst;
                bst = new Bst;


                ofstream out(argv[3] , std::fstream::app);
                Team* temporar = te;
                Team* win;
                win = new Team;

                int runda_aux;
        for(int runda = 1 ; runda <= aux_nr; runda++)
        {win = lupta(temporar , nr_echipe , out , runda);
            temporar = win;

            if(nr == 16)
               {Team *aux;
                   aux = new Team;
                   aux = temporar;
                    bst->team = aux;
                    aux = aux->get_next();

                   for(int numar=0 ; numar<7 ; numar++)
                   {


                    runda_aux = runda;

                    bst->insert(bst , bst,aux);

                     aux = aux->get_next();

                    }
               }

            nr_echipe = nr_echipe/2;
            nr = nr/2;
                }
                
                return bst;
            }

        void Binar_search(Bst* bst , char* argv[])
           {
                ofstream out(argv[3] , std::fstream::app);
                ifstream inf(argv[2]);          
            out<<endl<<endl<<"TOP 8 TEAMS:";
            
            int nr;
            inf>>nr;
            int runda=1;
            
                
                while(putere(nr) != 0)
                        nr--;


                while(nr != 8)
                    {nr = nr/2;
                        runda++;
                      } 
            
            bst->max(bst , out , runda);
        

                 }





    int main(int argc , char** argv)
        {Team *te=NULL;
        Bst *bst;

        bst = new Bst;
        


ifstream cerinte(argv[1]);
 read(argv , &te);

	for (int j = 0; j <= 4; j++)
       {
		int task;
		cerinte >> task;


		switch (j) {
			case 0: {
				if (task == 1)

					write_1(argv , te);
				break;
			}
			case 1: {
				if (task == 1)
					{
					losers(argv , &te);
                    write_1(argv , te);
				    }
				break;
			}
			case 2: {
				if (task == 1)
                   bst = LUPTE(te , argv );
				break;
			}
			case 3: {
   				if (task == 1)
                     Binar_search( bst ,argv);               
 	                    			
                break;
			}
			case 4: {
				if (task == 1)
				        write_1(argv , te);
				break;
			}

			default: {
				cout << "Error! " << endl;
				break;
			}
		}
    }

	cerinte.close();

            return 0;
        }
