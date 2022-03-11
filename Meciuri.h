#include "Team.h"

class Meciuri
{
    Team *First , *Second;
    Meciuri *next;

public:
    Meciuri();
    Team* get_First();
    Team* get_Second();
    void set_First(Team*);
    void set_Second(Team*);
    Team* get_win();
    Team* get_lose();
    void point_at_next(Meciuri*);
    Meciuri* get_next();


};
