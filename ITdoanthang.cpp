struct line {ll a, b;} it[4*maxn];
ll Get(line d, int x){
    return d.a * x + d.b;
}
void Update(int node, int l, int r, int u, int v, line val){
    if(u > r || v < l) return;
    int mid = (l + r) >> 1;
    if(l >= u && r <= v){
        if(Get(it[node], l) >= Get(val, l) && Get(it[node], r) >= Get(val, r)) return;
        if(Get(it[node], l) <= Get(val, l) && Get(it[node], r) <= Get(val, r)){
            it[node] = val;
            return;
        }
        if(Get(it[node], l) >= Get(val, l) && Get(it[node], mid) >= Get(val, mid)){
            Update(node*2+1, mid+1, r, u, v, val);
            return;
        }
        if(Get(it[node], l) <= Get(val, l) && Get(it[node], mid) <= Get(val, mid)){
            Update(node*2+1, mid+1, r, u, v, it[node]);
            it[node] = val;
            return;
        }
        if(Get(it[node], mid+1) >= Get(val, mid+1) && Get(it[node], r) >= Get(val, r)){
            Update(node*2, l, mid, u, v, val);
            return;
        }
        if(Get(it[node], mid+1) <= Get(val, mid+1) && Get(it[node], r) <= Get(val, r)){
            Update(node*2, l, mid, u, v, it[node]);
            it[node] = val;
            return;
        }
    }
    Update(node*2, l, mid, u, v, val);
    Update(node*2+1, mid+1, r, u, v, val);
}
ll Query(int node, int l, int r, int u){
    if (u < l || r < u) return -MM;
    ll res = Get(it[node], u);
    if (l == r) return res;
    int mid = (l + r) >> 1;
    res = max(res, Query(node*2, l, mid, u));
    res = max(res, Query(node*2+1, mid+1, r, u));
    return res;
}