#include <bits/stdc++.h>
using namespace std;

/*
    https://www.acwing.com/problem/content/10/
    有 N 个物品和一个容量是 V 的背包。

    物品之间具有依赖关系，且依赖关系组成一棵树的形状。如果选择一个物品，则必须选择它的父节点。

    如下图所示：
                1
            2      3
          4   5

    如果选择物品5，则必须选择物品1和2。这是因为2是5的父节点，1是2的父节点。

    每件物品的编号是 i，体积是 vi，价值是 wi，依赖的父节点编号是 pi。物品的下标范围是 1…N。

    求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

    输出最大价值。

    输入格式
    第一行有两个整数 N，V，用空格隔开，分别表示物品个数和背包容量。

    接下来有 N 行数据，每行数据表示一个物品。
    第 i 行有三个整数 vi,wi,pi，用空格隔开，分别表示物品的体积、价值和依赖的物品编号。
    如果 pi=−1，表示根节点。 数据保证所有物品构成一棵树。

    输出格式
    输出一个整数，表示最大价值。
*/

const int N = 1010;

int n, m;
int h[N], e[N], ne[N], idx; //tot,head以i为起点第一条边储存的位置
int v[N], w[N], f[N][N];
//链式前向星,编号为b的依赖点为a
void add(int a, int b)
{
    e[idx] = b;     //记录第几个位置,b==i;
    ne[idx] = h[a]; //记录他的上一个,就是是否有同类,同一个节点
    h[a] = idx;     //更新最后出现的位置
    idx++;
}
void dfs(int u)
{
    //选哪一个物品,实质上是倒着访问,不影响
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int son = e[i]; //下一个节点
        dfs(son);       //搜索下一个节点
        //从大到小枚举,每个物品选一次,跟01一样
        for (int j = m - v[u]; j >= 0; j--)
            //决策,选哪一个,或者不选
            for (int k = 0; k <= j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]); //在
    }
    //上面的循环把位置空出来了,这里加进去,因为必须要选
    for (int i = m; i >= v[u]; i--)
        f[u][i] = f[u][i - v[u]] + w[u];
    //小于的话,因为是有依赖条件的,所以
    for (int i = 0; i < v[u]; i++)
        f[u][i] = 0; //如果选不成,那么都选不了,就归零
    
}
int main()
{
    memset(h, -1, sizeof(h)); //head,初始化为-1
    cin >> n >> m;            //物品个数,背包容量
    int root;                 //用来记录根节点
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> v[i] >> w[i] >> p; //体积,价值,依赖点
        if (p == -1)
            root = i; //根节点
        else
            add(p, i); //如果不是根节点,用链式前向星存储
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}