#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define pb push_back

int main(){

    srand(time(0));
    ll t = 1000;
    cout << t << '\n';
    for(ll i = 0; i < t; i++){
        ll n = rand()%100+1;
        ll x = rand()%1000+1;
        cout << n << " " << x << '\n';
    }    

    return 0;
}
