#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

ll fpow(ll a, ll b, ll p){
    a %= p;
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 5;
    a=a*a%2;
    cout << a << endl;

    return 0;
}