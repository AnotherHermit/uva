// Accepted 11/2-13

#include <iostream>

using namespace std;

int main11559()
{
	int N, B, H, W, p, a;
	char buffer[100];

	int possible_sum;

	while(cin >> N >> B >> H >> W)
	{
		possible_sum = 10001 * N;

		for (int i = 0; i < H; i++)
		{
			cin >> p;

			for (int i = 0; i < W; i++)
			{
				cin >> a;

				if(a >= N && p*N < possible_sum && p*N <= B)
				{
					possible_sum = p*N;
				}
			}
		}

		if(possible_sum == 10001*N)
			cout << "stay home" << endl;
		else
			cout << possible_sum << endl;
	}

	return 0;
}