#include<bits/stdc++.h>
using namespace std;
#define task "concor"
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define lb lower_bound
#define ub upper_bound
#define lla(v) (v).begin(),(v).end()
#define zs(v) int((v).seize())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ar array
#define endl '\n'
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1000000007; /// 998244353
const int base=311;
const int N=2000+5;
struct four
{
    int x,y,r,m;
};
four rad[N];
pii work[N];
int n,s,d,dd[N];

ld dis(pii A, pii B, pii E)
{

    pair<ld, ld> AB;
    AB.fi = B.fi - A.fi;
    AB.se = B.se - A.se;

    pair<ld, ld> BE;
    BE.fi = E.fi - B.fi;
    BE.se = E.se - B.se;

    pair<ld, ld> AE;
    AE.fi = E.fi - A.fi,
    AE.se = E.se - A.se;

    ld AB_BE, AB_AE;
    AB_BE = (AB.fi * BE.fi + AB.se * BE.se);
    AB_AE = (AB.fi * AE.fi + AB.se * AE.se);
    ld reqAns = 0;

    if (AB_BE > 0) {
        ld y = E.se - B.se;
        ld x = E.fi - B.fi;
        reqAns = sqrt(x * x + y * y);
    }

    else if (AB_AE < 0) {
        ld y = E.se - A.se;
        ld x = E.fi - A.fi;
        reqAns = sqrt(x * x + y * y);
    }

    else {
        ld xx=-AB.se, yy=AB.fi;
        ld xa=A.fi, ya=A.se;
        ld xe=E.fi, ye=E.se;
        return abs(xx*xe+yy*ye-xx*xa-yy*ya)/sqrt(xx*xx+yy*yy);
    }
    return reqAns;
}
void solved()
{
    cin>>s>>n>>d;
    for(int i=1;i<=s;++i) cin>>rad[i].x>>rad[i].y>>rad[i].r>>rad[i].m;
    work[0]={0,0};
    for(int i=1;i<=n;++i) cin>>work[i].fi>>work[i].se;
    work[n+1]={0,0};
    ++n;
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=s;++j)
        if(!dd[j])
        {
            if(dis(work[i-1],work[i],mp(rad[j].x,rad[j].y))-(ld)rad[j].r<=d)
            {
//                cout<<i<<' '<<j<<endl;
                ans+=rad[j].m;
                dd[j]=1;
            }
        }
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solved();
}








