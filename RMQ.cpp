#include <bits/stdc++.h>
#define maxn 100005
#define maxa 1000000009
using namespace std;
int n,a[maxn],f[18][maxn];
void rmq()
{
    //for (int i=1; i<=n; i++) f[0][i] = a[i];
    for (int i=1; i<=17; i++)
        for (int u=1; u<=n-(1<<i)+1; u++)
            f[i][u] = min(f[i-1][u],f[i-1][u+(1<<(i-1))]);
}
int getmin(int u, int v)
{
    int k = log2(v-u+1);
    return min(f[k][u],f[k][v-(1<<k)+1]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("RMQ.INP", "r", stdin);
    freopen("RMQ.OUT", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> f[0][i];
    rmq();
    int x,y;
    while (cin >> x >> y) cout << getmin(x,y) << "\n";
}
