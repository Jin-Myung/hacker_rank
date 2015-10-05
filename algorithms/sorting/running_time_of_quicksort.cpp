#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &ar, int lo, int hi, int &num_swap) {
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
        ++num_swap;
    }
    swap(ar[ii], ar[hi]);
    ++num_swap;
    return ii;
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
    
    
    int num_swap = 0;
    quickSort(arr, 0, n-1, num_swap);
    cout << num_swap << endl;

    return 0;
}
