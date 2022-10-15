int n, m, par[maxn];
vector <int> a[maxn], res;
int index[maxn], low[maxn], cnt = 0;
void DFS(int u)
{
    low[u] = index[u] = ++cnt;
	int x = (par[u] != -1);
    for (int v : a[u])
    {
        if (v == par[u]) continue;
        if (par[v]) low[u] = min(low[u], index[v]);
        else
        {
            par[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
			x += (low[v] >= index[u]);
        }
    }
	if (x > 1) res.pb(u);
}

int main()
{
    for (int i = 1; i <= n; i++)
        if (!par[i])
        {
            par[i] = -1;
            DFS(i);
        }
    cout << res.size() << endl;
	sort(res.begin(), res.end());
	for (int u : res) cout << u << " ";
	return 0;
}
