pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return make_pair(1, 0);
 
    pair<ll, ll> qr = make_pair(a / b, a % b);
    pair<ll, ll> st = extended_gcd(b, qr.y);
 
    return make_pair(st.y, st.x - qr.x*st.y);
}