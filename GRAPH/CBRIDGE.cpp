int n, m, par[maxn];
vector <int> a[maxn];
int num[maxn], low[maxn], cnt = 0;
vector <pii> res;

void DFS(int u)
{
    low[u] = num[u] = ++cnt;
    for (int &v : a[u]){
        if (v == par[u]) continue;
        if (par[v]) low[u] = min(low[u], num[v]);
        else{
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
			if (low[v] == num[v]) res.pb(mp(u,v));
        }
    }
}

int main()
{
    for (int i = 1; i <= n; i++)
        if (!par[i])
        {
            par[i] = -1;
            DFS(i);
        }
	cout << res.size() << '\n';
	for (pii x : res) cout << x.F << " " << x.S << '\n';
    return 0;
}
