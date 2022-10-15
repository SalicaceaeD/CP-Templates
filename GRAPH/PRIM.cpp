int n,m;
vector<pii> a[maxn];
int d[maxn];//khoang cach ngan nhat tu dinh u -> cay da co
int connect[maxn];
long long ans = 0;
bool used[maxn];
void nhap()
{
    cin >> n >> m;
    for (int u, v, w, i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
}
void prim(){
    fill(d, d+n+1, 1e9);
    reset(used);
    int socanh = -1;
    d[1] = 0;
    while (1){
        int u = 0;
        for (int i = 1; i <= n; i++)
            if (used[i] == 0 && d[i] < d[u]) u = i;
        if (u == 0) break;
        socanh++;
        used[u] = 1;
        ans += d[u];
        for (int i = 0; i < a[u].size(); i++){
            int v = a[u][i].F;
            int w = a[u][i].S;
            if (used[v]==0 && d[v] > w){
                d[v] = w;
                connect[v] = u;
            }
        }
    }
    if (socanh != n-1){
        cout << "-1";
        return;
    }
    cout << ans << endl;
    for (int i = 2; i <= n; i++)
        cout << i << " " << connect[i] << "\n";
}
