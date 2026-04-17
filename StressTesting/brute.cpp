#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define pb push_back


void solve(){

    ll n,x; cin >> n >> x;
    ll sum = 0;
    for(ll i = 0; i < n; i++) sum += x;
    cout << sum << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ll tt; cin >> tt;
    // while(tt--)
      solve();

    return 0;
}
