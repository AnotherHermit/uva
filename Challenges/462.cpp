#include <iostream>
#include <string>

using namespace std;

int main()
{
	int suits[4];
	int points = 0;
	string temp;

	while(getline(cin, temp))
	{
		for (int i = 0; i < 13; i++)
		{	
			int add = 0;
			switch (temp[i*3])
			{
			case 'A':
				add += 4096 + 1024 + 1;
			case 'K':
				add += 512 + 1;
			case 'Q':
				add += 256 + 1;
			case 'J':
				add += 256 + 1;
			default:
				add += 16;
			}

			switch (temp[i*3 + 1])
			{
			case 'S':
				suits[0] += add;
				break;
			case 'H':
				suits[1] += add;
				break;
			case 'D':
				suits[2] += add;
				break;
			case 'C':
				suits[3] += add;
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ((suits[i] & 1024) && (suits[i] & (128+64+32)))
			{
				suits[i] |= 4096;
			}
			else if(suits[i] & 1024)
			{
				suits[i]--;
			}

			if ((suits[i] & 512) && ((suits[i] & (128+64)) || ((suits[i] & 16) && (suits[i] & 32))))
			{
				suits[i] |= 4096;
			}
			else if(suits[i] & 512)
			{
				suits[i]--;
			}

			if (!((suits[i] & 256) && (suits[i] & (128+64))))
			{
				suits[i]--;
			}
		}




	}

	return 0;
}