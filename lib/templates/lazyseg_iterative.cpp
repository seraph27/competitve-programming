const ll MX = 1e5+5;
ll n, a[MX], t[MX*3], mk[MX*3];

void build(ll l, ll r, ll p) {
    if(l == r) {
        t[p] = a[l];
        return;
    }
    ll m = l + ((r-l)>>1);
    build(l, m, p<<1), build(m+1, r, (p<<1)|1);
    t[p] = t[p<<1] + t[(p<<1)|1];
}

void push(ll tl, ll tr, ll p, ll m) {
    if(mk[p]) {
        t[p<<1] += mk[p]*(m-tl+1), t[(p<<1)|1] += mk[p]*(tr-m);
        mk[p<<1] += mk[p], mk[(p<<1)|1] += mk[p];
    }
    mk[p] = 0;
}

void update(ll l, ll r, ll tl, ll tr, ll p, ll c) {
    if(l<=tl && tr<=r) {
        t[p] += (tr-tl+1)*c, mk[p]+=c;
        return;
    }
    ll m = tl + ((tr-tl)>>1);
    push(tl, tr, p, m);
    if(l<=m) update(l, r, tl, m, p<<1, c);
    if(r>m) update(l, r, m+1, tr, (p<<1)|1, c);
    t[p] = t[p<<1] + t[(p<<1)|1];
}

ll getsum(ll l, ll r, ll tl, ll tr, ll p) {
    if(l<=tl && tr<=r) return t[p];
    ll sum = 0;
    ll m = tl + ((tr-tl)>>1);
    push(tl, tr, p, m);
    if(l<=m) sum+=getsum(l, r, tl, m, p<<1);
    if(r>m) sum+=getsum(l, r, m+1, tr, (p<<1)|1);
    return sum;
}