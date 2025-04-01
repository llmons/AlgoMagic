/*
题目描述
小蓝的班上有 n 个人，一次考试之后小蓝想统计同学们的成绩，第 i 名同学的成绩为 ai 。当小蓝统计完前 x 名同学的成绩后，他可以从 1 ∼ x 中选出任意 k 名同学的成绩，计算出这 k 个成绩的方差。小蓝至少要检查多少个人的成绩，才有可能选出 k 名同学，他们的方差小于一个给定的值 T ？

提示：k 个数 v1, v2, · · · , vk 的方差 σ2 定义为：σ2 =∑ki=1(vi−v')/k ，其中 v' 表示v 的平均值，v' =∑ki=1 vi/k 。

输入格式
输入的第一行包含三个正整数 n, k, T ，相邻整数之间使用一个空格分隔。

第二行包含 n 个正整数 a1, a2, · · · , an ，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个整数表示答案。如果不能满足条件，输出 −1 。
样例输入
5 3 1
3 2 5 2 3
样例输出
4
提示
【样例说明】

检查完前三名同学的成绩后，只能选出 3, 2, 5 ，方差为 1.56 ；检查完前四名同学的成绩后，可以选出 3, 2, 2 ，方差为 0.33 < 1 ，所以答案为 4 。

【评测用例规模与约定】

对于 10% 的评测用例，保证 1 ≤ n, k ≤ 102；

对于 30% 的评测用例，保证 1 ≤ n, k ≤ 103 ；

对于所有评测用例，保证 1 ≤ n, k ≤ 105 ，1 ≤ T ≤ 231 − 1 ，1 ≤ ai ≤ n 。
*/

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