/*
题目描述
小蓝准备去星际旅行，出发前想在本星系采购一些零食，星系内有 n 颗星球，由 n − 1 条航路连接为连通图，第 i 颗星球卖第 ci 种零食特产。小蓝想出了 q 个采购方案，第 i 个方案的起点为星球 si ，终点为星球 ti ，对于每种采购方案，小蓝将从起点走最短的航路到终点，并且可以购买所有经过的星球上的零食（包括起点终点），请计算每种采购方案最多能买多少种不同的零食。
输入格式
输入的第一行包含两个正整数 n, q ，用一个空格分隔。

第二行包含 n 个整数 c1, c2, · · · , cn ，相邻整数之间使用一个空格分隔。

接下来 n − 1 行，第 i 行包含两个整数 ui, vi ，用一个空格分隔，表示一条航路将星球 ui 与 vi 相连。接下来 q 行，第 i 行包含两个整数 si, ti ，用一个空格分隔，表示一个采购方案。

输出格式
输出 q 行，每行包含一个整数，依次表示每个采购方案的答案。
样例输入
4 2
1 2 3 1
1 2
1 3
2 4
4 3
1 4
样例输出
3
2
提示
【样例说明】

第一个方案路线为 {4, 2, 1, 3} ，可以买到第 1, 2, 3 种零食；第二个方案路线为 {1, 2, 4} ，可以买到第 1, 2 种零食。

【评测用例规模与约定】

对于 20% 的评测用例，1 ≤ n, q ≤ 5000 ；对于所有评测用例，1 ≤ n, q ≤ 105，1 ≤ ci ≤ 20，1 ≤ ui, vi ≤ n，1 ≤ si, ti ≤ n。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define fi first
#define se second
const int MAXN = 1e5 + 5;
const int LOG = 20;
ll n, q;
ll c[MAXN];
vector<ll> G[MAXN];
ll id[MAXN];
ll cnt;
ll pa[MAXN][LOG];
ll bitMask[MAXN][LOG];

void dfs(ll root, ll fa)
{
    id[root] = ++cnt;
    pa[root][0] = fa;
    // bitMask[root][0] = 1 << c[root];
    for (int i = 1; i < LOG; ++i)
    {
        pa[root][i] = pa[pa[root][i - 1]][i - 1];
        // bitMask[root][i] = bitMask[root][i - 1] | bitMask[pa[root][i - 1]][i - 1];
    }
    for (int pos : G[root])
    {
        if (pos == fa)
            continue;
        dfs(pos, root);
    }
}

int solve(ll s, ll t)
{
    if (s == t)
        return 1;
    if (id[s] > id[t])
        swap(s, t);

    int mask = 0;
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (id[pa[t][i]] > id[s])
        {
            mask |= bitMask[t][i];
            t = pa[t][i];
        }
    }
    mask |= bitMask[t][0];
    t = pa[t][0];
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (id[pa[s][i]] > id[t])
        {
            mask |= bitMask[s][i];
            s = pa[s][i];
        }
    }
    mask |= bitMask[s][0];
    return __builtin_popcount(mask);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        --c[i];
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    while (q--)
    {
        ll s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }
    return 0;
}