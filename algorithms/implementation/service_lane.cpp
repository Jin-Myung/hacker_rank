#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	vector<int> widths;
	while (N--) {
		int width;
		cin >> width;
		widths.push_back(width);
	}
	while (T--) {
		int A, B;
		cin >> A >> B;
		int min = 3;
		for (int ii = A; ii <= B; ++ii) {
			if (widths[ii] < min) {
				min = widths[ii];
			}
		}
		cout << min << endl;
	}
    return 0;
}
