#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << char(61) << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 1e7 + 10;
const int inf = 1e9;

vector<int> primes;
vector<bool> is_prime(N, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    fer(i, 2, N) {
        if(is_prime[i]) primes.push_back(i);
        for(auto p : primes) {
            if(i * p >= N) break;
            is_prime[i * p] = false;
            if(i % p == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    ll cnt = 0;

    fer(g, 1, n + 1) {
        for(auto p : primes) {
            if(g * p > n) break;
            cnt++;
        }
    }
    cout << cnt << '\n';
    //dbg(primes.size());
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    sieve();
    while(T--) solve();
    return 0;
}