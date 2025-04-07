/*
题目描述
一个整数如果按从低位到高位的顺序，奇数位（个位、百位、万位 · · · ）上的数字是奇数，偶数位（十位、千位、十万位 · · · ）上的数字是偶数，我们就称之为“好数”。给定一个正整数 N，请计算从 1 到 N 一共有多少个好数。
输入格式
一个整数 N。
输出格式
一个整数代表答案。
样例输入
24
样例输出
7
提示
对于第一个样例，24 以内的好数有 1、3、5、7、9、21、23，一共 7 个。试题 C: 好数 4第十五届蓝桥杯大赛软件赛省赛 C/C++ 大学 B 组【评测用例规模与约定】对于 10% 的评测用例，1 ≤ N ≤ 100。对于 100% 的评测用例，1 ≤ N ≤ 107。
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e7+5;
int n;
int ans;

bool check(int x){
    bool even_flag=true;
    for(;x;x/=10){
        int b=x%10;
        if(even_flag){
            if(b%2==0)return false;
        }else{
            if(b%2)return false;
        }
        even_flag^=1;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    // cout<<check(3)<<endl;
    for(int i=1;i<=n;++i){
        ans+=check(i);
    }
    cout<<ans<<endl;
    return 0;
}