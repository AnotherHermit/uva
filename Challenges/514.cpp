// Accepted 16/2-13

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main514()
{
	vector<short> station;
	short train_length, next_number, min_before_A;
	string out_msg;

	cin >> train_length;

	do
	{
		cin >> next_number;
		do
		{
			min_before_A = 1;
			out_msg = "Yes";

			for (int i = 0; i < train_length; i++)
			{
				if (next_number > min_before_A)
				{
					for (int j = min_before_A; j < next_number; j++)
					{
						station.push_back(j);
					}

					min_before_A = next_number + 1;
				}
				else if (next_number == min_before_A)
				{
					min_before_A++;
				}
				else if (next_number == station.back())
				{
					station.pop_back();
				}
				else
				{
					out_msg	= "No";
				}

				cin >> next_number;
			}

			cout << out_msg << endl;

		} while (next_number != 0);

		cout << endl;
		cin >> train_length;
	} while (train_length != 0);

	return 0;
}