/*
题目描述
小蓝正在和朋友们团建，有一个游戏项目需要两人合作，两个人分别拿到一棵大小为 n 和 m 的树，树上的每个结点上有一个正整数权值。

两个人需要从各自树的根结点 1 出发走向某个叶结点，从根到这个叶结点的路径上经过的所有结点上的权值构成了一个正整数序列，两人的序列的最长公共前缀即为他们的得分。给出两棵树，请计算两个人最多的得分是多少。

输入格式
输入的第一行包含两个正整数 n, m ，用一个空格分隔。

第二行包含 n 个正整数 c1, c2, · · · , cn ，相邻整数之间使用一个空格分隔，其中 ci 表示第一棵树结点 i 上的权值。

第三行包含 m 个正整数 d1, d2, · · · , dm ，相邻整数之间使用一个空格分隔，其中 di 表示第二棵树结点 i 上的权值。接下来 n − 1 行，每行包含两个正整数 ui, vi 表示第一棵树中包含一条 ui 和vi 之间的边。

接下来 m − 1 行，每行包含两个正整数 pi, qi 表示第二棵树中包含一条 pi和 qi 之间的边。

输出格式
输出一行包含一个整数表示答案。
样例输入
2 2
10 20
10 30
1 2
2 1
样例输出
1
提示
【样例说明】两个序列可以为 [10, 20] , [10, 30] ，最大前缀为 1 ；

【样例输入】

5 4

10 20 30 40 50

10 40 20 30

1 2

1 3

2 4

3 5

1 2

1 3

3 4

【样例输出】

2

【样例说明】

两个序列可以为 [10, 20, 40] , [10, 20, 30] ，最大前缀为 2 。

【评测用例规模与约定】

对于 20% 的评测用例，1 ≤ n, m ≤ 500 ；对于所有评测用例，1 ≤ n, m ≤ 2 × 105，1 ≤ ci, di ≤ 108 ，1 ≤ ui, vi ≤ n ，1 ≤ pi, qi ≤ m ，对于任意结点，其儿子结点的权重互不相同。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define fi first
#define se second
const int MAXN = 2 * 1e5 + 5;
ll n, m;
vector<ll> G1[MAXN];
vector<ll> G2[MAXN];
ll c[MAXN];
ll d[MAXN];
unordered_map<ll, ll> mp[MAXN]; // mp[i][j]=k: c1 树上的 i 位置的节点的子树中包含的权值 j 的对应的位置 k

void dfs1(ll root, ll fa)
{
    for (int pos : G1[root])
    {
        if (pos == fa)
            continue;
        mp[root][c[pos]] = pos;
        dfs1(pos, root);
    }
}

ll dfs2(ll root, ll fa, ll oth)
{
    ll mx = 0;
    for (int pos : G2[root])
    {
        if (pos == fa)
            continue;
        if (mp[oth].count(d[pos]) != 0)
            mx = max(mx, dfs2(pos, root, mp[oth][d[pos]]));
    }
    return mx + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= m; ++i)
        cin >> d[i];
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    for (int i = 1; i <= m - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }

    if (c[1] != d[1])
        cout << 0 << endl;
    dfs1(1, 1);
    cout << dfs2(1, 1, 1) << endl;
    return 0;
}