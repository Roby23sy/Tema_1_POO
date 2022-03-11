
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

	class Player
{
private:
    string firstName;
    string secondName;
    int points;

public:

	Player();
	Player(string , string , int);
	Player(const Player&);


	void afisare_test() const;
	Player & operator =(const Player &p);
	friend	ostream & operator <<( ostream& ,const Player &p);
	string get_Fn();
	string get_Sn();
    int get_points();
	void set_fName(string fn);
	void set_sName(string sn);
	void set_points(int p);
    void win(int);
};
