#include <bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/9/
    有 N 组物品和一个容量是 V 的背包。

    每组物品有若干个，同一组内的物品最多只能选一个。
    每件物品的体积是 vij，价值是 wij，其中 i 是组号，j 是组内编号。

    求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

    输出最大价值。

    输入格式
    第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。

    接下来有 N 组数据：

    每组数据第一行有一个整数 Si，表示第 i 个物品组的物品数量；
    每组数据接下来有 Si 行，每行有两个整数 vij,wij，用空格隔开，分别表示第 i 个物品组的第 j 个物品的体积和价值；
    输出格式
    输出一个整数，表示最大价值。
*/

const int N = 1010;

int n, m;
vector<vector<int>> dp(N, vector<int>(N, 0));
vector<int> d(N, 0);
vector<int> v(N), w(N), s(N);

int main(void) {
    cin >> n >> m;

    cout << dp[n][m] << endl;
    cout << d[m] << endl;
}