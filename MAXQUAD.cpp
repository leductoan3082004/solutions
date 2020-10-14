#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-10

int x[333], y[333], n;

double area(int a, int b, int c) {
	double s = 0;
	s += (y[a] - y[b]) * (x[a] + x[b]);
	s += (y[b] - y[c]) * (x[b] + x[c]);
	s += (y[c] - y[a]) * (x[c] + x[a]);
	s = (fabs(s)) / 2;
	return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MAXQUAD.inp","r",stdin);
    freopen("MAXQUAD.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	double best = -1000;

	for (int u = 0; u < n; u++)
	for (int v = u+1; v < n; v++) {
		double a = y[v] - y[u];
		double b = x[u] - x[v];
		double c = -(a * x[u] + b * y[u]);

		double best1 = -1000;
		double best2 = -1000;

		for (int w = 0; w < n; w++) if (w != u && w != v) {
			if (fabs(a * x[w] + b * y[w] + c) < EPS) {
				continue;
			}

			if (a * x[w] + b * y[w] + c < -EPS) {
				best1 = max(best1, area(u, v, w));
			}

			if (a * x[w] + b * y[w] + c > +EPS) {
				best2 = max(best2, area(u, v, w));
			}
		}
		best = max(best, best1 + best2);
	}
	printf("%0.6lf\n", best);
}
