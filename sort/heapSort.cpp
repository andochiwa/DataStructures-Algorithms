#include<bits/stdc++.h>
using namespace std;

void heapDown(vector<int>& a, int i, int n) {
    int parent = i;
    for (int child = i * 2 + 1; child < n; child = child * 2 + 1) {
        if (child + 1 < n && a[child] < a[child + 1]) {
            child++;
        }
        if (a[parent] < a[child]) {
            swap(a[parent], a[child]);
            parent = child;
        }
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapDown(a, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapDown(a, 0, i);
    }
}

int main() {
    vector<int> a{1, 2, 4, 7, 2, 3, 5, 2, 7, 1, 3, 33, 23, 45, 34, 42, 22, 36};
    heapSort(a);
    for (auto& n : a) {
        cout << n << " ";
    }
    return 0;
}

