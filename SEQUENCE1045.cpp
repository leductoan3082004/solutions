#include<bits/stdc++.h>
using namespace std;
#define task "SEQUENCE1045"
typedef pair<int,int> ii;
typedef long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
string to_str(int x)
{
    string ans = "";
    while (x) {
        ans = ans + char((x % 10) + '0');
        x /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        string A = "1", B = "1";
        cin >> n >> m;
        for (int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            A = mul(A,to_str(x));
        }
        for (int i = 0; i < m; i ++) {
            int x;
            cin >> x;
            B = mul(B,to_str(x));
        }
        if (A == B) cout << "YES\n";
        else cout << "NO\n";
    }
}





