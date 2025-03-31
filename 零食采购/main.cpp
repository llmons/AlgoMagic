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