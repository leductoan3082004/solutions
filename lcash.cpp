#include<bits/stdc++.h>

using namespace std;

#define task "lcash"
#define fi first
#define se second
#define fore(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ford(i,a,b) for(int i=(int)a;i>=(int)b;--i)

typedef long long ll;
typedef pair<int,int> pii;

const int mxn=100005;
int n,s,a[mxn];

bool check(int num)
{
    vector<int> b;
    b.clear();
    for(int i=1;i<=num;++i){
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    ll sum=0;
    for(int i=0;i<num;++i){
        if(b[i]>sum+1) return 0;
        sum+=b[i];
        if(sum>=s) return 1;
    }
    return 0;
}
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    int l=1, r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    if(ans==0) cout<<-1;
    else cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
//    if(fopen(task".inp","r"))
//    {
//        freopen(task".inp","r",stdin);
//        freopen(task".out","w",stdout);
//    }
    solve();
}






