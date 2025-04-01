/*
题目描述
小蓝最近迷上了回文字符串，他有一个只包含小写字母的字符串 S ，小蓝可以往字符串 S 的开头处加入任意数目个指定字符：l、q、b （ASCII 码分别为：108、113、98）。小蓝想要知道他是否能通过这种方式把字符串 S 转化为一个回文字符串。
输入格式
输入的第一行包含一个整数 T，表示每次输入包含 T 组数据。接下来依次描述 T 组数据。每组数据一行包含一个字符串 S 。
输出格式
输出 T 行，每行包含一个字符串，依次表示每组数据的答案。如果可以将S 转化为一个回文字符串输出 Yes，否则输出 No 。
样例输入
3
gmgq
lqpdlbll
aaa
样例输出
Yes
No
Yes
提示
【样例说明】

对于 gmgqlq ，可以在前面加上 qlq => qlqgmgqlq 转化为一个回文字符串；

对于 pdlbll ，无法转化为一个回文字符串;

对于 aaa ，本身就是一个回文字符串。

【评测用例规模与约定】

对于 50% 的评测用例，1 ≤ |S | ≤ 1000 ，其中 |S | 表示字符串 S 的长度；对于所有评测用例，1 ≤ T ≤ 10 ，1 ≤∑|S | ≤ 106 。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define fi first
#define se second
const int MAXN = 1e6 + 5;
unordered_set<char> st = {'l', 'q', 'b'};
bool check(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        ++l, --r;
    }
    return true;
}
bool solve(string s)
{
    int l = 0, r = s.size() - 1;
    while (st.count(s[l]))
        ++l;
    while (st.count(s[r]))
        --r;
    if (l >= r)
        return true;
    return check(s.substr(l, r + 1));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        if (solve(s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}