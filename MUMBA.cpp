#include<bits/stdc++.h>

using namespace std;

#define task "MUMBA"
#define TL ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
int n,ans = 0;
void check(string s)
{
    int N = s.length();
    s = " " + s;
    for (int i = 1; i < N; ++i) {
        if (s[i] == s[i + 1] && s[i] == 'b') return;
    }

    for (int len = 1; len <= N / 3; ++len) {
        for (int i = 1; i <= N - len * 3 + 1; ++i) {
            string s1 = s.substr(i,len);
            string s2 = s.substr(i + len, len);
            string s3 = s.substr(i + 2 * len, len);
            if (s1 == s2 && s2 == s3) return;
        }
    }
    ans ++;
}
void process(int i, string s)
{
    string pre = s;
    for (int ch = 'a'; ch <= 'b'; ++ch) {
        s = s + char(ch);
        if (i < n) process(i + 1,s);
        else check(s);
        s = pre;
    }
}

int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;

    if (n >= 17) return cout << 0 ,0 ;

    process(1,"");

    cout << ans;
}









