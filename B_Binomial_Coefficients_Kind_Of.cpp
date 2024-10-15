#include <bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, n) for (int i = 0; i < n; ++i)
#define ferr(i, n) for (int i = 1; i <= n; ++i)

const int MOD = 1e9 + 7;   // 模数，一般取质数
const int MAXN = 10001; // 最大的n值，根据需求调整

std::vector<long long> fact(MAXN + 1), invFact(MAXN + 1);

long long power(long long a, long long b, int mod)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = result * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return result;
}

// 预处理阶乘和阶乘的逆元
void preprocessFactorials(int n, int mod)
{
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    invFact[n] = power(fact[n], mod - 2, mod); // 使用费马小定理计算逆元
    for (int i = n - 1; i >= 0; --i)
    {
        invFact[i] = invFact[i + 1] * (i + 1) % mod;
    }
}

// 计算组合数 C(n, k) % mod
long long comb(int n, int k, int mod)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    vector<int> N(t);
    vector<int> K(t);
    fer(i, t) cin >> N[i];
    fer(i, t) cin >> K[i];
    preprocessFactorials((*max_element(all(N))), MOD);
    fer(i, t)
    {
        if (K[i] == 1)
        {
            cout << 2 << endl;
            continue;
        }
        int ans = comb(N[i], K[i] - 1, MOD) + comb(N[i] - 1, K[i] - 1, MOD);
        cout << ans << endl;
    }
    return 0;
}