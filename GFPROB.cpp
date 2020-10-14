#include <bits/stdc++.h>

using namespace std;
const string filename = "GFPROB";

#define int long long

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n,m,k,s;
int par[100001];
vector<ii> AdjList[100001];
int a[100001], d[100001], p[100001];

int anc(int x)
{
	if (par[x] == x) return x;
	return par[x] = anc(par[x]);
}

void join(int x,int y)
{
	par[anc(x)] = anc(y);
}

int res = 0;

void cal_d()
{
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i=1;i<=n;i++)
	{
		par[i] = i;
		d[i] = 1e18;
	}	
	for (int i=1;i<=k;i++)
	{
		int x = a[i];
		d[x] = 0; p[x] = x;
		pq.push(ii(0,x));
	}
	while(!pq.empty())
	{
		int du = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (du != d[u])
			continue;
		for (int i=0;i<AdjList[u].size();i++)
		{
			int v = AdjList[u][i].first;
			int w = AdjList[u][i].second;
			if (d[v] > du + w)
			{
				p[v] = p[u];
				d[v] = du + w;
				pq.push(ii(d[v],v));
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> n >> m >> s >> k;
	for (int i=1;i<=k;i++)
		cin >> a[i];
	while(m--)
	{
		int u,v,w;
		cin >> u >> v >> w;
		AdjList[u].push_back(ii(v,w));
		AdjList[v].push_back(ii(u,w));
	}
	cal_d();
	vector<iii> c;
	for (int u=1;u<=n;u++)
		for (int i=0;i<AdjList[u].size();i++)
		{
			int v = AdjList[u][i].first;
			int w = AdjList[u][i].second;
			c.push_back(iii(d[u] + d[v] + w,ii(p[u],p[v])));
		}
	sort(c.begin(),c.end());
	int cnt = 0;
	for (int i=0;i<c.size();i++)
	{
		int w = c[i].first;
		int u = c[i].second.first;
		int v = c[i].second.second;
		if (anc(u) != anc(v))
		{
			res += w;
			join(u,v);
		}
		if (cnt == k-1)
			break;
	}
	cout << res + d[s];
}