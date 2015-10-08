#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &ar, int lo, int hi) {
    int pivot = ar[hi];
    int curr = lo;
    int greater = lo;
    while (1) {
        if (ar[curr] < pivot) {
            swap(ar[curr], ar[greater]);
            ++curr;
            ++greater;
        } else {
            ++curr;
        }
        if (curr >= hi) {
            break;
        }
    }
    swap(ar[hi], ar[greater]);
//    cout << "P: ";
//    for (int ii = lo; ii <= hi; ++ii) {
//        cout << ar[ii] << " ";
//    }
//    cout << endl;
    return greater;
}

void quickSort(vector <int> &ar, int lo, int hi) {
    // Complete this function
    if (hi <= lo)
        return;
    int pivot = partition(ar, lo, hi);
    for (int ii = 0; ii < ar.size(); ++ii) {
        cout << ar[ii] << " ";
    }
    cout << endl;
    quickSort(ar, lo, pivot-1);
    quickSort(ar, pivot+1, hi);
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
