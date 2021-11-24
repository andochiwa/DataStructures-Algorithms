#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp(a.size());
    int k = 0, l = low, r = mid + 1;
    while (l <= mid && r <= high) {
        temp[k++] = (a[l] < a[r]) ? a[l++] : a[r++];
    }
    while (l <= mid) {
        temp[k++] = a[l++];
    }
    while (r <= high) {
        temp[k++] = a[r++];
    }
    for (int i = 0, j = low; i < k; i++, j++) {
        a[j] = temp[i];
    } 
}

void mergeSortHandler(vector<int>& a, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSortHandler(a, low, mid);
    mergeSortHandler(a, mid + 1, high);
    merge(a, low, mid, high);
    
}

void mergeSort(vector<int>& a) {
    mergeSortHandler(a, 0, a.size() - 1);
}

int main() {
    vector<int> a{1, 2, 4, 7, 2, 3, 5, 2, 7, 1, 3, 33, 23, 45, 34, 42, 22, 36};
    mergeSort(a);
    for (auto& n : a) {
        cout << n << " ";
    }
    return 0;
}