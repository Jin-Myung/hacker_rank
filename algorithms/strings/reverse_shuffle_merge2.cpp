#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool possible_input(
        const string ins,
        const string cand
        ) {
//    cout << ins << endl;
//    cout << cand << endl;
    string::const_iterator iit = ins.cbegin();
    string::const_iterator cit = cand.cbegin();
    while (1) {
        string::const_iterator nit = find(iit, ins.cend(), *cit);
//        cout << distance(ins.cbegin(), iit) << " " << distance(cand.cbegin(), cit) << " " << distance(ins.cbegin(), nit) << endl;
        if (nit == ins.cend()) {
            return false;
        }
        iit = nit+1;
        ++cit;
        if (cit == cand.cend()) {
            return true;
        }
    }
    return false;
}

int main() {
    string orig, ins;
    cin >> orig;
    ins = orig;
    sort(ins.begin(), ins.end(), greater<char>());
    string input;
    for (int ii = 0; ii < ins.size(); ii += 2) {
        input += ins[ii];
    }
    do {
//        cout << input << endl;
        if (possible_input(orig, input)) {
            break;
        }
    } while (prev_permutation(input.begin(), input.end()));
    reverse(input.begin(), input.end());
    cout << input << endl;
    return 0;
}

