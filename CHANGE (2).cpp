/*BINH :))*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long llu;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f  first
#define s  second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)
#define EL cout<<endl
#define maxn 1005
#define vi vector<int>
#define ii pair<ll,ll>
#define vii vector<ii>
void init(){
        freopen("cf.inp","r",stdin);
        freopen("cf.out","w",stdout);
}
ll n ,s,x,a[1000],d=0,f[1000000],ans=INT_MAX;

int main(){
    IO
    //init();
    cin >> s >> n;
    FOR(i,1,n){
        cin >> a[i];
    }
    for (int j=1;j<=s*3;j++){
        f[j] = 1e8;
        for (int i=1;i<=n;i++){
            if (j < a[i]) continue;
            if (f[j-a[i]] == 1e8) continue;
            f[j] = min(f[j], f[j-a[i]] + 1);
        }
    }
    for (int j=1;j<=s*3;j++){
        for (int i=1;i<=n;i++){
            f[j] = min(f[j], f[j+a[i]] + 1);
        }
    }
    cout << f[s];
}
