int n,m,ans;
int root[maxn];
struct data {int u,v,w;} a[maxn];
vector <data> kq;
bool comp(data x, data y)
{
    return x.w < y.w;
}
int get_root(int u){
    return (root[u] ? root[u]=get_root(root[u]) : u);
}
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
}
void kruskal()
{
    sort(a+1, a+m+1, comp);
    reset(root);
    ans = 0;
    for (int i=1; i<=m; i++)
    {
        int p = get_root(a[i].u);
        int q = get_root(a[i].v);
        if (p==q) continue;
        root[p] = q;
        ans += a[i].w;
        kq.pb(a[i]);
    }
}
