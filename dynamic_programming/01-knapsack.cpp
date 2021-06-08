#include<bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/2/
    有 N 件物品和一个容量是 M 的背包。每件物品只能使用一次。

    第 i 件物品的体积是 vi，价值是 wi。

    求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，M，用空格隔开，分别表示物品数量和背包容积。

    接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

    输出格式
    输出一个整数，表示最大价值。
*/

const int N = 1010;

// dp[i][j] 表示选i个物品，背包重量为j时的价值
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
            // 不选的情况
            dp[i][j] = dp[i - 1][j];
            // 在背包容量够的情况下才选，然后考虑不选和选的最大值
            if (j >= v[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    // 转成一维，因为第i的状态只需要依赖i - 1的状态，所以可以从后往前遍历，这样前面就是i - 1的状态
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            d[j] = max(d[j], d[j - v[i]] + w[i]);
        }
    }
    cout << dp[n][m] << endl;
    cout << d[m] << endl;
    return 0;
}