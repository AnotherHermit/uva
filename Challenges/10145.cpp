// Accepted 13/2-13

#include <iostream>
#include <map>

using namespace std;

int main10145()
{
	int N, TRID, ITEM;
	int C = 0; 
	char MODE;
	map<int, bool> ignore_list;
	map<int, unsigned int> data_list;
	pair<map<int,unsigned int>::iterator,bool> ret;

	cin >> N >> ws;

	while(C < N)
	{
		cin >> MODE;
		
		if (MODE == 'S')
		{
			cin >> TRID >> ITEM;

			if(ignore_list.find(TRID) != ignore_list.end())
			{
				cout << "IGNORED" << endl;
			}
			else
			{
				ret = data_list.insert(pair<int,unsigned int>(ITEM, TRID<<2));
				if(ret.second)
				{
					cout << "GRANTED" << endl;
				}
				else if(ret.first->second>>2 == TRID)
				{
					cout << "GRANTED" << endl;
				}
				else if(ret.first->second & 1)
				{
					cout << "DENIED" << endl;
					ignore_list.insert(pair<int,bool>(TRID, true));
				}
				else
				{
					ret.first->second |= 2;
					cout << "GRANTED" << endl;
				}
			}
		}
		else if (MODE == 'X')
		{
			cin >> TRID >> ITEM;

			if(ignore_list.find(TRID) != ignore_list.end())
			{
				cout << "IGNORED" << endl;
			}
			else
			{
				ret = data_list.insert(pair<int,unsigned int>(ITEM, (TRID<<2) + 1));
				if(ret.second)
				{
					cout << "GRANTED" << endl;
				}
				else if(ret.first->second & 2)
				{
					cout << "DENIED" << endl;
					ignore_list.insert(pair<int,bool>(TRID, true));
				}
				else if(ret.first->second>>2 == TRID)
				{
					ret.first->second |= 1;
					cout << "GRANTED" << endl;
				}
				else
				{
					cout << "DENIED" << endl;
					ignore_list.insert(pair<int,bool>(TRID, true));
				}
			}
		}
		else if (MODE == '#')
		{
			ignore_list.clear();
			data_list.clear();
			C++;
			if (C != N)
				cout << endl;
		}
	}

	return 0;
}