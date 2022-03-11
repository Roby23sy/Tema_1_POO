#include "Coada.h"


    Coada::Coada()
    {
            front=NULL;
            rear=NULL;
    }

   Meciuri* Coada::get_front()
            {
                return front;
            }

    Meciuri* Coada::get_rear()
        {
            return rear;
        }

    void Coada::set_front(Meciuri* me)
        {
            front = me;
        }


    void Coada::set_rear(Meciuri* me)
        {
            rear = me;
        }

    void Coada::exec(Team** win , Team** lose ,int nr ,ofstream& out)
        {   Meciuri* me = front;


            for(int co = 0 ; co<nr ; co++)
            {Team* aux = me->get_win();
                if(win == NULL)
                    {*win = aux;
                        (*win)->point_at_next(NULL);
                    }
                else
                {aux->point_at_next(*win);
                    (*win) = aux;
                }


            aux = me->get_lose();

                if(*lose == NULL)
                    {*lose = aux;
                        (*lose)->point_at_next(NULL);
                    }
                else
                {aux->point_at_next(*lose);
                    *lose = aux;
                }


            me = me->get_next();
            }


        }

        void Coada::new_meci(Meciuri* meci)
            {if(rear == NULL)
                        this->set_rear(meci);

                    else
                    {
                        this->get_rear()->point_at_next(meci);
                        this->set_rear(meci);

                    }



                    if(this->get_front() == NULL)
                        this->set_front(this->get_rear());

            }




