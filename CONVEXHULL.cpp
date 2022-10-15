int n;
pair<pii,int> q[maxn], a[maxn];

pair<pii,int>  operator -(const pair<pii,int> & u, const pair<pii,int>& v){
    return {{u.F.F - v.F.F, u.F.S - v.F.S},u.S};
}
ll operator *(const pair<pii,int>& u, const pair<pii,int>& v){
    return u.F.F*v.F.S - u.F.S*v.F.F;
}

double dis(pair<pii,int> a, pair<pii,int> b){
    return sqrt((a.F.F - b.F.F) * (a.F.F - b.F.F) + (a.F.S - b.F.S) * (a.F.S - b.F.S));
}

ll ccw(pair<pii,int> a, pair<pii,int> b, pair<pii,int> c){
    return (b-a)*(c-b);
}

bool cmp(pair<pii,int> p, pair<pii,int> q){
    ll c = ccw(a[1],p,q);
    bool ok = 0;
    if(c > 0) return 1;
    else if(c == 0 && p < q) return 1;
    return 0;
}

int main()
{
    sort(a+1,a+n+1);
    int cnt = 0;
    q[++cnt] = a[1];
    sort(a+2,a+n+1,cmp);
    for(int i=2; i<=n; ++i){
        while(cnt > 1 && ccw(q[cnt-1],q[cnt],a[i]) <= 0) --cnt;
        q[++cnt] = a[i];
    }
    return 0;
}

struct pt { double x, y; };
bool cmp(pt u, pt v)
{ return (u.x < v.x) || (u.x == v.x && u.y < v.y); }

struct ConvexHull
{
    bool cw(pt u, pt v, pt t)
    { return u.x * (v.y - t.y) + v.x * (t.y - u.y) + t.x * (u.y - v.y) < 0;}
    bool ccw(pt u, pt v, pt t)
    { return u.x * (v.y - t.y) + v.x * (t.y - u.y) + t.x * (u.y - v.y) > 0;}

    vector<pt> c;
    ConvexHull (vector<pt> &a)
    {
        if (a.size() == 1) return;

        sort (a.begin(), a.end(), cmp);
        int m = a.size() - 1;
        pt p1 = a[0], p2 = a[m];
        vector<pt> up, down;
        up.pb(p1); down.pb(p2);

        for (int i=1; i<m; i++)
        {
            if (i == m-1 || cw(p1, a[i], p2))
            {
                while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i])) up.pop_back();
                up.pb(a[i]);
            }
            if (i == m-1 || ccw(p1, a[i], p2))
            {
                while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i])) down.pop_back();
                down.pb(a[i]);
            }
        }

        //a.clear();
        for (int i=0; i<up.size(); i++) c.pb(up[i]);
        for (int i=down.size()-2; i>0; i--) c.pb(down[i]);
        return;
    }
};
