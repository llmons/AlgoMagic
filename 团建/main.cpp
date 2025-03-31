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