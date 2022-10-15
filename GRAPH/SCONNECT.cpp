int cnt = 0, top = 0, scc = 0;
int id[maxn], low[maxn], in[maxn];
vector<int> res[maxn];
int st[maxn];

void Tarjan(int u)
{
    id[u] = low[u] = ++cnt;
    st[++top] = u;
    for (int &v : a[u])
    {
        if (in[v]) continue;
        if (id[v]) low[u] = min(low[u], id[v]);
        else
        {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == id[u])
    {
        scc++;
        while (1)
        {
            int v = st[top--];
            res[scc].pb(v),
            in[v] = scc;
            if (v == u) break;
        }

    }
}
