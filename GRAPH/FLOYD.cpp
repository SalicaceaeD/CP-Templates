void Floyd() {
    for (int u=1; u<=n; u++)
        for (int v=1; v<=n; v++)
            trace[u][v] = v;
    for (int k=1; k<=n; ++k)
        for (int u=1; u<=n; ++u)
            for (int v=1; v<=n; ++v)
                if (c[u][v] > c[u][k]+c[k][v]) {
                    c[u][v] = c[u][k]+c[k][v];
                    trace[u][v] = trace[u][k];
                }
}
void Trace(){
    //cout << c[s][t] << "\n";
    vector<int> kq;
    kq.push_back(s);
    while(s!=t){
        int k = trace[s][t];
        kq.push_back(k);
        s = k;
    }
    //cout << kq.size() << "\n";
    //for (int i=0; i<kq.size(); i++) cout << kq[i] << " ";
}
