#include <iostream>

using namespace std;

int main() {	
	int N, C, n1, n5, n10, count;

	cin >> N;
	
	for(int i = 0; i < N; i++) {
		count = 0;
		
		cin >> C >> n1 >> n5 >> n10;

		for(int j = C; j > 0; j--) {
			if(n10 > 0) {
				if(n5 < (j - n10) && n1 >= 3) {
					n10--;
					n1 -= 3;
					n5++;
					count += 4;
				} else {
					n10--;
					n1 += 2;
					count++;
				}
			} else if((n5 >= (2 * j)) || ((n1 < 3) && (n5 >= 2))) {
				n5 -= 2;
				n1 += 2;
				count += 2;
			} else if(n5 > 0 && n1 >= 3) {
				n5--;
				n1 -= 3;
				count += 4;
			} else if(n1 >= 8) {
				n1 -= 8;
				count += 8;
			} else {
				int* temp = nullptr;
				*temp = 0;
			}
		}

		cout << count << endl;
	}

	return 0;
}