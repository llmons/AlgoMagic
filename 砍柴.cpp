// #pragma GCC optimize("02")
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e+5;

bool isP(int x){
    if(x<=1)return false;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)return false;
    return true;
}

void init(vector<int>&p){
    for(int i=2;i<MAXN;++i)
        if(isP(i))p.emplace_back(i);
}

int solve(int n,vector<int>&p){
    int lan_win=0;
    int last_cut=-1;
    while(n>1){
        auto it=upper_bound(p.begin(),p.end(),n)-1;
        if(it!=p.end()){
            lan_win^=1;
            n-=*it;
        }
    }
    return lan_win;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int>p;
    init(p);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<solve(n,p)<<endl;;
    }
    return 0;
}