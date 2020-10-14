#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")

using namespace std;

#define X first
#define Y second
#define ll long long
#define ld double
#define up_b upper_bound
#define low_b lower_bound
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

const int mod=1e9+7;
const int N=1e6;


ll Power(int x,int y)
{
    ll ans=1;
    for (ll t=x;y;y>>=1)
    {
        if (y&1) ans=(ans*t);
        t=(t*t);
    }
    return ans;
}
int Rev(int x)
{
    return Power(x,mod-2);
}

string s;
int type;
int even[N+5],odd[N+5],sum[N+5],a[N+5];
int dem[40][10];
int r[15][4],l[15][4];
string getmax(string &ans,string &res)
{
    if (ans.size()<res.size()) return res;
    if (ans.size()>res.size()) return ans;
    for (int i=0;i<ans.size();i++)
    {
        if (ans[i]>res[i]) return ans;
        if (ans[i]<res[i]) return res;
    }
    return ans;
}
int main()
{
//    freopen("BABA.inp","r",stdin);
//    freopen("BABA.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s>>type;
    int n=s.size();s=' '+s;
    for (int i=1;i<=n;i++) a[i]=s[i]-'0';
    for (int i=1;i<=n;i++)
    {
        odd[i]=odd[i-1];even[i]=even[i-1];
        if (i%2==1) odd[i]=(odd[i-2]+a[i])%11;
        if (i%2==0) even[i]=(even[i-2]+a[i])%11;
        sum[i]=sum[i-1]+a[i];
    }
    if (type==1)
    {
        ll ans=0;
        dem[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            int x=(odd[i]-even[i]+11)%11;
            int y=sum[i]%3;
            ans+=dem[x][y];
            dem[x][y]++;
        }
        cout<<ans;
    }
    else
    {
        for (int x=0;x<=10;x++)
        for (int y=0;y<=2;y++) l[x][y]=r[x][y]=-1;
        l[0][0]=0,r[0][0]=0;
        for (int i=1;i<=n;i++)
        {
            int x=(odd[i]-even[i]+11)%11;
            int y=sum[i]%3;
            r[x][y]=i;
            if (l[x][y]==-1) l[x][y]=i;
        }
        string ans="0";
        for (int x=0;x<=10;x++)
        for (int y=0;y<=2;y++)
        {
            if (l[x][y]==r[x][y]) continue;
            string res;
            res.assign(s.begin()+l[x][y]+1,s.begin()+r[x][y]+1);
            ans=getmax(ans,res);
        }
        cout<<ans;
    }
}
