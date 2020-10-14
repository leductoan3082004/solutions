#include <bits/stdc++.h>
using namespace std;

int k , n, m ;
const long long mod = 10000000007;
long long f[5500][5500];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   // freopen("SEQK.inp", "r", stdin);
   // freopen("SEQK.out", "w", stdout);
    cin >> k >> m >> n;
    for (int i=1;i<=n;i++){
        if (i == 1){
            for (int j=1;j<m;j++){
                f[i][j] = 1;
            }
        }
        else {
            for (int j=1;j<m;j++){
                long long t1, t2;
                if (j + k >= m) t1 = 0;
                else t1 = f[i-1][j+k];
                if (j - k < 1) t2 = 0;
                else t2 = f[i-1][j-k];
                f[i][j] = (t1 + t2) % mod;
            }
        }
    }
    long long res = 0;
    for (int i=1;i<m;i++)
        res = (res + f[n][i]) % mod;
        cout << res;
}
