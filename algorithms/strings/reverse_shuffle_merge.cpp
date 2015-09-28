#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool is_next_ch(const int ch, const vector<int> &ch_cnt, const vector<int> &front_ch_cnt) {
    for (int ii = ch+1; ii <= 'z'; ++ii) {
        if (
                front_ch_cnt[ii-'a'] > 0
                && front_ch_cnt[ii-'a'] >= ch_cnt[ii-'a']
                ) {
            return false;
        }
    }
    return true;
}

int remove_ch(string &str, const int ch) {
    string::size_type pos = str.find(ch);
    string left = str.substr(0, pos);
    string right = str.substr(pos+1);
    pos = right.find(ch);
    string right_left = right.substr(0, pos);
    string right_right = right.substr(pos+1);
    str = left + right_left + right_right;
    return 0;
}

char pick_ch(string &str, vector<int> &ch_cnt) {
    for (int ch = 'a';;++ch) {
        if (ch_cnt[ch-'a'] == 0) {
            continue;
        }
        vector<int> front_ch_cnt('z'-'a'+1, 0);
        for (int ii = 0; str[ii] != ch; ++ii) {
            front_ch_cnt[str[ii]-'a']++;
        }
        if (is_next_ch(ch, ch_cnt, front_ch_cnt)) {
            ch_cnt[ch-'a'] -= 2;
            remove_ch(str, ch);
            return static_cast<char>(ch);
        }
    }
}

string rev_shf_mrg(string str) {
    vector<int> ch_cnt('z'-'a'+1, 0);
    for (const char &ch : str) {
        ch_cnt[ch-'a']++;
    }
    string ret;
    while(false == str.empty()) {
        ret += pick_ch(str, ch_cnt);
//        cout << ret << " " << str << endl;
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    cout << rev_shf_mrg(str) << endl;
    return 0;
}
