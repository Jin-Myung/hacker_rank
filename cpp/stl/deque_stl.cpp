#include <iostream>
#include <deque>
#include <vector> 

using namespace std;

int get_max(const deque<int> &sub, int &idx) {
    int max = -1;
    for (int ii = 0; ii < sub.size(); ii++) {
        if (sub[ii] > max) {
            max = sub[ii];
            idx = ii;
        }
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr;
        while (N--) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        int max_idx = -1;
        deque<int> sub(arr.begin(), arr.begin()+K);
        int next = K;
        do {
            if (-1 == max_idx) {
                cout << get_max(sub, max_idx) << " ";
            } else {
                if (sub[max_idx] > sub.back()) {
                    cout << sub[max_idx] << " ";
                } else {
                    max_idx = sub.size()-1;
                    cout << sub.back() << " ";
                }
            }
            if (next == arr.size()) {
                break;
            }
            sub.push_back(arr[next]);
            sub.pop_front();
            --max_idx;
            ++next;
        } while (1);
        cout << endl;
    }
    return 0;
}
