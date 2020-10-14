#include<bits/stdc++.h>

using namespace std;

/// WRITE CODE AND DRINK A CUP OF MILK TEA :D.
#define task "DIGIT"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int,int> pii;

const int oo = 2e9;
const ll inf = 1e15;
const int N = 1e3 + 5;

int n , k;
string dp[2][N];

string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i < k; ++i) dp[0][i] = "1";
    for (int i = 0; i < k; ++i) dp[1][i] = "0";
    for (int i = 2; i <= n; ++i) {
        string pre = "0";
        for (int j = 1; j < k; ++j) pre = add(pre,dp[0][j]);
        string sum = add(pre,dp[0][0]);
        /// pre does not consist 0
        for (int j = 0; j < k; ++j) {
            if (j == 0) dp[1][j] = add(dp[1][j],pre);
            else dp[1][j] = add(dp[1][j],sum);
        }
        for (int j = 0; j < k; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = "0";
        }
    }
//    for (int i = 0; i < k; ++i) cout << dp[0][i] << ' ';
    string ans = "0";
    for (int i = 0; i < k; ++i) ans = add(ans,dp[0][i]);
    if (n == 1) ans = add(ans,"1");
    cout << ans ;
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    solve();
}
/// LOOK AT MY CODE, MY CODE IS AMAZING :D.










