/*
题目描述
小蓝想制作一个吊坠，他手上有 n 个长度为 m 的首尾相连的环形字符串{s1, s2, · · · , sn} ，他想用 n − 1 条边将这 n 个字符串连接起来做成吊坠，要求所有的字符串连完后形成一个整体。连接两个字符串 si, sj 的边的边权为这两个字符串的最长公共子串的长度（可以按环形旋转改变起始位置，但不能翻转），小蓝希望连完后的这 n − 1 条边的边权和最大，这样的吊坠他觉得最好看，请计算最大的边权和是多少。

输入格式
输入的第一行包含两个正整数 n, m ，用一个空格分隔。

接下来 n 行，每行包含一个长度为 m 的字符串，分别表示 s1, s2, · · · , sn 。

输出格式
输出一行包含一个整数表示答案。

样例输入
4 4
aabb
abba
acca
abcd
样例输出
8
提示
【样例说明】

连接 < 1, 2 >, < 2, 3 >, < 2, 4 > ，边权和为 4 + 2 + 2 = 8

【评测用例规模与约定】

对于 20% 的评测用例，1 ≤ n, m ≤ 10 ；

对于所有评测用例，1 ≤ n ≤ 200 ，1 ≤ m ≤ 50 。所有字符串由小写英文字母组成。
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,mm;
struct Edge
{
	int u,v,w;
	bool operator<(const Edge&o)const{
		return w>o.w;
	}
};

vector<int>fa;
vector<Edge>edges;
vector<string>input;
int ans;
int ecnt;

void Init(){
	mm=m*2;
	fa.resize(n);
	edges.resize(n*(n-1)>>1);
	input.resize(n);
	iota(fa.begin(),fa.end(),0);
}
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	fa[Find(x)]=Find(y);
}
void Kruskal(){
	for(Edge&e:edges){
		if(Find(e.u)!=Find(e.v)){
			Union(e.u, e.v);
			ans+=e.w;
		}
	}
}
int LCS(string a,string b){
	string ta=a+a,tb=b+b;
	vector<vector<int>>dp(mm,vector<int>(mm));
	for(int i=1;i<mm;++i)
		for(int j=1;j<mm;++j)
			dp[i][j]=ta[i]==tb[j]?dp[i-1][j-1]+1:0;
	int mx=0;
	for(auto&r:dp)for(int c:r)mx=max(mx,c);
	return min(m,mx);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	Init();

	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		for(int j=0;j<i;++j)
			edges[ecnt++]={i,j,LCS(s,input[j])};
		input[i]=s;
	}
	sort(edges.begin(),edges.end());
	Kruskal();
	cout<<ans<<endl;
	return 0;
}