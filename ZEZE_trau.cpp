#include<bits/stdc++.h>

using namespace std;

#define task "ZEZE"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 1e5 + 5;
ll a[N], n, ans = 0;

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
void process(string &s)
{
    int pos = 1000000;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] != '0')  break;
        else {
            pos = i;
            ans ++;
        }
    }
    s = s.substr(0,pos);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    string cur = "1";
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        cur = mul(s,cur);
        process(cur);
    }
    cout << ans;
}










