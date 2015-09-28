#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_free_ch(int num_ch, int m) {
    cout << "free_ch: " << num_ch << " " << m << endl;
	if (num_ch < m) 
		return 0;
	return num_ch / m + get_free_ch(num_ch / m + num_ch % m, m);
}

int get_answer(int n, int c, int m) {
	int num_ch = n / c;
    cout << "num_ch: " << num_ch << endl;
	num_ch += get_free_ch(num_ch, m);
	return num_ch;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=get_answer(n, c, m);
        // Computer answer
        cout<<answer<<endl;
    }
    return 0;
}
