#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define fi first
#define se second
const int MAXN = 1e5 + 5;
ll n, k, t;
ll a[MAXN];
ll l, r;
ll sum1[MAXN], sum2[MAXN], num[MAXN];
bool judge(ll x)
{
    memcpy(num, a, sizeof(num));
    sort(num + 1, num + x + 1);
    for (int i = 1; i <= x; ++i)
    {
        sum1[i] = sum1[i - 1] + num[i];
        sum2[i] = sum2[i - 1] + num[i] * num[i];
    }
    double s = 1e100;
    for (int j = k; j <= x; ++j)
    {
        double avg = 1.0 * (sum1[j] - sum1[j - k]) / k;
        s = min(s, sum2[j] - sum2[j - k] - 2 * (sum1[j] - sum1[j - k]) * avg + k * avg * avg);
    }
    return s / k < t;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> t;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    l = k - 1;
    r = n + 1;
    while (l + 1 < r)
    {
        ll mid = l + ((r - l) >> 1);
        if (judge(mid))
            r = mid;
        else
            l = mid;
    }
    cout << (r == n + 1 ? -1 : r) << endl;
    return 0;
}