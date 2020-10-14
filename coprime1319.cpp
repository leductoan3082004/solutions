#include<bits/stdc++.h>
using namespace std;

#define task "coprime1319"
#define fi first
#define se second

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
typedef long long ll;
typedef pair<int,int> pii;

const int mxn=1e5+5;
int p[]={2,3,5,7,11};
int m[mxn],n,st[40][4*mxn];
vector<ll> s;
ll a[mxn];

void update(int mask, int i, int l, int r, int p, int val)
{
    if(p>r||p<l) return;
    if(l==r)
    {
        st[mask][i]=max(st[mask][i],val);
        return;
    }
    int mid=(l+r)>>1;
    update(mask,i<<1,l,mid,p,val);
    update(mask,i<<1|1,mid+1,r,p,val);
    st[mask][i]=max(st[mask][i<<1],st[mask][i<<1|1]);
}
int get(int mask, int i, int l, int r, int u, int v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[mask][i];
    int mid=(l+r)>>1;
    return max(get(mask,i<<1,l,mid,u,v),get(mask,i<<1|1,mid+1,r,u,v));
}
void solve()
{
    read(n);
    for(int i=1;i<=n;++i)
    {
        read(a[i]);
        s.push_back(a[i]);
        for(int j=0;j<5;++j)
            if(a[i]%p[j]==0) m[i]|=(1<<j);
    }
//    for(int i=1;i<=n;++i) cout<<m[i]<<' ';
//    cout<<endl;
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());

    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int k=lower_bound(s.begin(),s.end(),a[i])-s.begin()+1;
        int val=0;
        for(int mask=0;mask<(1<<5);++mask)
        {
//            if(i==2&&mask==2) cout<<m[i]<<' '<<get(mask,1,1,n,1,k-1)<<'\n';
            if((mask&m[i])==0)
            {
//                if(i==2&&mask==2) cout<<"uwu\n";
                val=max(val,get(mask,1,1,n,1,k-1));
            }
        }
        ans=max(ans,val+1);
        update(m[i],1,1,n,k,val+1);
    }
//    cout<<(9&2)<<'\n';
//    cout<<get(2,1,1,n,1,n)<<'\n';
//    cout<<get(9,1,1,n,1,n)<<'\n';
    write(ans);
}
int main()
{
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    solve();
}
