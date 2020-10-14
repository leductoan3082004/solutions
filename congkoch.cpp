#include<bits/stdc++.h>

using namespace std;

#define task "congkoch"
#define TL ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;


vector<pair<double,double> > ans;
int n;
double Cos = 1.00 / 2.00 , Sin = (sqrt(3.00) / 2.00);
void process(int k, double xa, double ya, double xb, double yb)
{

    if (k == n + 1) {
        ans.push_back(make_pair(xa,ya));
        return;
    }
    double xm1 = (double)xa + (double)1.00 * (xb - xa) / 3.00;
    double ym1 = (double)ya + (double)1.00 * (yb - ya) / 3.00;
    double xm2 = (double)xa + (double)2.00 * (xb - xa) / 3.00;
    double ym2 = (double)ya + (double)2.00 * (yb - ya) / 3.00;
    double xm = xm1 + (double)(Cos * (xm2 - xm1)) - (double)(Sin * (ym2 - ym1));
    double ym = ym1 + (double)(Sin * (xm2 - xm1)) + (double)(Cos * (ym2 - ym1));
//    cout << xm << ' ' << ym << endl;

    process(k + 1, xa , ya , xm1 , ym1);
    process(k + 1, xm1, ym1, xm, ym);
    process(k + 1, xm , ym , xm2 , ym2);
    process(k + 1, xm2, ym2 , xb, yb);
}
int main()
{
    TL
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    process(1,0.00,0.00,100.00,0.00);
    ans.push_back(make_pair(100.00,0.00));
    for (auto k : ans) printf("%.10f %.10f\n",k.first, k.second);
}










