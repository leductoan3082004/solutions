#include<bits/stdc++.h>
using namespace std;
#define task "orderset"
#define lwb lower_bound
#define upb upper_bound
#define ar array
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ALL(v) (v).begin(), (v).end()
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

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
const int N=2e5+5;
int m;
vector<int> st;
vector<pair<char,int>> q;
vector<int> s;

void upd(int i, int l, int r, int p, int val)
{
    if(l==r)
    {
        st[i]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) upd(i<<1,l,mid,p,val);
    else upd(i<<1|1,mid+1,r,p,val);
    st[i]=st[i<<1]+st[i<<1|1];
}
int get(int i, int l, int r, int u, int v)
{
    if(u>r||v<l) return 0;
    if(u<=l&&r<=v) return st[i];
    int mid=(l+r)>>1;
    return get(i<<1,l,mid,u,v)+get(i<<1|1,mid+1,r,u,v);
}
void solve()
{
    read(m);
    for(int i=1;i<=m;++i)
    {
        char c; int val;
        c=getchar();
        read(val);
        q.push_back({c,val});
        s.push_back(val);
    }
    s.push_back(-1e9-1);
    sort(ALL(s));
    s.resize(unique(ALL(s))-s.begin());
    int n=s.size();
    st.resize(4*n);
    for(auto i:q)
    {
        char c=i.fi;
        if(c=='I')
        {
            int val=lwb(ALL(s),i.se)-s.begin();
            upd(1,1,n,val,1);
        }
        if(c=='D')
        {
            int val=lwb(ALL(s),i.se)-s.begin();
            upd(1,1,n,val,0);
        }
        if(c=='K')
        {
            //int val=lwb(ALL(s),i.se)-s.begin();
            int res=-1,l=1,r=n;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(get(1,1,n,1,mid)>=i.se)
                {
                    res=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(res==-1) puts("invalid");
            else
            {
                write(s[res]);
                putchar('\n');
            }
        }
        if(c=='C')
        {
            int val=lwb(ALL(s),i.se)-s.begin();
            write(get(1,1,n,1,val-1));
            putchar('\n');
//            cout<<get(1,1,n,1,val-1)<<'\n';
        }
    }
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




