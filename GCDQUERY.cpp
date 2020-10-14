#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
const int N=1e5+5;
vector<int> IsPrime,pos[N],Val[N],ind[N],st[N];
int n,q,f[N];
void eth()
{
    f[0]=1;
    f[1]=1;
    for (int i=2; i<=trunc(sqrt(maxN)); i++)
    if (!f[i]){
        int j= i*2;
        while (j<=maxN){
            f[j]=1;
            j+=i;
        }
    }
    for (int i=1; i<maxN; i++)
        if (f[i]==0){
            Val[i].push_back(-1);
            pos[i].push_back(-1);
            IsPrime.push_back(i);
        }
}
vector<int> FactX(int x)
{
    vector<int> ans;
    ans.clear();
    int k=x;
    for (int i=0; i<IsPrime.size(); i++){
        if (IsPrime[i]>k) break;
        if (k%IsPrime[i]==0){
                ans.push_back(IsPrime[i]);
                while (k%IsPrime[i]==0) k/=IsPrime[i];
        }
    }
    return ans;
}
void build(int k, int i, int l, int r)
{
    if (l==r){
        st[k][i]=Val[k][l];
        return;
    }
    build(k,2*i,l,(l+r)/2);
    build(k,2*i+1,(l+r)/2+1,r);
    st[k][i]=max(st[k][2*i],st[k][2*i+1]);
}
int get(int k, int i, int l, int r, int u, int v)
{
    if (u>r||v<l) return -1;
    if (u<=l&&r<=v) return st[k][i];
    return max(get(k,i*2,l,(l+r)/2,u,v),get(k,i*2+1,(l+r)/2+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    eth();
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        ind[x].push_back(i);
        vector<int > a = FactX(x);
        for (int j=0; j<a.size(); j++){
            pos[a[j]].push_back(i);
            Val[a[j]].push_back(x);
        }
    }
    for (int i=0; i<IsPrime.size(); i++){
        int val=IsPrime[i];
        int sz=pos[val].size()-1;
        if (sz==0) continue;
        st[IsPrime[i]].resize(4*sz);
        build(IsPrime[i],1,1,sz);
    }
    while (q--){
        int x,u,v,L,R;
        int ans=-1, num=0;
        cin >> x >> u >> v;
        vector<int> a = FactX(x);
        for (int i=0; i<a.size(); i++){
            int val=a[i];
            L=lower_bound(pos[val].begin(),pos[val].end(),u)-pos[val].begin();
            R=upper_bound(pos[val].begin(),pos[val].end(),v)-pos[val].begin()-1;
            int sz=pos[val].size()-1;
            int res=get(val,1,1,sz,L,R);
            if (res>=ans){
                ans=res;
                int l=lower_bound(ind[res].begin(),ind[res].end(),u)-ind[res].begin();
                int r=upper_bound(ind[res].begin(),ind[res].end(),v)-ind[res].begin()-1;
                num=(r-l+1);
            }
        }
        if (ans==-1) cout << ans << ' ' << ans << '\n';
        else cout << ans << ' ' << num << '\n';
    }
}

