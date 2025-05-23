#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i > n; --i)

const int MOD = 1e9 + 7;
const int N = 1e5 + 2;

vector<int> p;

bool is_ok(int n)
{
    if (n == 1)
        return true;
    bool f = true;
    while (n)
    {
        if (n % 10 > 1)
        {
            f = false;
            break;
        }
        n /= 10;
    }
    if (f)
        return true;
    return false;
}

void prework(vector<int> &p)
{
    fer(i, 10, N) if (is_ok(i)) p.push_back(i);
}

void solve()
{
    int n;
    cin >> n;
    bool ok = false;

    fer(i, 1, p.size()) // 注意开始下标
    {
        if (is_ok(n))
        {
            ok = true;
            break;
        }
        if (n % p[i] == 0)
        {
            n /= p[i];
            i--;
        }
    }
    if (ok)
        puts("YES");
    else
        puts("NO");
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    prework(p);
    while (T--)
    {
        solve();
    }

    return 0;
}