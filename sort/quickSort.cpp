#include<bits/stdc++.h>
using namespace std;

void quickSortHandle(vector<int>& a, int low, int high) {
    if (low < high) {
        int l = low, h = high, pivot = a[low];
        while (l < h) {
            while (l < h && a[h] >= pivot) {
                h--;
            }
            a[l] = a[h];
            while (l < h && a[l] <= pivot) {
                l++;
            }
            a[h] = a[l];
        }
        a[l] = pivot;
        quickSortHandle(a, low, l - 1);
        quickSortHandle(a, l + 1, high);
    }
}

void quickSort(vector<int>& a) {
    quickSortHandle(a, 0, a.size() - 1);
}

int main() {
    vector<int> a{1, 2, 4, 7, 2, 3, 5, 2, 7, 1, 3, 33, 23, 45, 34, 42, 22, 36};
    quickSort(a);
    for (auto& n : a) {
        cout << n << " ";
    }
    return 0;
}