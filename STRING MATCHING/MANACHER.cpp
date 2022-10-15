int Manacher()
{
    n = s.length() * 2 - 1;

    string a(n, DUMMY);
    for (int i=0; i<n; i+=2) a[i] = s[i/2];

    int l = 0, r = -1, center, res = 0;
    for (int i=0, j=0; i<n; i++)
    {
        j = (i > r ? 0 : min(f[l+r-i], r-i)) + 1;
        while (i-j >= 0 && i+j < n && a[i+j] == a[i-j]) j++;
        f[i] = --j;
        if (i+j > r) l = i-j, r = i+j;

        int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
        if (len > res) res = len, center = i;
    }
    return res;
}

