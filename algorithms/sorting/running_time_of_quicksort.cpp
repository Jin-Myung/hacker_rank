#include <bits/stdc++.h>
using namespace std;

void insertionSortAll(vector<int> &ar, int &num_shift) {
    for (vector<int>::size_type ii = 1; ii < ar.size(); ++ii) {
        for (decltype(ii) jj = ii; jj > 0 && ar[jj] < ar[jj-1]; --jj) {
            swap(ar[jj], ar[jj-1]);
            ++num_shift;
        }
    }
}

int partition(vector <int> &ar, int lo, int hi, int &num_swap) {
    int pivot = ar[hi];
    int curr = lo;
    int greater = lo;
    while (1) {
        if (ar[curr] < pivot) {
            swap(ar[curr], ar[greater]);
            ++num_swap;
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
    ++num_swap;
//    cout << "P: ";
//    for (int ii = lo; ii <= hi; ++ii) {
//        cout << ar[ii] << " ";
//    }
//    cout << endl;
    return greater;
}

void quickSort(vector <int> &ar, int lo, int hi, int &num_swap) {
    // Complete this function
    if (hi <= lo)
        return;
    int pivot = partition(ar, lo, hi, num_swap);
    quickSort(ar, lo, pivot-1, num_swap);
    quickSort(ar, pivot+1, hi, num_swap);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    vector<int> arr_is = arr;
    int num_shift = 0;
    insertionSortAll(arr_is, num_shift);
    
    int num_swap = 0;
    quickSort(arr, 0, n-1, num_swap);
    cout << num_shift - num_swap << endl;

    return 0;
}
