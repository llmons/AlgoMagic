#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define fi first
#define se second
const int MAXN = 1e6 + 5;
ll n, s, p, c;
ll diff[MAXN];
ll ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p >> c;
        diff[1] += p;
        diff[c + 1] -= p;
    }

    for (int i = 1; i < MAXN; ++i)
    {
        diff[i] += diff[i - 1];
        ans += min(diff[i], s);
    }

    cout << ans << endl;
    return 0;
}