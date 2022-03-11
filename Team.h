
#include "Player.h"

	class Team
{
private:

	string team_name;
	int nr_players;
	Team* next;

public:
	Player *player;

public:

	Team();
	Team(string , int ,Player*);
	Team(const Team&);
		~Team();
    Team & operator =(const Team &te);
	void afisare_test() const;

	Team* get_next();

	int get_nr_players();
	string get_name();
	void set_name(string name);
	void set_nr(int nr);
   	double get_punctaj(int x=0);
    friend ifstream& operator >> (ifstream& inf ,Team *te);
    friend ofstream& operator << (ofstream& out ,Team *te);
    void point_at_next(Team *where_to_point);
    void win();
    Team* add(Team **L);


};
