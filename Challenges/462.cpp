// Accepted 12/02-13

#include <iostream>
#include <string>

using namespace std;

int main462()
{
	int points, no_trump;
	pair<char, int> bid;
	string temp;
	
	while(getline(cin, temp))
	{
		bool stopped = true;
		points = 0;
		no_trump = 0;
		bid.second = 0;
		int suits[4] = {0};

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
			if ((suits[i] & 1024) && ((suits[i]>>4) & 8+4+2+1) > 1)
			{
				suits[i] |= 4096;
			}
			else if(suits[i] & 1024)
			{
				suits[i]--;
			}

			if ((suits[i] & 512) && ((suits[i]>>4) & 8+4+2+1) > 2)
			{
				suits[i] |= 4096;
			}
			else if(suits[i] & 512)
			{
				suits[i]--;
			}

			if ((suits[i] & 256) && ((suits[i]>>4) & 8+4+2+1) < 4)
			{
				suits[i]--;
			}

			if(suits[i] & 4096)
			{
				stopped &= true;
			}
			else
			{
				stopped = false;
			}

			no_trump += (suits[i] & 8+4+2+1);

			if(((suits[i]>>4) & 8+4+2+1) > bid.second)
			{
				bid.second = ((suits[i]>>4) & 8+4+2+1);
				switch (i)
				{
				case 0:
					bid.first = 'S';
					break;
				case 1:
					bid.first = 'H';
					break;
				case 2:
					bid.first = 'D';
					break;
				case 3:
					bid.first = 'C';
					break;
				default:
					break;
				}
			}

			if (((suits[i]>>4) & 8+4+2+1) == 2)
			{
				suits[i]++;
			}
			else if(((suits[i]>>4) & 8+4+2+1) < 2)
			{
				suits[i]+=2;
			}

			points += (suits[i] & 8+4+2+1);
		}
		
		if (stopped && no_trump >= 16)
		{
			cout << "BID NO-TRUMP" << endl;
		}
		else if (points >= 14)
		{
			cout << "BID " << bid.first << endl;
		}
		else
		{
			cout << "PASS" << endl;
		}
	}
	return 0;
}