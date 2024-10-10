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
const int N = 2e5 + 2;

//int T[N];

int C(int n, int m)
{
    double ans = 1;
    int j = 1;
    for (int i = m + 1; i <= n; i++)
    {
        ans *= (i * 1.0 / j);
        j++;
    }
    for (int i = j; i <= n - m; i++)
        ans /= i;
    return (int)ans;
}
void solve()
{
    //memset(T,0,sizeof T);
    vector<int>T(N);
    int n, k, q;
    cin >> n >> k >> q;
    fer(i, n) cin >> T[i];

    int ans = 0;
    fer(i, n)
    {
        if (T[i] <= q)
        {
            int j = i + 1;
            int c = 1;
            for (; j < n; j++)
            {
                if(T[j]<=q) c++;
                else{
                    i=j;
                    break;
                }
            }
            if (c >= k)
            {
                ans += (c - k + 2) * (c - k + 1) / 2;
            }
        }
    }
    cout << ans << endl;
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