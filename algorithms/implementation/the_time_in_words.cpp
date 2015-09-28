#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string get_hh_str(int hh) {
    switch(hh) {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 21: return "twenty one";
        case 22: return "twenty two";
        case 23: return "twenty three";
        case 24: return "twenty four";
        case 25: return "twenty five";
        case 26: return "twenty six";
        case 27: return "twenty seven";
        case 28: return "twenty eight";
        case 29: return "twenty nine";
    }
    return "";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hh, mm;
    cin >> hh >> mm;
    if (mm == 0) {
        cout << get_hh_str(hh) << " o' clock" << endl;
    } else if (mm == 15) {
        cout << "quarter past " << get_hh_str(hh) << endl;
    } else if (mm == 30) {
        cout << "half past " << get_hh_str(hh) << endl;
    } else if (mm == 45) {
        cout << "quarter to " << get_hh_str(hh+1) << endl;
    } else if (mm == 1) {
        cout << "one minute past " << get_hh_str(hh) << endl;
    } else if (mm == 59) {
        cout << "one minute to " << get_hh_str(hh+1) << endl;
    } else if (mm < 30) {
        cout << get_hh_str(mm) << " minutes past " << get_hh_str(hh) << endl;
    } else {
        cout << get_hh_str(60-mm) << " minutes to " << get_hh_str(hh+1) << endl;
    }
    return 0;
}
