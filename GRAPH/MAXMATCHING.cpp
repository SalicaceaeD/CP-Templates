int n, m, res = 0, cur;
vector <int> ke[maxn];
int MatchX[maxn], Used[maxn];

bool DFS(int u){
    if (Used[u] == cur) return 0;
    Used[u] = cur;
    for (int v : ke[u])
        if (MatchX[v] == 0|| DFS(MatchX[v])){
            MatchX[v] = u;
            return 1;
        }
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    int u, v;
    while (cin >> u >> v) ke[u].PB(v);
    for (cur = 1; cur <= m; cur++)
        res += DFS(cur);
    cout << res << endl;
    for (int i = 1; i <= n; i++) cout << MatchX[i] << " ";
    return 0;
}

