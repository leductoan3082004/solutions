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
#define task "KSWAP"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

const int N = 3e5 + 5;
struct two
{
    int val,cnt,pos;
};
two st[4 * N];
int a[N],n;
ll k;
two sum(two A, two B)
{
    two ans;
    ans.cnt = A.cnt + B.cnt;
    if (A.val >= B.val)
    {
        ans.val = A.val;
        ans.pos = A.pos;
    }
    else
    {
        ans.val = B.val;
        ans.pos = B.pos;
    }
    return ans;
}
void update(int i, int l, int r, int p, int val)
{
    if (p < l || p > r) return;
    if (l == r)
    {
        st[i].val = val;
        st[i].pos = l;
        if (val == -1) st[i].cnt = 0;
        else st[i].cnt = 1;
        return;
    }
    update(i*2,l,(l+r)/2,p,val);
    update(i*2+1,(l+r)/2+1,r,p,val);
    st[i] = sum(st[2*i],st[2*i+1]);
}
two get(int i, int l, int r, int u, int v)
{
    if (u > r || v < l) return {-1,0,0};
    if (u <= l && r <= v) return st[i];
    return sum(get(i*2,l,(l+r)/2,u,v),get(i*2+1,(l+r)/2+1,r,u,v));
}
int main()
{
//    TL
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);

    read(n); read(k);
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
        update(1,1,n,i,a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        ll lim = min(k + 1,(ll)(n - i + 1));
        int l = 1, r = n;
        two tmp = {0,0,0};
        while (l <= r)
        {
            int mid = (l + r) / 2;
            two seg = get(1,1,n,1,mid);
            if (seg.cnt >= lim)
            {
                r = mid - 1;
                tmp = seg;
                if (seg.cnt == lim) break;
            }
            else l = mid + 1;
        }
        write(tmp.val); putchar(' ');
        update(1,1,n,tmp.pos,-1);
        int cnt = get(1,1,n,1,tmp.pos).cnt;
        k -= 1LL * cnt;
        k = max(k,0LL);
    }
}
