#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int blocks = sqrt(N)+5;
int a[3*N],st[200][4*N],n;
template <typename T>
inline void Read(T& x)
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
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}
void update(int pos, int i, int l, int r, int p, int val)
{
    if ( p > r || p < l) return ;
    if (l == r) {
        st[pos][i] += val;
        return;
    }
    update(pos,i*2,l,(l+r)/2,p,val);
    update(pos,i*2+1,(l+r)/2+1,r,p,val);
    st[pos][i] = st[pos][2*i] + st[pos][2*i+1];
}
int get(int pos, int i, int l, int r, int u, int v)
{
    if ( u > r || v < l ) return 0;
    if ( u <= l && r <= v ) return st[pos][i];
    return get(pos,i*2,l,(l+r)/2,u,v) + get(pos,i*2+1,(l+r)/2+1,r,u,v);
}
void xuli()
{
    Read(n);
    int nb = sqrt(n);

    for (int i = 0; i < n; i ++) {
        int pos = i / nb;
        Read(a[i]);
        update(pos,1,1,N,a[i],1);
    }
    int m;
    Read(m);

    while (m--) {
        int t;
        Read(t);
        if (t == 0 ) {
            int i,v;
            Read(i); Read(v);
            i -- ;
            int pos = i / nb;
            update(pos,1,1,N,a[i],-1);
            a[i] = v;
            update(pos,1,1,N,a[i],1);
        }
        else {
            int u,v,k;
            Read(u); Read(v); Read(k);
            u-- ; v--;
            if ( u / nb == v / nb) {
                int ans = 0;
                for (int i = u; i <= v; i ++)
                if (a[i] > k) ans ++ ;
                Write(ans); putchar('\n');
            }
            else {
                int ans = 0, F = u / nb, S = v / nb;
                for (int i = F + 1; i < S; i ++) ans += get(i,1,1,N,k+1,N);

                for (int i = u ; i <= (F+1)*nb - 1; i ++)
                if (a[i] > k) ans ++;

                for (int i = S * nb ; i <= v ; i++)
                if (a[i] > k ) ans ++ ;
                Write(ans); putchar('\n');
            }
        }
    }
}
int main()
{
    xuli();
}
