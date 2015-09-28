#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<unsigned char> cancelled;
    int T;
    cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int N, K;
		cin >> N >> K;
		int num_students_on_time = 0;
		for (int jj = 0; jj < N; jj++) {
			int arrival_time;
			cin >> arrival_time;
			if (arrival_time <= 0) {
				num_students_on_time++;
			}
		}
		if (num_students_on_time >= K) {
			cancelled.push_back(0);
		} else {
			cancelled.push_back(1);
		}
	}
	for (const auto &ii : cancelled) {
		if (ii)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}
