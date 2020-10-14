#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define mino "chutieu"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_par
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define Down(i,a,b) for(int i=a;i>=b;i--)
#define FOR_(i,a,b) for(int i=a;i<b;i++)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 1e6 + 5;

using namespace std;

typedef pair<int,int> pii;

int n,m,u[N],v[N];
string g[505], F[505], g2[505];

string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}

void solve(int m, int n)
{
    string res = mul(g[m],g[n]);
    res = mul(res, g2[m]);
    res = mul(res, F[n]);
    cout << res << '\n';
}
int main()
{
    turbo
    freopen("chutieu.inp","r",stdin);
    freopen("chutieu.out","w",stdout);
    int i = 1;
    g[0] = g2[0] = "1";
    g[1] = g2[1] = "1";
    g[2] = g2[2] = "2";
    FOR(i,3,500)
    {
        g[i] = add(add(g[i-1],g[i-2]),g[i-3]);
    }
    FOR(i,3,500)
    {
        g2[i] = add(g2[i-1],g2[i-2]);
    }
    FOR(i,1,500)
    {
        if(i >= 3) F[i] = add(add(F[i-1],F[i-2]), g2[i-3]);
    }
    while(true)
    {
        cin >> u[i] >> v[i];
        if(u[i] == 0) break;
        solve(u[i],v[i]);
        i++;
    }
}
