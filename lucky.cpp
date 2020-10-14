#include<bits/stdc++.h>

using namespace std;

/// KEEP THAT IN YOUR MIND AND REVENGE
#define task "lucky"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second

typedef long long ll;
typedef pair<ll,ll> pii;

const ll mod=1e9+7;
void multiply(ll T[3][3], ll M[3][3])
{
    ll a, b, c, d, e, f, g, h, i;
    a = (T[0][0] * M[0][0] +
        T[0][1] * M[1][0] +
        T[0][2] * M[2][0])%mod;
    b = (T[0][0] * M[0][1] +
        T[0][1] * M[1][1] +
        T[0][2] * M[2][1])%mod;
    c = (T[0][0] * M[0][2] +
        T[0][1] * M[1][2] +
        T[0][2] * M[2][2])%mod;
    d = (T[1][0] * M[0][0] +
        T[1][1] * M[1][0] +
        T[1][2] * M[2][0])%mod;
    e = (T[1][0] * M[0][1] +
        T[1][1] * M[1][1] +
        T[1][2] * M[2][1])%mod;
    f = (T[1][0] * M[0][2] +
        T[1][1] * M[1][2] +
        T[1][2] * M[2][2])%mod;
    g = (T[2][0] * M[0][0] +
        T[2][1] * M[1][0] +
        T[2][2] * M[2][0])%mod;
    h = (T[2][0] * M[0][1] +
        T[2][1] * M[1][1] +
        T[2][2] * M[2][1])%mod;
    i = (T[2][0] * M[0][2] +
        T[2][1] * M[1][2] +
        T[2][2] * M[2][2])%mod;
    T[0][0] = a;
    T[0][1] = b;
    T[0][2] = c;
    T[1][0] = d;
    T[1][1] = e;
    T[1][2] = f;
    T[2][0] = g;
    T[2][1] = h;
    T[2][2] = i;
}

void power(ll T[3][3], ll n)
{
    if (n == 0 || n == 1)
        return;
    ll M[3][3] = {{ 1, 1, 1 },
                   { 1, 0, 0 },
                   { 0, 1, 0 }};

    power(T, n / 2);

    multiply(T, T);

    if (n % 2)
        multiply(T, M);
}
ll tribonacci(ll n)
{
    ll T[3][3] = {{ 1, 1, 1 },
                   { 1, 0, 0 },
                   { 0, 1, 0 }};

    // base condition
    if (n == 0 || n == 1)
        return 0;
    else
        power(T, n - 2);
    return T[0][0];
}
void solve()
{
   ll n; cin>>n;
   n+=3;
   cout<<tribonacci(n)<<'\n';
}
int main()
{
   TL
   if(fopen(task".inp","r")) {
      freopen(task".inp","r",stdin);
      freopen(task".out","w",stdout);
   }
   ll t;
   cin>>t;
   while(t--) solve();
}
/// JUST KEEP TRAINING




