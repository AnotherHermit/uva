
// Accepted 11/2-13

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main10420()
{
	int numberImputs;
	char name_temp[75];
	string country;
	map<string,int> conquests;

	cin >> numberImputs;
	for (int i = 0; i < numberImputs; i++)
	{
		cin >> country;
		cin.getline(name_temp, 75);
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

	return 0;
}