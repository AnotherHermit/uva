
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int numberImputs;
	string country, name_temp;
	map<string,int> conquests;

	cin >> numberImputs;
	for (int i = 0; i < numberImputs; i++)
	{
		cin >> country >> name_temp >> name_temp;
		pair<map<string,int>::iterator, bool> existed =  conquests.insert(pair<string,int>(country,1));

		if(existed.second == false)
		{
			existed.first->second++;
		}
	}

	for(map<string,int>::iterator it = conquests.begin(); it != conquests.end(); it++)
	{
		cout << it->first << ' ' << it->second << endl;
	}

	cin.get();
	cin.get();

	return 0;
}