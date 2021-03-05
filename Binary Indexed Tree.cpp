#include<bits/stdc++.h>

using namespace std;

class BIT
{
private:
    vector<int> tree;
    int n;
public:
    BIT();
    BIT(vector<int>& nums)
    {
        build(nums);
    }
    void print();
    inline int lowbit(int x);
    void build(vector<int>& nums);
    void add(int x, int val);
    inline int getsum(int x, int y);
    inline int sum(int x);
};

void BIT::build(vector<int>& nums)
{
    n = nums.size();
    tree.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) add(i + 1, nums[i]);
}

inline int BIT::lowbit(int x)
{
    return x & -x;
}

void BIT::add(int x, int val)
{
    for(int i = x; i <= n; i += lowbit(i)) tree[i] += val;
}

inline int BIT::getsum(int x, int y)
{
    return sum(y + 1) - sum(x);
}

inline int BIT::sum(int x)
{
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tree[i];
    return res;
}

void BIT::print()
{
    for(auto i : tree) cout << i << " ";
    cout << endl;
}

int main(void)
{
    vector<int> arr;
    int n;
    cout << "输入大小" << endl;
    cin >> n;
    cout << "输入数值" << endl;
    for(int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        arr.push_back(j);
    }
    BIT bit(arr);
    bit.print();
    int x, y;
    cout << "输入查询区间" << endl;
    cin >> x >> y;
    cout << bit.getsum(x, y) << endl;
    return 0;
}