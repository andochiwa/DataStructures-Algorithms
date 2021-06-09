#include <bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/11/
    有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

    第 i 件物品的体积是 vi，价值是 wi。

    求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。

    输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7 的结果。

    输入格式
    第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

    接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

    输出格式
    输出一个整数，表示 方案数 模 109+7 的结果。
*/

const int N = 1010;

int n, m;
int mod = 1e9 + 7;
// dp[i][j]表示选i个物品，体积为j的时的最大价值, dp2[i][j]表示选i个物品，体积为j时总价值最佳的的方案数
vector<vector<int>> dp(N, vector<int>(N, 0)), dp2(N, vector<int>(N, 0));
vector<int> d(N, INT_MIN), g(N, 0);
vector<int> v(N), w(N);

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    // 什么都不装也是一种方案
    for (int i = 0; i <= m; i++) {
        dp2[0][i] = 1;
        g[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        // 二维
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            dp2[i][j] = dp2[i - 1][j];
            if (j >= v[i]) {
                // 先保存不选当前物品时的最大价值
                int temp = dp[i][j];
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
                // 如果价值更大，说明方案需要更新。如果相等，说明方案增多
                if (dp[i][j] > temp) {
                    dp2[i][j] = dp2[i - 1][j - v[i]];
                } else {
                    dp2[i][j] += dp2[i - 1][j - v[i]] % mod;
                }
            }
        }
        // 一维
        for (int j = m; j >= v[i]; j--) {
            // 先保存不选时当前物品的最大价值
            int temp = d[j];
            d[j] = max(d[j], d[j - v[i]] + w[i]);
            // 和上面一样
            if (d[j] > temp) {
                g[j] = g[j - v[i]];
            } else {
                g[j] += g[j - v[i]] % mod;
            }
        }
    }
    
    cout << dp2[n][m] << endl;
    cout << g[m] << endl;
    
    return 0;
}