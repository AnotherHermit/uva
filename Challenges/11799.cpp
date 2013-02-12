#include <iostream>

using namespace std;

int main()
{
	int T, N, C, min_speed;

	cin >> T;

	

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		min_speed = 0;

		for (int j = 0; j < N; j++)
		{
			cin >> C;

			if(C > min_speed)
				min_speed = C;
		}

		cout << "Case " << i + 1 << ": " << min_speed << endl;
	}

	return 0;
}