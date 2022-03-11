#include "Coada.h"

class Bst
{public:
    Team *team;
    Bst *left;
    Bst *right;


    Bst();
    Bst(Team *te);
    void set_team(Team *te);
    void insert(Bst* root , Bst* nod , Team* te);
    void maxright(Bst* nod , ofstream& out , int runda , int ver);
    void maxleft(Bst* nod , ofstream& out , int runda);
    void max(Bst* nod , ofstream& out , int runda);
    void max_left_right(Bst* nod , ofstream& out , int runda);
};
