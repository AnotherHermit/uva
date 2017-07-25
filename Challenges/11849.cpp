// Accepted 24/1 - 16

#include <iostream>
#include <vector>

using namespace std;

int main11849() {
	int N, M, n, m, sum;

	vector<int> nval;

	cin >> N >> M;

	while(N != 0 && M != 0) {
		n = 0;
		m = 0;
		sum = 0;

		nval.resize(N);

		for(size_t i = 0; i < N; i++) {
			cin >> nval[i];
		}

		for(size_t i = 0; i < M; i++) {
			cin >> m;

			while(m > nval[n]) {
				if(n < (N - 1)) {
					n++;
				} else {
					break;
				}
			}

			if(m == nval[n]) {
				sum++;
			}
		}

		cout << sum << endl;
		cin >> N >> M;
	}

	return 0;
}