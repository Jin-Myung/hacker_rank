#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long A, B;
		cin >> A >> B;
		double sqrtA = sqrt(1.*A);
		double sqrtB = sqrt(1.*B);
		long C = sqrtA;
		long D = sqrtB;
		long out = D-C;
		if (sqrtA-C == 0. || sqrtB-D == 0.) {
			out++;
		}
		cout << out << endl;
	}
    return 0;
}
