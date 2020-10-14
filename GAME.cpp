#include<bits/stdc++.h>

using namespace std;

#define task "GAME"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
int p[10][10] ={
    {-2,-1,0,-2},
    {-1,-1,-1,-1},
    {0,0,-2,-1},
    {0,-3,0,0},
    {-1,0,0,-1}
};
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    int t; cin >> t;
    while (t--) {
        vector<int> a(4);
        for (int i = 0; i < 4; ++i) cin >> a[i];
        int turn = 0;
        while (1) {
            turn ++;
            int d = 0;
            while (d < 5) {
                vector<int> b = a;
                int ok = 1;
                for (int i = 0; i < 4; ++i) {
                    b[i] += p[d][i];
                    if (b[i] < 0) ok = 0;
                }
                if (ok) {
                    a = b;
                    break;
                }
                ++d;
            }
            if (d == 5) break;
        }
        if (turn % 2 == 1) cout << "BINH";
        else cout << "AN";
        cout << '\n';
    }

}










