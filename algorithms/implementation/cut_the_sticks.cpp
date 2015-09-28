#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a;
	while (N--) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	while (!a.empty()) {
		cout << a.size() << endl;
		int min = 1000;
		for (const auto &t : a) {
			if (t < min) {
				min = t;
			}
		}
		for (auto &t : a) {
			t -= min;
		}
		vector<int> b;
		for (const auto &t : a) {
			if (t > 0) {
				b.push_back(t);
			}
		}
		a = b;
	}
    return 0;
}
