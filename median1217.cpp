#include<bits/stdc++.h>

using namespace std;

#define task "median1217"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=250005;
ll seed,mul,add;
int n,k,a[mxn];
multiset<int,greater<int>> s1;
multiset<int> s2;

void ILYPTV()
{
    cin>>seed>>mul>>add>>n>>k;
    a[1]=seed;
    for(int i=2;i<=n;++i) a[i]=(1LL*a[i-1]*mul+1LL*add)%65536;

//    for(int i=1;i<=n;++i) cout<<a[i]<<' ';
//    cout<<'\n';

    vector<int> tam;
    tam.clear();
    for(int i=1;i<=k;++i) tam.push_back(a[i]);
    sort(tam.begin(),tam.end());
    for(int i=1;i<=(k+1)/2;++i) s1.insert(tam[i-1]);
    for(int i=(k+1)/2+1;i<=k;++i) s2.insert(tam[i-1]);
//    cout<
//    for(int i=1;i<=n;++i) cout<<a[i]<<' ';
//    cout<<'\n';
//    cout<<s2.size()<<'\n';
    ll ans=*s1.begin();
    for(int i=k+1;i<=n;++i)
    {
        if(!s1.empty()&&s1.find(a[i-k])!=s1.end())
        {
            s1.erase(s1.find(a[i-k]));
            s1.insert(a[i]);
        }
        else if(!s2.empty())
        {
            s2.erase(s2.find(a[i-k]));
            s2.insert(a[i]);
        }
        if(!s2.empty()&&*s1.begin()>*s2.begin())
        {
            int tmp1=*s1.begin();
            int tmp2=*s2.begin();
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            s1.insert(tmp2);
            s2.insert(tmp1);
        }
        ans+=*s1.begin();
    }
    s1.clear();
    s2.clear();
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        ILYPTV();
    }
}






