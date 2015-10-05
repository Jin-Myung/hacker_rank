#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &ar, int lo, int hi) {
    int pivot = ar[hi];
    int ii = lo-1;
    int jj = hi;
    while (1) {
        while (ar[++ii] < pivot) {
            if (ii == hi) {
                break;
            }
        }
        while (ar[--jj] > pivot) {
            if (jj == lo) {
                break;
            }
        }
        if (jj <= ii) {
            break;
        }
        swap(ar[ii], ar[jj]);
    }
    swap(ar[ii], ar[hi]);
//    cout << "P: ";
//    for (int ii = lo; ii <= hi; ++ii) {
//        cout << ar[ii] << " ";
//    }
//    cout << endl;
    return ii;
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
