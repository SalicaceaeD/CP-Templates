int n, m, cnt = 0;
string s;
int num[maxn], child[maxn][26];

void add(string s)
{
    int node = 0;
    for (int i=0; i<s.length(); i++)
    {
        int k = s[i] - 'a';
        if (child[node][k]==0) child[node][k] = ++cnt;
        node = child[node][k];
        num[node]++;
    }
}
int get(string s)
{
    int node = 0;
    for (int i=0; i<s.length(); i++)
    {
        int k = s[i] - 'a';
        if (child[node][k]==0) return 0;
        node = child[node][k];
    }
    return num[node];
}

