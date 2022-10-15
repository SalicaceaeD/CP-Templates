void BFS()
{
    int q[maxn];
    memset(trace, 0, sizeof trace);
    trace[s] = -1;
    int top = 1, bot = 1;
    q[1] = s;
    while (bot<=top)
    {
        int u = q[bot++];
        for (int i=0; i<a[u].size(); i++)
        {
            int v = a[u][i];
            if (trace[v]==0)
            {
                trace[v] = u;
                q[++top] = v;
            }
        }
    }
}

