#include <iostream>
using namespace std;

int main() {

	int M, N, min;
	int factor=1, multiple=1;

	cin >> M >> N;

	if (M < N)
		min = M;
	else
		min = N;
		

	while (1) {
		int i;
		for (i = 2; i <= min; i++) {
			if (M % i == 0 && N % i == 0) {
				M /= i;
				N /= i;
				factor *= i;
				multiple = factor;
				break;
			}
		}
		if (i == min+1) {
			multiple *= M * N;
			break;
		}
	}

	cout << factor << endl;
	cout << multiple;

	return 0;
}