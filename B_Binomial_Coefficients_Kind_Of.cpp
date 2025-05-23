#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, n) for (int i = 0; i < n; ++i)
#define ferr(i, n) for (int i = 1; i <= n; ++i)

const int MOD = 1e9 + 7;
const int MAX_N = 2e5 + 2;

ll fpow(ll a, ll b, int p)
{
    ll ans = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> N(n), K(n);
    fer(i, n) cin >> N[i];
    fer(i, n) cin >> K[i];

    fer(i, n)
    {
        if (K[i] == 0 || K[i] == N[i])
        {
            cout << 1 << endl;
            continue;
        }
        cout << fpow(2, K[i], MOD) << endl;
    }
    
    return 0;
}