#include <bits/stdc++.h>
using namespace std;

/*
    有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。

    每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。

    求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，V,M，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。

    接下来有 N 行，每行三个整数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。

    输出格式
    输出一个整数，表示最大价值。
*/
// 多了一维的01背包
const int N = 1010;

int n, m, V;
vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, 0)));
vector<vector<int>> d(N, vector<int>(N, 0));
vector<int> v(N), w(N), s(N);

int main(void) {
    cin >> n >> m >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= V; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k >= w[i] && j >= v[i]) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - v[i]][k - w[i]] + s[i]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            for (int k = V; k >= w[i]; k--) {
                d[j][k] = max(d[j][k], d[j - v[i]][k - w[i]] + s[i]);
            }
        }
    }

    cout << dp[n][m][V] << endl;
    cout << d[m][V] << endl;
}