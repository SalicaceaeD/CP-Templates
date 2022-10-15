
vector<int> z;

vector<int> z_function () {
    vector<int> z (n);
	int l = 0, r = 0;
    for (int k=1; k<n; ++k) {
        if (k <= r)
            z[k] = min (r-k+1, z[k-l]);
        while (k+z[k] < n && s[z[k]] == s[k+z[k]]) ++z[k];
        //MAX(zmax, z[i]);
        if (k+z[k]-1 > r)
            l = k,  r = k+z[k]-1;
    }
    return z;
}
