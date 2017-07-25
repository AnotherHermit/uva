#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main10036()
{
	int M;
	short N, K;
	int remainder[101];
	short next_number, pos_next;
	string out_msg;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		out_msg = "Not divisible";

		for (int j = 0; j < 100; j++)
		{
			remainder[j] = 0;
		}

		cin >> N >> K;
		cin >> next_number;

		remainder[0] = next_number % K;

		for (int j = 1; j < N; j++)
		{
			cin >> next_number;
			pos_next = abs(next_number) % K;
			if (pos_next)
			{
				remainder[pos_next]++;
				remainder[K]++;
			}
		}

		// Implement algoritm




		for (int j = 0; j < K; j++)
		{
			cout << remainder[j] << ' ';
		}

		cout << out_msg << endl;
	}
	
	return 0;
}