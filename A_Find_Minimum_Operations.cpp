#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n, k;
    cin >> n >> k;
    int c = 0;
    while (n)
    {
        int t = log(n) / log(k);
        n -= pow(k, t);
        c++;
    }
    cout << c << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}