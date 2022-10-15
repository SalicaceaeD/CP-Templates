//Tran Thuy Duong
//Fibonaci (1) 1 2 3 5 8 13 21
#include <bits/stdc++.h>
#define maxv 3
#define maxn 100005
#define maxc 1000000009
#define MOD 1000000007
#define task "MATRIX"
#define reset(x) memset(x, 0, sizeof x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
long long n;
struct matrix
{
    int val[maxv][maxv];
    matrix()
    {
        memset(val, 0, sizeof val);
    }
    matrix operator * (const matrix & x)
    {
        matrix res;
        for (int u=1; u<3; u++)
            for (int v=1; v<3; v++)
                for (int i=1; i<3; i++)
                    res.val[u][v] = ((long long) val[u][i] * x.val[i][v] + res.val[u][v]) % MOD;
        return res;
    }
} A, res;
matrix POWW(matrix A, long long b)
{
    matrix C;
    for (int i=0; i<3; i++) C.val[i][i] = 1;
    for (; b; b/=2, A = A * A)
        if (b%2) C = C * A;
    /* while (b>0)
    {
        if (b%2) C = C * A;
        A = A * A;
        b /= 2;
    } */
    return C;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);
	cin >> n;
	A.val[1][1] = A.val[1][2] = A.val[2][1] = 1;
	res = POWW(A,n);
	cout << res.val[1][1];
}
