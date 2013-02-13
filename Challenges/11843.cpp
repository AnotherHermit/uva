#include <iostream>
#include <math.h>

using namespace std;

int main11843()
{
	int N, S, C, X, min_i;
	double min_d, N_d;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> N >> S;

		N_d = N;
		min_d = log(N_d)/log(2.) + 1;
		min_i = min_d;

		if(S == 1)
		{
			X = N;
		}
		else if(S == 2)
		{

		}

		cout << X << endl;
	}

	return 0;
}