#include <bits/stdc++.h>
using namespace std;

#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;

ll i,j,ii,res,tmp2,l,r,u,d,p,f[109][109][109],n,m;
string s;
vector<pll> vt;
char a[109][109];
queue<plll> q;
bool ok[1000];

void BFS(ll sta,pll x){
    q.push({{x.fi,x.se},x.fi-x.fi});
    f[sta][x.fi][x.se]=0;
    while (!q.empty()) {
        plll tmp=q.front();
        q.pop();
        if ((tmp.fi.fi>1)&&(a[tmp.fi.fi-1][tmp.fi.se]!='#')&&(f[sta][tmp.fi.fi-1][tmp.fi.se]>tmp.se+1)) {
            f[sta][tmp.fi.fi-1][tmp.fi.se]=tmp.se+1;
            q.push({{tmp.fi.fi-1,tmp.fi.se},tmp.se+1});
        }
        if ((tmp.fi.fi<n)&&(a[tmp.fi.fi+1][tmp.fi.se]!='#')&&(f[sta][tmp.fi.fi+1][tmp.fi.se]>tmp.se+1)) {
            f[sta][tmp.fi.fi+1][tmp.fi.se]=tmp.se+1;
            q.push({{tmp.fi.fi+1,tmp.fi.se},tmp.se+1});
        }
        if ((tmp.fi.se>1)&&(a[tmp.fi.fi][tmp.fi.se-1]!='#')&&(f[sta][tmp.fi.fi][tmp.fi.se-1]>tmp.se+1)) {
            f[sta][tmp.fi.fi][tmp.fi.se-1]=tmp.se+1;
            q.push({{tmp.fi.fi,tmp.fi.se-1},tmp.se+1});
        }
        if ((tmp.fi.fi<m)&&(a[tmp.fi.fi][tmp.fi.se+1]!='#')&&(f[sta][tmp.fi.fi][tmp.fi.se+1]>tmp.se+1)) {
            f[sta][tmp.fi.fi][tmp.fi.se+1]=tmp.se+1;
            q.push({{tmp.fi.fi,tmp.fi.se+1},tmp.se+1});
        }
    }
}

int main(){
    //freopen("meeting.inp","r",stdin);
    //freopen("meeting.out","w",stdout);
    IO;
    cin>>p;
    if (p==1) {
        cin>>n>>m;
        cin>>s;
        for (i=0;i<s.length();i++) {
            ok[s[i]]=true;
        }
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                cin>>a[i][j];
            }
        }
        l=oo;
        r=-oo;
        u=oo;
        d=-oo;
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                if (ok[a[i][j]]) {
                    l=min(l,j);
                    r=max(r,j);
                    u=min(u,i);
                    d=max(d,i);
                }
            }
        }
        cout<<(r-l+1)*(d-u+1);
    }
    else {
        cin>>n>>m;
        cin>>s;
        for (i=0;i<s.length();i++) {
            ok[s[i]]=true;
        }
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                cin>>a[i][j];
                if (ok[a[i][j]]) {
                    vt.push_back({i,j});
                }
            }
        }
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                for (ii=0;ii<vt.size();ii++) {
                    f[ii][i][j]=oo;
                }
            }
        }
        for (i=0;i<vt.size();i++) {
            BFS(i,vt[i]);
        }
        res=oo;
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                tmp2=0;
                for (ii=0;ii<vt.size();ii++) {
                    tmp2+=f[ii][i][j];
                }
                res=min(res,tmp2);
            }
        }
        if (res>=oo) {
            cout<<-1;
        }
        else {
            cout<<res;
        }
    }
}
