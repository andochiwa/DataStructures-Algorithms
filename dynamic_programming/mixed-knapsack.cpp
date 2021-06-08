#include <bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/7/
    有 N 种物品和一个容量是 V 的背包。

    物品一共有三类：

    第一类物品只能用1次（01背包）；
    第二类物品可以用无限次（完全背包）；
    第三类物品最多只能用 si 次（多重背包）；
    每种体积是 vi，价值是 wi。

    求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

    接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

    si=−1 表示第 i 种物品只能用1次；
    si=0 表示第 i 种物品可以用无限次；
    si>0 表示第 i 种物品可以使用 si 次；
    输出格式
    输出一个整数，表示最大价值。
*/

// 思路：分开处理，把多重背包转成01背包，然后01背包和完全背包分开单独处理即可
const int N = 1010;

int n, m;
vector<vector<int>> dp(N, vector<int>(N, 0));
vector<int> d(N, 0);
vector<int> v(N), w(N), s(N);

int main(void) {
    cin >> n >> m;
    vector<vector<int>> count;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
        if (s[i] == -1) {
            count.push_back({-1, v[i], w[i]});
        } else if (s[i] > 0) {
            for (int j = 1; j <= s[i]; j <<= 1) {
                count.push_back({-1, v[i] * j, w[i] * j});
                s[i] -= j;
            }
            if (s[i] > 0) {
                count.push_back({-1, v[i] * s[i], w[i] * s[i]});
            }
        } else {
            count.push_back({0, v[i], w[i]});
        }
    }
    // 二维
    for (int i = 1; i <= count.size(); i++) {
        int c = i - 1;
        if (count[c][0] == -1) {
            // 01背包
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= count[c][1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - count[c][1]] + count[c][2]);
                }
            }
        } else {
            // 多重背包
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= count[c][1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - count[c][1]] + count[c][2]);
                }
            }
        }
    }
    // 一维
    for (auto c : count) {
        if (c[0] == -1) {
            for (int j = m; j >= c[1]; j--) {
                d[j] = max(d[j], d[j - c[1]] + c[2]);
            }
        } else {
            for (int j = c[1]; j <= m; j++) {
                d[j] = max(d[j], d[j - c[1]] + c[2]);
            }
        }
    }

    cout << dp[n][m] << endl;
    cout << d[m] << endl;
}