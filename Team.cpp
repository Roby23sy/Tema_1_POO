
#include "Team.h"

	Team::Team()
		{

			player = NULL;

			next = NULL;
		}

	Team::Team(string s , int nr , Player* p)
		{
			team_name = s;

			nr_players = nr;

			player = new Player[nr_players];

			for( int i = 0 ; i< nr ; i++)
				{
					player[i] = p[i];

				}

		}

	Team::Team(const Team& t)
		{
			team_name = t.team_name;

			nr_players = nr_players;

			if( player != NULL) delete [] player ;

			player = new Player[sizeof(t.player)];

			player = t.player;

			next = t.next;
		}

	Team & Team::operator=(const Team& t)
		{
			team_name = t.team_name;

			nr_players = t.nr_players;

			player = new Player[sizeof(t.player)];

			player = t.player;

            next = t.next;

		}

	void Team::afisare_test() const
		{
			cout<<endl<<endl<<"<<<"<<team_name<<">>>"<<endl<<"        ("<<nr_players<<")"<<endl<<endl;
			int i;
			for( i = 0 ; i< nr_players ; i++)
				{
					cout<<player[i];

				}

		}



	int Team::get_nr_players()
		{
			return nr_players;


		}
		Team::~Team()
		{

			if(player != NULL) delete [] player;


			}

	string Team::get_name()
		{

			return team_name;

		}

	double Team::get_punctaj(int x)
		{double score=0;
			for(int l1=0 ; l1< nr_players ; l1++)
				{
					score += player[l1].get_points();

				}
            score = (score / (double) nr_players)+x;

			return score;

		}

	void Team::set_name(string name)
		{
			team_name = name;

		}

	void Team::set_nr(int nr)
		{
			nr_players = nr;

		}

	Team* Team::get_next()
		{
			return next;
		}

	 ifstream& operator >> (ifstream& inf , Team *te)
		{	int nr_players;
                string str;

        inf>>nr_players;
        te->set_nr(nr_players);

        inf.ignore();

        getline(inf , str);

        while(str.length()  && *(str.end() -1) == ' ')

            str.pop_back();

        te->set_name(str);

        te->player = new Player[nr_players];
             for(int j = 0 ; j< nr_players ; j++)
             {
                 int n_aux;
                 inf>>str;

                 te->player[j].set_fName(str);

                 inf>>str;

                 te->player[j].set_sName(str);

                 inf>>n_aux;

                 te->player[j].set_points(n_aux);

             }

			return inf;
		}

    void Team::point_at_next(Team *where_to_point)
        {

            next = where_to_point;

        }

    void Team::win()
        {
            for(int joale = 0 ; joale < nr_players ; joale++)
            {
                player[joale].win(nr_players);
            }

        }

    ofstream& operator << (ofstream& out ,Team *te)
        {
            Team *temp;
            temp = new Team;

            temp = te;

            while(temp != NULL)
            {
             out<<temp->get_name()<<endl;
             temp = temp->get_next();
            }

        }


    Team* Team::add(Team **L)
        {Team* te;
            te = new Team;

          te->point_at_next(*L);

         te->set_name((*L)->get_name());
         te->set_nr((*L)->get_nr_players());
         te->player = (*L)->player;
            te->point_at_next((*L)->get_next());
            return te;
        }

