/*https://bom.to/nxtvde2k1m4l*/
#include<bits/stdc++.h>
using namespace std;
#define task "HS"
typedef pair<int,int> ii;
typedef unsigned long long ll;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
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
vector<string> a[205];
int main()
{
    init();
    int n; cin >> n;
    a[1].push_back("1");
    a[1].push_back("1");
    for (int i = 2; i <= n; i ++) {
        a[i].push_back("1");
        for (int j = 1; j < a[i-1].size(); j ++)
        a[i].push_back(add(a[i-1][j] , a[i-1][j-1]));
        a[i].push_back("1");
    }
    for (int i = 0; i < a[n].size(); i ++) cout << a[n][i] << '\n';
}





