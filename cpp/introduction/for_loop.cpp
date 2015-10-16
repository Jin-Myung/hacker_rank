#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int print(int n) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    switch (n) {
        case 1: cout << "one" << endl;
            break;
        case 2: cout << "two" << endl;
            break;
        case 3: cout << "three" << endl;
            break;
        case 4: cout << "four" << endl;
            break;
        case 5: cout << "five" << endl;
            break;
        case 6: cout << "six" << endl;
            break;
        case 7: cout << "seven" << endl;
            break;
        case 8: cout << "eight" << endl;
            break;
        case 9: cout << "nine" << endl;
            break;
        default:
            if (n % 2) {
                cout << "odd" << endl;
            } else {
                cout << "even" << endl;
            }
    } 
    return 0;
}

int main() {
    int a, b;
    cin >> a >> b;
    for (int ii = a; ii <= b; ++ii) {
        print(ii);
    }
    return 0;
}