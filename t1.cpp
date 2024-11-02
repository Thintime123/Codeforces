#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

signed main()
{
    ll n;
    scanf("%lld", &n);
    ll s = 0;
    fer(i, 1, n)
    {
        ll a;
        scanf("%lld", &a);
        s += i - a;
    }
    s += n;
    printf("%lld", s);
    return 0;
}