#include<iostream>
#include<vector>
using namespace std;

void build_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = start + (end - start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(arr, tree, left_node, start, mid);
        build_tree(arr, tree, right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end, int pos, int val)
{
    if(start == end)
    {
        arr[pos] = val;
        tree[node] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    if(pos >= start && pos <= mid) update_tree(arr, tree, left_node, start, mid, pos, val);
    else update_tree(arr, tree, right_node, mid + 1, end, pos ,val);
    tree[node] = tree[left_node] + tree[right_node];
}

int query_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end, int x, int y)
{
    if(x > end || y < start) return 0;
    else if((start >= x && end <= y) || start == end)
    {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int sum_left = query_tree(arr, tree, left_node, start, mid, x, y);
    int sum_right = query_tree(arr, tree, right_node, mid + 1, end, x, y);
    return sum_left + sum_right;
}

int main(void)
{
    vector<int> arr;
    int n;
    cout << "input size" << endl;
    cin >> n;
    cout << "input value" << endl;
    for(int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        arr.push_back(j);
    }
    vector<int> tree(1000, 0);
    build_tree(arr, tree, 0, 0, arr.size() - 1);
    for(int i = 0; i < 15; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    // update_tree(arr, tree, 0, 0, arr.size() - 1, 4, 6);
    // for(int i = 0; i < 15; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    cout << query_tree(arr, tree, 0, 0, arr.size() - 1, 2, 4) << endl;
    return 0;
}