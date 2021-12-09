#include <iostream>
#include <math.h>
using namespace std;


int main() {

	int M, N, min=10000, sum = 0;

	cin >> M;
	cin >> N;

	for (int i = M; i <= N; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			if (sqrt(i) == j) {
				sum += i;
				if (i < min) {
					min = i;
				}
			}
		}
	}
	if (sum == 0)
		cout << -1 ;
	else {
		cout << sum << endl;
		cout << min ;
	}

	return 0;
}