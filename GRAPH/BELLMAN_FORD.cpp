int n,m,s,t,trace[maxn],d[maxn];
vector<pii> a[maxn];
void bellmanford()
{
    for (int i=1; i<=n; i++) d[i]=maxc;
    d[s] = 0;
    int ok;
    while (1)
    {
        ok = 1;
        for (int u=1; u<=n; u++)
            for (int i=0; i<a[u].size(); i++)
            {
                int v = a[u][i].first;
                int w = a[u][i].second;
                if (d[v]>d[u]+w)
                {
                    d[v] = d[u]+w;
                    trace[v] = u;
                    ok=0;
                }
            }
        if (ok) break;
    }
}
void ghikq()
{
    cout << d[t] << "\n";
    int luu[maxn], dem=1;
    int k = luu[1] = t;
    while(k!=s)
        k = luu[++dem] = trace[k];
    cout << dem << "\n";
    for (int i=dem; i>=1; i--) cout << luu[i] << " ";
}

