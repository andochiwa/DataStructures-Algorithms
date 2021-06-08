#include<bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/3/
    有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。

    第 i 种物品的体积是 vi，价值是 wi。

    求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

    接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 种物品的体积和价值。

    输出格式
    输出一个整数，表示最大价值。
*/

const int N = 1010;

int n, m;
vector<vector<int>> dp(N, vector<int>(N, 0));
vector<int> d(N, 0);
vector<int> v(N), w(N);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i]; 
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) {
                // 这里和01不同，因为可以重复，所以是dp[i][j - v[i]]而不是d[i - 1][j - v[i]]
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        // 因为可以重复，所以状态转移位置从上一层变成了当前层，也就是已经选过的，所以不是倒序而是正序
        for (int j = v[i]; j <= m; j++) {
            d[j] = max(d[j], d[j - v[i]] + w[i]);
        }
    }
    cout << dp[n][m] << endl;
    cout << d[m] << endl;

    return 0;
}