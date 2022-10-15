void IJK()
{
    memset(kt, 0, sizeof(kt));
    memset(d, 60, sizeof(d));

    priority_queue < pair<int, int> > P;
	d[s] = 0;
    P.push(mp(-d[s], s));

    while (!P.empty())
    {
        // Tim dinh toi uu
        int u = P.top().S;
        int l = -P.top().F; // == d[u]
        P.pop();
        if (l > d[u]) continue;
        // Dung dinh u di toi uu
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].F;
            int w = a[u][i].S;
            if (d[v] > l + w)
            {
                d[v] = l + w;
                tr[v] = u;
                P.push(mp(-d[v],v ));
            }
        }
    }
}
