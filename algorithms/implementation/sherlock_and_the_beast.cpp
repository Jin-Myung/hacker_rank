#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<string> outputs;
    int T;
    cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int N;
		cin >> N;
		if (N%3 == 0) {
			outputs.push_back(string(N, '5'));
		} else {
			int num3 = 0;
			string output;
			for (; N >= 0; N -= 5, num3 += 5) {
				if (N%3 == 0) {
					output = string(N, '5')+string(num3, '3');
					break;
				}
			}
			if (output.empty()) {
				outputs.push_back(string("-1"));
			} else {
				outputs.push_back(output);
			}
		}
	}
	for (const auto &output : outputs) {
		cout << output << endl;
	}
    return 0;
}
