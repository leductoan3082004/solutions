/* NTD214 */
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define cl cout<<endl
#define For(i,a,b) for (int i=a; i<=b; i++)
#define Forr(i,a,b) for (int i=a; i<b; i++)
#define Refor(i,a,b) for (int i=a; i>=b; i--)
#define Reforr(i,a,b) for (int i=a; i>b; i--)
#define pb push_back
#define vi vector<int>
#define _io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PROB "PS"
using namespace std;
const int N=100005;
int n,a[N],leftt,rightt,pos[N],k;
ll Min=100000000000000000,f[N];
void init()
{
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
}
void readdata()
{
    cin>>n;
    For(i,1,n)
    {
        scanf("%d",&a[i]);
        f[i]=f[i-1]+a[i];
        if (f[i]>0)
        {
            leftt=0;
            rightt=i;
        }
        if (f[i]<Min)
        {
            Min=f[i];
            k=i;
        }
        pos[i]=k;
    }
}
void solve()
{
    int l=pos[n],r=n;
    while (l>0)
    {
        while(f[r]-f[l]<=0&&r>l) r--;
        if (r-l>rightt-leftt)
        {
            rightt=r;
            leftt=l;
        }
        if (r-l==rightt-leftt&&l<leftt)
        {
            leftt=l;
            rightt=r;
        }
        l=pos[l-1];
    }
    cout<<leftt+1<<" "<<rightt;

}
int main()
{
    init();
    readdata();
    solve();
}
