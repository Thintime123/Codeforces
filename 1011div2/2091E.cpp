#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e7 + 5;
vector<bool> is_prime;
vector<int> primes;

// 预处理所有质数
void sieve(int n) {
    is_prime.resize(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for(ll i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n;
    cin >> n;
    
    int ans = 0;
    // 枚举所有可能的a
    for(int a = 1; a < n; a++) {
        // 枚举所有可能的b
        for(int b = a + 1; b <= n; b++) {
            int g = gcd(a, b);
            // 计算F(a,b) = (a*b)/(g*g)
            ll F = (1LL * a * b) / (1LL * g * g);
            if(F <= N && is_prime[F]) {
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    // 预处理质数
    sieve(N);
    
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
