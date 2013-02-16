// Accepted 16/2-13

#include <iostream>
#include <math.h>

/* Ta bort innan inlämning
#include <Windows.h>
#include "mmsystem.h" */

using namespace std;

int main11843()
{
	/* Ta bort innan inlämning
	DWORD startD,endD;
	startD = timeGetTime();
	unsigned int end;*/


	short LUT[1000][10] = {0};
	int N, S, C;

	for (int i = 0; i < 1000; i++)
	{
		LUT[i][0] = i + 1;
	}

	short pos = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0;pos < 1000 && j < pow(2,i); pos++, j++)
		{
			for (int k = i; k < 10; k++)
			{
				LUT[pos][k] = i + 1;
			}
		}
	}

	pos = 0;
	for (int i = 1; i < 46; i++)
	{
		for (int j = 0;pos < 1000 && j < i; j++, pos++)
		{
			LUT[pos][1] = i;
			if(i == LUT[pos][9])
			{
				for (int k = 2; k < 9; k++)
				{
					LUT[pos][k] = i;
				}
			}
		}
	}


	for (int j = 2; j < 9; j++)
	{
		for (int i = 0; i < 1000; i++)
		{
			short min_way = 50;
			if(LUT[i][j] == 0)
			{
				short same_row = i - 2;
				short less_row = 0;

				for (int k = 0; k < i; k++)
				{
					if(LUT[same_row][j] == LUT[less_row][j-1])
					{
						min_way = LUT[same_row][j];
						break;
					}
					else if(LUT[same_row][j] < LUT[less_row][j-1])
					{
						min_way = LUT[less_row][j-1];
						break;
					}
					same_row--;
					less_row++;
				}

				LUT[i][j] = min_way + 1;
			}
		}
	}


	/* Ta bort innan inlämning
	endD = timeGetTime();
	end = endD - startD;
	cerr << end << endl; 

	for (int j = 0; j < 300; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << LUT[j][i] << ' ';
			if(LUT[j][i] < 10)
				cout << ' ';

			if(LUT[j][i] < 100)
				cout << ' ';

		}
		cout << endl;
	} */

	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> N >> S;
		{
			if(S > 10)
				S = 10;
			cout << LUT[N-1][S-1] << endl;
		}
	}


	return 0;
}