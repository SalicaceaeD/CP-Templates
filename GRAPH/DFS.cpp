void DFS(int u)
{
    for (int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        if (trace[v]==0)
        {
            trace[v] = u;
            DFS(v);
        }
    }
}
void ghikq()
{
    if (trace[t]==0) {cout << -1; return;}
    vector<int> kq;
    kq.pb(t);
    int x = t;
    while (x!=s) x = trace[x], kq.pb(x);
    cout << kq.size() << "\n";
    for (int i=kq.size()-1; i>=0; i--) cout << kq[i] << " ";
}

