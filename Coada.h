#include "Meciuri.h"

class Coada
{
    Meciuri *front , *rear;

   public:
       Coada();

       Meciuri* get_front();
       Meciuri* get_rear();
       void set_front(Meciuri*);
       void set_rear(Meciuri*);
       void new_meci(Meciuri*);
       void exec(Team** win , Team** lose , int nr, ofstream& out);


};
