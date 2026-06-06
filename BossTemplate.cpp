#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using bigll = __int128;
using vll = vector<ll>;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back


// MaxHeap and MinHeap
priority_queue<ll> maxHeap;
priority_queue<ll, vll, greater<ll>> minHeap;


// Merge sort Implementation using mg and mergesort
void mg(vll &v, ll left, ll mid, ll right){
    vll res; ll l = left; ll r = mid+1;
    while(l<=mid || r<=right){
        if(l>mid || (r<=right && v[l]>v[r])) res.pb(v[r++]);
        else if(r>right || (l<=mid && v[l]<=v[r])) res.pb(v[l++]);
    }
    for(ll i = 0; i < res.size(); i++) v[i+left] = res[i];
}
void mergesort(vll &v, ll left, ll right){
    if(left>=right) return;
    ll mid = (left+right)/2;
    mergesort(v,left,mid);
    mergesort(v,mid+1,right);
    mg(v,left,mid,right);
}


// Segment Tree Implementation
ll MAXN;
typedef struct {
    ll val;
} node;
vector<node> seg;
ll combine(ll a, ll b){
    return a+b;
}
void build(ll a[], ll v, ll l, ll r) {
    if(l==r) seg[v].val = a[l];
    else{
        ll mid = (l+r)/2;
        build(a, v*2, l, mid);
        build(a, v*2+1, mid+1, r);
        seg[v].val = combine(seg[v*2].val, seg[v*2+1].val);
    }
}
ll sum(ll v, ll l, ll r, ll L, ll R) {
    if(L>R) return 0;
    if(L==l && R==r) return seg[v].val;
    ll mid = (l+r)/2;
    return combine(sum(v*2, l, mid, L, min(R,mid)), sum(v*2+1, mid+1, r, max(L,mid+1), R));
}
void update(ll v, ll l, ll r, ll pos, ll new_val) {
    if(l==r) seg[v].val = new_val;
    else{
        ll mid = (l+r)/2;
        if(pos <= mid) update(v*2, l, mid, pos, new_val);
        else update(v*2+1, mid+1, r, pos, new_val);
        seg[v].val = combine(seg[v*2].val, seg[v*2+1].val);
    }
}

// Fenwick tree for sum with 1-indexing
vll fenwick;
ll fenwicksum(ll k) {
    ll s = 0;
    while (k >= 1) {
        s += fenwick[k];
        k -= k&-k;
    }
    return s;
}
void fenwickadd(ll k, ll x, ll n) {
    while (k <= n) {
        fenwick[k] += x;
        k += k&-k;
    }
}


// Modular inverse of a mod m
ll ModularInverse(ll a, ll m) {
    if(a<=1) return a;
    else return m-(m/a)*ModularInverse(m%a,m)%m;
}


// Generates Permutation
void permutation(vll v){
    do{
        for(auto i:v) cout << i << " ";
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
}


// Floor of Log base 2
ll log2floor(ll i) {
    return __builtin_clzll(1)-__builtin_clzll(i);
}


void solve(){

    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    MAXN = 1000000;
    seg.assign(4*MAXN,{0});
    vll v(n);


    // Sparse Table Implementation
    vector<vll> sparse(n,vll(log2floor(n)+1,0));
    for(ll i = 0; i < n; i++) sparse[i][0] = v[i];
    for(ll j = 1; j <= log2floor(n)+1; j++){
        for(ll i = 0; i+(1<<j) < n; i++){
            sparse[i][j] = sparse[i][j-1] | sparse[i+(1<<(j-1))][j-1];
        }
    }


    // Totient function using sieve
    vll phi(1000001);
    for(ll i = 0; i <= 1000000; i++) phi[i] = i;
    for(ll i = 2; i <= 1000000; i++){
        if(phi[i]==i){
            for(ll j = i; j <= 1000000; j+=i) phi[j] -= phi[j]/i;
        }
    }

    // ll tt; cin >> tt;
    // while(tt--)
        solve();
    
    return 0;
}
