const int dx[4]={-1, 0, 1, 0};
const int dy[4]={0, 1, 0, -1};
int a[10][10];

int f[1<<16];
int danhdau[1<<16];

int BIT(int mask, int i) {
    return (mask>>i)&1;
}

int turnon(int mask, int i) {
    return mask^(1<<i);
}
int calc(int mask) {
        if (mask==(1<<16)-1) return 0;
        if (danhdau[mask]++) return f[mask];
        vector<int> dd;
        for (int i=0;i<16;i++)
        {
                int bit=BIT(mask, i);
                if (bit==0)
                {
                        int x=i/4+1;
                        int y=i%4+1;
                        if (x==1||y==1||x==4||y==4) dd.push_back(i);
                        else
                        {
                                for (int h=0;h<4;h++)
                                {
                                        int u=x+dx[h];
                                        int v=y+dy[h];
                                        int store=(u-1)*4+v-1;
                                        int ok=BIT(mask, store);
                                        if (ok==1)
                                        {
                                                dd.push_back(i);
                                                break;
                                        }
                                }
                        }
                }
        }
        int sz=__builtin_popcount(mask);
        int &res=f[mask];
        if (sz&1) res=INT_MAX;///get min
        else res=INT_MIN;///get max
        for (int store : dd)
        {
                int x=store/4+1;
                int y=store%4+1;
                int next_mask=turnon(mask, store);
                int next_dp=calc(next_mask);
                if (sz&1)
                {
                        res=min(res, next_dp-a[x][y]);
                }
                else
                {
                        res=max(res, next_dp+a[x][y]);
                }
        }
        return res;
}
int maxDiff(std::vector<string> b)
{
        int n=4;
        vector<int> gt;
        for (int i=0;i<n;i++)
        {
                int j=0;
                int sz=b[i].size();
                while (j<sz)
                {
                        int k=j;
                        int val=0;
                        while (k<sz&&b[i][k]>='0'&&b[i][k]<='9')
                        {
                                val=val*10+(b[i][k]-'0');
                                k++;
                        }
                        gt.push_back(val);
                        j=k+1;
                }
        }
        for (int i=1, ct=0;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                        a[i][j]=gt[ct++];
                }
        }
        return calc(0);

}
