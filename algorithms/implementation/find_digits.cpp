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
		long N;
		cin >> N;
		long temp = N;
		int count = 0;
		while (temp) {
			int digit = temp % 10;
			if (digit && N % digit == 0) {
				count++;
			}
			temp /= 10;
		}
		cout << count << endl;
	}
    return 0;
}
