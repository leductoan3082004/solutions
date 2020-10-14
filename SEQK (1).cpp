#include<bits/stdc++.h>
#define mino "seqk"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define Down(i,a,b) for(int i=a; i>=b; i--)
#define FOR_(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 5e3 + 5;
const ll MOD = 1e10 + 7;

using namespace std;

typedef pair<ll,int> pii;


int k, m, n;
ll F[N][N], res;

int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);


    turbo

    cin >> k >> m >> n;

    FOR_(i,1,m) F[1][i] = 1;

    FOR(i,1,n)
    {
        FOR_(j,1,m)
        {
            if( j - k > 0 ) F[i][j] = (F[i][j] + F[i-1][j-k]) % MOD;
            if( j + k < m ) F[i][j] = (F[i][j] + F[i-1][j+k]) % MOD;

            if( i == n ) res = (res + F[i][j]) % MOD;
        }
    }

    cout << res;
}
