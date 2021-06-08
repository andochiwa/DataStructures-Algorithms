#include<bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/5/
    有 N 种物品和一个容量是 V 的背包。

    第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

    求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
    输出最大价值。

    输入格式
    第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

    接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

    输出格式
    输出一个整数，表示最大价值。
*/

// 二进制优化的思路就是，将数量给拆分成1, 2, 4, ... 的形式，然后与物品组合，这样就可以把物品分成数量为1的了
// 比如价值2 数量10 就可以拆分成1, 2, 4, 3，然后物品的组合就是
// 2, 4, 8, 6，数量都为1，这样问题就转成了0-1背包
const int N = 1010;

int n, m;
vector<vector<int>> dp(N, vector<int>(N, 0));
vector<int> d(N, 0);
vector<int> v(N), w(N), s(N);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }
    // count里存的就是拆分后的物品，每个物品数量都为1
    vector<pair<int, int>> count{{0, 0}};
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= s[i]; k <<= 1) {
            count.push_back({k * v[i], k * w[i]});
            s[i] -= k;
        }
        if (s[i] > 0) {
            count.push_back({s[i] * v[i], s[i] * w[i]});
        }
    }
    int len = count.size();
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= count[i].first) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - count[i].first] + count[i].second);
            }    
        }
    }

    for (auto [x, y] : count) {
        for (int j = m; j >= x; j--) {
            d[j] = max(d[j], d[j - x] + y);
        }
    }

    cout << dp[n][m] << endl;
    cout << d[m] << endl;
    return 0;
}