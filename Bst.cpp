#include "Bst.h"


    Bst::Bst()
        {
            team = NULL;
            left = NULL;
            right = NULL;
        }


        Bst::Bst(Team *te)
            {
                team = new Team;

                team = te;

                left = NULL;

                right = NULL;
            }


    void Bst::insert(Bst* root , Bst* nod , Team* te)
        {
            if (te->get_punctaj() < team->get_punctaj())
               {
                if(left != NULL)
                    left->insert(root , left ,te);

                else
                    left = new Bst(te);
               }
            else if (te->get_punctaj() > team->get_punctaj())
               {
                if(right != NULL )
                    right->insert(root , right ,te);

                else
                    right = new Bst(te);

               }

             else if (te->get_punctaj() == team->get_punctaj())
               {
                    if(this->team->get_name() == root->team->get_name())
                        {if(right != NULL )
                    right->insert(root , right ,te);

                else
                    right = new Bst(te);

                        }   
                    else
                    {
                        if(left != NULL)
                    left->insert(root , left ,te);

                else
                    left = new Bst(te);
                    }
             

               }


        }

    void Bst::maxright(Bst* nod , ofstream& out , int runda , int ver)
        {
            Bst* aux;

            aux = new Bst;

            aux = nod;

            if(aux->right != NULL)
            {
                maxright(aux->right , out , runda , 1);
            }
                    if(aux->left != NULL && ver == 1)
                        {
                            out<<endl;
                            out<<std::left<<setw(30)<<aux->left->team->get_name();
                            out<<"    -  "<<fixed<<setprecision(2)<<aux->left->team->get_punctaj(runda);
                        }

                    out<<endl;
                    out<<std::left<<setw(30)<<aux->team->get_name();
                    out<<"    -  "<<fixed<<setprecision(2)<<aux->team->get_punctaj(runda);





        }

        void Bst::maxleft(Bst* nod , ofstream& out , int runda)
        {
            Bst* aux;

            aux = new Bst;

            aux = nod->left;

            if(aux->right != NULL )
            {
                maxright(aux->right , out , runda , 0);

            }

            out<<endl;
                    out<<std::left<<setw(30)<<aux->team->get_name();
                    out<<"    -  "<<fixed<<setprecision(2)<<aux->team->get_punctaj(runda);

            if(aux->left != NULL)
                maxleft(aux , out , runda );







        }

         void Bst::max(Bst* nod , ofstream& out , int runda)
            {

            Bst::maxright(nod , out , runda-1 , 0);

            Bst::maxleft(nod , out , runda-1);

            out<<endl;

            }







