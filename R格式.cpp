/*
小蓝最近在研究一种浮点数的表示方法：R
 格式。

对于一个大于 0
 的浮点数 d
，可以用 R
 格式的整数来表示。

给定一个转换参数 n
，将浮点数转换为 R
 格式整数的做法是:

将浮点数乘以 2n
；
四舍五入到最接近的整数。
输入格式
一行输入一个整数 n
 和一个浮点数 d
，分别表示转换参数，和待转换的浮点数。

输出格式
输出一行表示答案：d
 用 R
 格式表示出来的值。

数据范围
用 l
 表示将 d
 视为字符串时的长度。
对于 50%
 的评测用例：1≤n≤10
，1≤l≤15
。
对于 100%
 的评测用例：1≤n≤1000
，1≤l≤1024
；保证 d
 是小数，即包含小数点。

输入样例：
2 3.14
输出样例：
13
样例解释
3.14×22=12.56
，四舍五入后为 13
。
*/

#include <bits/stdc++.h>
using namespace std;

class BigInt
{
    vector<int>num;
    void fixLen(){
        while(!num.empty()&&num.back()==0)num.pop_back();
        if(num.empty())num.emplace_back(0);
    }
public:
    BigInt(){
        num.emplace_back(0);
    }
    BigInt(int x){
        for(;x>0;x/=10)num.emplace_back(x%10);
        if(num.empty())num.emplace_back(0);
    }
    BigInt(const string&s){
        int len=s.size();
        num.resize(len);
        for(int i=0,j=len-1;j>=0;--j){
            if(s[j]=='.')continue;
            num[i++]=s[j]-'0';
        }
        fixLen();
    }
    void fix(){
        int len=num.size();
        num.resize(len+1);
        for(int i=0;i<len;++i){
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
        fixLen();
    }
    BigInt operator+(const BigInt&o)const{
        BigInt ret;
        int len=max(num.size(),o.num.size());
        ret.num.resize(len+1);
        for(int i=0;i<len;++i){
            if(i<num.size())ret.num[i]+=num[i];
            if(i<o.num.size())ret.num[i]+=o.num[i];
        }
        ret.fix();
        return ret;
    }
    BigInt operator*(const BigInt&o)const{
        BigInt ret;
        int len=num.size()+o.num.size();
        ret.num.resize(len);
        for(int i=0;i<num.size();++i){
            for(int j=0;j<o.num.size();++j){
                ret.num[i+j]+=num[i]*o.num[j];
            }
        }
        ret.fix();
        return ret;
    }
    friend ostream& operator<<(ostream&os,const BigInt&x){
        for(int i=x.num.size()-1;i>=0;--i){
            os<<x.num[i];
        }
        return os;
    }
    void printWithDot(int dot){
        if(num[dot-1]>=5)++num[dot];
        fix();
        if(num.size()==dot)cout<<"0";
        for(int i=num.size()-1;i>=dot;--i)cout<<num[i];
        cout<<endl;
    }
    static BigInt fastPow(int base,int n){
        BigInt ret(1),Base(base);
        for(;n>0;n>>=1){
            if(n&1)ret=ret*Base;
            Base=Base*Base;
        }
        return ret;
    }
};



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string d;
    cin>>n>>d;
    int dot;
    for(int i=d.size()-1;i>=0;--i){
        if(d[i]=='.'){
            dot=d.size()-1-i;
            break;
        }
    }
    BigInt ans=BigInt::fastPow(2,n)*BigInt(d);
    ans.printWithDot(dot);
    return 0;
}