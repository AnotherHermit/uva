// Accepted 24/1 - 16

#include <iostream>

using namespace std;

int main11556()
{
	int64_t N, b;

	while (cin >> N >> b) {
		if (N > (((int64_t)2 << b) - (int64_t)1))
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}

	return 0;
}