#include<bits/stdc++.h>
using namespace std;
#define task "KKDD"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int N=10005;
int a[N],n,k;
ll dp[N],cost[N][105];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int len=k;len<=min(n,2*k);++len)
    {
        multiset<int,greater<int>> s1;
        multiset<int> s2;
        vector<int> b;
        b.clear(); s1.clear(); s2.clear();
        ll sum1=0,sum2=0;
        for(int i=1;i<=len;++i) b.push_back(a[i]);
        sort(b.begin(),b.end());
        for(int i=0;i<(len+1)/2;++i)
        {
            s1.insert(b[i]);
            sum1+=b[i];
        }
        for(int i=(len+1)/2;i<len;++i)
        {
            s2.insert(b[i]);
            sum2+=b[i];
        }
//        cout<<s1.size()<<' '<<s2.size()<<'\n';
//        for(int i:b) cout<<i<<' ';
//        cout<<endl;
        cost[len][len]=(*s1.begin())*s1.size()-sum1+sum2-(*s1.begin())*s2.size();
//        cout<<len<<' '<<cost[len][len]<<endl;
        for(int i=len+1;i<=n;++i)
        {
            if(s1.find(a[i-len])!=s1.end())
            {
                s1.erase(s1.find(a[i-len]));
                s1.insert(a[i]);
                sum1+=a[i];
                sum1-=a[i-len];
            }
            else if(s2.find(a[i-len])!=s2.end())
            {
                s2.erase(s2.find(a[i-len]));
                s2.insert(a[i]);
                sum2+=a[i];
                sum2-=a[i-len];
            }
            if(s2.size()&&s1.size())
            {
                int tmp1=*s1.begin();
                int tmp2=*s2.begin();
                if(tmp1>tmp2)
                {
                    sum1-=tmp1;
                    sum2-=tmp2;
                    s1.erase(s1.begin());
                    s2.erase(s2.begin());
                    sum1+=tmp2;
                    sum2+=tmp1;
                    s1.insert(tmp2);
                    s2.insert(tmp1);
                }
            }
//            cout<<s1.size()<<' '<<s2.size()<<' '<<(*s1.begin())<<' '<<sum1<<' '<<sum2<<'\n';
            cost[i][len]=(*s1.begin())*s1.size()-sum1+sum2-(*s1.begin())*s2.size();
        }
    }
    for(int i=0;i<=n;++i) dp[i]=1e15;
    dp[0]=0;
//    cout<<cost[4][4]<<endl;
//    for(int i=1;i<=n;++i,cout<<endl)
//        for(int j=k;j<=2*k;++j) cout<<cost[i][j]<<' ';
    for(int i=1;i<=n;++i)
    {
        for(int j=k;j<=min(i,k*2);++j)
        {
            dp[i]=min(dp[i],dp[i-j]+cost[i][j]);
        }
    }
    cout<<dp[n];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}





