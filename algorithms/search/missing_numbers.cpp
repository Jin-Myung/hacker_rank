#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> arr_n;
    while (n--) {
        int temp;
        cin >> temp;
        arr_n.push_back(temp);
    }
    cin >> n;
    vector<int> arr_m;
    while (n--) {
        int temp;
        cin >> temp;
        arr_m.push_back(temp);
    }
    sort(arr_n.begin(), arr_n.end());
    sort(arr_m.begin(), arr_m.end());
    vector<int>::const_iterator it_n = arr_n.begin();
    vector<int>::const_iterator it_m = arr_m.begin();
    vector<int> output;
    while (1) {
        if (it_n == arr_n.end() && it_m == arr_m.end()) {
            break;
        } else if (it_n == arr_n.end()) {
            while (it_m != arr_m.end()) {
                if (output.empty() || *it_m != output.back()) {
                    output.push_back(*it_m);
                }
                ++it_m;
            }
        } else if (it_m == arr_m.end()) {
            while (it_n != arr_n.end()) {
                if (output.empty() || *it_n != output.back()) {
                    output.push_back(*it_n);
                }
                ++it_n;
            }
        } else if (*it_n == *it_m) {
            ++it_n;
            ++it_m;
        } else if (*it_n < *it_m) {
            while (*it_n < *it_m) {
                if (output.empty() || *it_n != output.back()) {
                    output.push_back(*it_n);
                }
                ++it_n;
            }
        } else {
            while (*it_m < *it_n) {
                if (output.empty() || *it_m != output.back()) {
                    output.push_back(*it_m);
                }
                ++it_m;
            }
        }
    }
    for (const int &v : output) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
