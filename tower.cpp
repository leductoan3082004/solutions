#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct two
{
    int s,f;
    ll h;
    int pos;
};
const int N=1e6+5;
ll f[N];
int trace[N],n;
two a[N];
void init()
{
    freopen("tower.inp","r",stdin);
    freopen("tower.out","w",stdout);
}
bool cmp ( two a, two b )
{
    return a.s < b.s;
}
void nhap()
{
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>a[i].f>>a[i].s>>a[i].h;
        a[i].pos = i;
    }
    sort(a+1,a+n+1,cmp);
}
int BS(int l, int r, ll val)
{
    int ans = 0;
    while (l <= r ){
        int mid = (l+r)/2;
        if (a[mid].s <= val) {
            ans = mid;
            l = mid+1;
        }
        else r = mid - 1;
    }
    return ans;
}
void xuli()
{
    for (int i=1; i<=n; i++) {
        int j = BS(1,i-1,a[i].f) ;
        if (f[j] + a[i].h > f[i-1] ) {
            f[i] = f[j] + a[i].h;
            trace[i] = j;
        }
        else {
            trace[i] = i-1;
            f[i] = f[i-1];
        }
    }
    cout<<f[n]<<'\n';
    int k = n;
    int sum = 0;
    while (k!=0 ){
        int t = trace[k];
        if (f[t] == f[k] ){
            k = trace[k];
            continue;
        }
        else {
            cout<<a[k].pos<<' ';
            k = trace[k];
        }
    }
}
int main()
{
    init();
    nhap();
    xuli();
}

