#include<bits/stdc++.h>

using namespace std;

template <typename T>
inline void read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' | c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
#define task "beads"
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;

const int mxn=1e5+5;
int a[mxn],st[4*mxn],l[mxn],r[mxn],n;
vector<int> s;
void update(int i, int l, int r, int p, int val)
{
    if(p>r||p<l) return;
    if(l==r)
    {
        st[i]=max(st[i],val);
        return;
    }
    int mid=(l+r)>>1;
    update(i<<1,l,mid,p,val);
    update(i<<1|1,mid+1,r,p,val);
    st[i]=max(st[i<<1],st[i<<1|1]);
}
int get(int i, int l, int r, int u, int v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    int mid=(l+r)>>1;
    return max(get(i<<1,l,mid,u,v),get(i<<1|1,mid+1,r,u,v));
}
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
    {
        read(a[i]);
        s.push_back(a[i]);
    }
    s.push_back(-2);
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());
    for(int i=n;i>=1;--i)
    {
        int k=lower_bound(s.begin(),s.end(),a[i])-s.begin();
        int tmp=get(1,1,n,k+1,n)+1;
        update(1,1,n,k,tmp);
        l[i]=tmp;
    }
//    cout<<st[1]<<'\n';
    fill(st+1,st+4*n+1,0);
    for(int i=n;i>=1;--i)
    {
        int k=lower_bound(s.begin(),s.end(),a[i])-s.begin();
        int tmp=get(1,1,n,1,k-1)+1;
        update(1,1,n,k,tmp);
        r[i]=tmp;
    }
//    for(int i=1;i<=n;++i) cout<<l[i]<<' '<<r[i]<<'\n';
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,l[i]+r[i]-1);
    write(ans);
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






