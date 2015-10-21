#include <vector>
#include <iostream>

using namespace std;

int find_start_loc(const vector<int> &fuel) {
    for (int ii = 0; ii < fuel.size(); ++ii) {
        int rem = 0;
        for (int jj = ii; jj < fuel.size(); ++jj) {
            rem += fuel[jj];
            if (rem < 0) {
                break;
            }
        }
        if (rem >= 0) {
            for (int jj = 0; jj < ii; ++jj) {
                rem += fuel[jj];
                if (rem < 0) {
                    break;
                }
            }
        }
        if (rem < 0) {
            continue;
        }
        return ii;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> fuel;
    while (N--) {
        int f, d;
        cin >> f >> d;
        fuel.push_back(f-d);
    }
    cout << find_start_loc(fuel) << endl;
}
