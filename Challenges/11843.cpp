#include <iostream>
#include <math.h>

// Ta bort innan inlämning
#include <Windows.h>
#include "mmsystem.h"

using namespace std;

int main()
{
	// Ta bort innan inlämning
	DWORD startD,endD;
	startD = timeGetTime();
	unsigned int end;


	short LUT[1000][10] = {0};
	int N, S, C, X, min_i;
	double min_d, N_d;

	for (int i = 0; i < 1000; i++)
	{
		LUT[i][0] = i + 1;
	}

	short pos = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0;pos < 1000 && j < pow(2,i); pos++, j++)
		{
			LUT[pos][9] = i + 1;
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




	// Ta bort innan inlämning
	endD = timeGetTime();
	end = endD - startD;
	cerr << end << endl;


	while(cin >> N >> S)
	{
		cout << LUT[N-1][S-1] << endl;
	}

	return 0;
}