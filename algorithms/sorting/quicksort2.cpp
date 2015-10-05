#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &ar, int lo, int hi) {
    int pivot = ar[lo];
    vector<int> part_less;
    vector<int> part_greater;
    for (int ii = lo+1; ii <= hi; ++ii) {
        if (ar[ii] < pivot) {
            part_less.push_back(ar[ii]);
        } else {
            part_greater.push_back(ar[ii]);
        }
    }
    vector<int> ar_left = vector<int>(ar.begin(), ar.begin()+lo);
    vector<int> ar_right = vector<int>(ar.begin()+hi+1, ar.end());
    ar = ar_left;
    ar.insert(ar.end(), part_less.begin(), part_less.end());
    int ret = ar.size();
    ar.push_back(pivot);
    ar.insert(ar.end(), part_greater.begin(), part_greater.end());
    ar.insert(ar.end(), ar_right.begin(), ar_right.end());
//    cout << "P: ";
//    for (int ii = lo; ii <= hi; ++ii) {
//        cout << ar[ii] << " ";
//    }
//    cout << endl;
    return ret;
}

void quickSort(vector <int> &ar, int lo, int hi) {
    // Complete this function
    if (hi <= lo)
        return;
    int pivot = partition(ar, lo, hi);
    quickSort(ar, lo, pivot-1);
    quickSort(ar, pivot+1, hi);
    for (int ii = lo; ii <= hi; ++ii) {
        cout << ar[ii] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    return 0;
}
