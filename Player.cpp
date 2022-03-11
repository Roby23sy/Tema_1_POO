
#include "Player.h"

	Player::Player()
		{
			firstName = "Jhon";

			secondName = "Doe";

			points = 0;

		}


	Player::Player(string f , string s , int xp)
		{
			firstName = f;

			secondName = s;

			points = xp;

		}

	Player::Player(const Player& p)
		{
			firstName = p.firstName;

			secondName = p.secondName;

			points = p.points;

		}


	void Player::afisare_test() const
		{

			cout<<endl<<endl<<firstName<<" "<<secondName<<"==>"<<points;

		}

	Player & Player::operator=(const Player& p)
		{
			firstName = p.firstName;

			secondName = p.secondName;

			points = p.points;



		}

	string Player::get_Fn()
		{
			return firstName;
		}

	string Player::get_Sn()
		{
			return secondName;
		}

	int Player::get_points()
		{
			return points;
		}
    void Player::win(int nr_player)
        {


        }

	ostream & operator <<(ostream &out, const Player &p)
		{
			out<<endl<<p.firstName<<" "<<p.secondName<<"==>"<<p.points;

			return out;
		}

	void Player::set_fName(string fn)
		{
			firstName = fn;

		}

	void Player::set_sName(string sn)
		{
			secondName = sn;

		}

	void Player::set_points(int p)
		{
			points = p;


		}

