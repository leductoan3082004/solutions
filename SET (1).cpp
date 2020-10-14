#include<bits/stdc++.h>
#define mino "test"

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

const int N = 1e5 + 5;

using namespace std;

typedef pair<ll,int> pii;


int T, top;
pii S[N];

int check(int x)
{
    int t = sqrt(x * 2);
    if(t * (t + 1) == x * 2) return 1;
    return 0;
}

int main()
{
    //freopen(mino".inp","r",stdin);
    //freopen(mino".out","w",stdout);


    turbo

    cin >> T;

    while( T-- )
    {
        top = 0;
        int k, a, b, m;
        cin >> k >> a >> b;
        cin >> m;

        S[++top] = mp(a, b);

        if ( (b - a) % k == 0 )
        {
            a += (k - a % k);
            b += (k - b % k);
            while( a % k == 0 && b % k == 0 )
            {
                S[++top] = mp(a/k, b/k);
                a /= k;
                b /= k;
            }
        }

        //FOR(i,1,top) cout << S[i].fi << ' ' << S[i].se << endl;

        while( m-- )
        {
            int p, q;
            cin >> p >> q;
            int cc = 0;
            FOR(j,1,top)
            {

                if( p < q && (q-p) % (S[j].se - S[j].fi) == 0 )
                {
                    cc = 1;
                    break;
                }
            }
            if( cc ) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}
