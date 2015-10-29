#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cand {
    size_t sa;
    size_t sb;
    int len;
public:
    bool operator<(const Cand &rhs) {
        return sa < rhs.sa;
    }
};

bool operator>(const Cand &lhs, const Cand &rhs) {
    return 
        ((lhs.sa >= rhs.sa) && (lhs.sb > rhs.sb) && (lhs.len <= rhs.len))
        || ((lhs.sa > rhs.sa) && (lhs.sb >= rhs.sb) && (lhs.len <= rhs.len))
        ;
}

void non_dom_sort(vector<Cand> &arr) {
    sort(arr.begin(), arr.end());
    arr.erase(
        unique(arr.begin(), arr.end(), [](const Cand &a, const Cand &b){ return (a.sa == b.sa) && (a.sb == b.sb) && (a.len == b.len); }),
        arr.end()
        );
    if (arr.size() <= 1) {
        return;
    }
//    nth_element(cand_arr.begin(), cand_arr.end()+1, cand_arr.end(), greater<Cand>());
    vector<Cand> new_arr;
    for (const Cand &cnd : arr) {
        bool dominated = false;
        for (const Cand &to : arr) {
            if (cnd > to) {
                dominated = true;
                break;
            }
        }
        if (false == dominated) {
            new_arr.push_back(cnd);
        }
    }
    swap(arr, new_arr);
    sort(arr.begin(), arr.end());
    arr.erase(
        unique(arr.begin(), arr.end(), [](const Cand &a, const Cand &b){ return (a.sa == b.sa) && (a.sb == b.sb) && (a.len == b.len); }),
        arr.end()
        );
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<Cand> cand_arr;
    cand_arr.push_back(Cand{0, 0, 0});
    int max_child_len = 0;
    while(1) {
        vector<Cand> next_arr;
        for (const Cand &cnd : cand_arr) {
            for (int ch = 'A'; ch <= 'Z'; ++ch) {
                size_t pos_a = a.find(ch, cnd.sa);
                if (pos_a == string::npos) {
                    continue;
                }
                size_t pos_b = b.find(ch, cnd.sb);
                if (pos_b == string::npos) {
                    continue;
                }
                next_arr.push_back(Cand{pos_a+1, pos_b+1, cnd.len+1});
            }
        }
        non_dom_sort(next_arr);
//        cout << "================================================\n";
        for (const Cand &cnd : next_arr) {
//            cout << cnd.sa << " " << cnd.sb << ": " << cnd.len << endl;
            if (cnd.len > max_child_len) {
                max_child_len = cnd.len;
            }
        }
        if (next_arr.empty()) {
            break;
        }
        swap(cand_arr, next_arr);
    }
    cout << max_child_len << endl;
    return 0;
}

