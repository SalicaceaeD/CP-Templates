void DFS(int u)
{
    for (int i=1; i<=17; ++i) p[i][u] = p[i-1][p[i-1][u]];
    for (int v : a[u]) if (v != p[0][u]) {
        p[v][0] = u;
        h[v] = h[u] + 1;
        DFS(v);
    }
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    for (int i=17; i>=0; --i)
        if ((delta >> i) & 1) u = p[u][i];
    if (u == v) return u;
    for (int i=17; i>=0; --i)
        if (p[u][i] != p[v][i])
            u = p[u][i],
            v = p[v][i];
    return p[u][0];
}

