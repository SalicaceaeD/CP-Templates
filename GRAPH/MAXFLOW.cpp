int n, m, s, t;
int c[maxn][maxn], f[maxn][maxn], tr[maxn];
int maxFlow = 0;
vector<int> a[maxn];

void input()
{
    reset(c); reset(f);
    for (int u, v, i=1; i<=m; i++)
    {
        cin >> u >> v;
        cin >> c[u][v];
        a[u].pb(v); a[v].pb(u);
    }
}

void BFS(int u)
{
    int q[maxn];
    int top = 0, bot = 1;
    q[++top] = s;
    while (bot <= top)
    {
        int u = q[bot++];
        for (int v : a[u])
            if (tr[v] == 0 && c[u][v] > f[u][v])
            {
                tr[v] = u;
                q[++top] = v;
            }
    }
}

bool find_path()
{
    reset(tr);
    tr[s] = -1;
    BFS(s);
    return (tr[t]);
}

void incFlow()
{
    int u = t;
    int delta = MOD;
    while (u != s)
    {
        int v = tr[u];
        delta = min(delta, c[v][u] - f[v][u]);
        u = v;
    }
    u = t;
    while (u != s)
    {
        int v = tr[u];
        f[u][v] -= delta;
        f[v][u] += delta;
        u = v;
    }
    maxFlow += delta;
}

int main()
{
    while (find_path())
        incFlow();
    cout << maxFlow;
	return 0;
}
