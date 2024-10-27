#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i > n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> sum(n + 1);
    fer(i, 1, n + 1){
        scanf("%lld", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
    string s;
    cin >> s;
    s = " " + s;

    int ans = 0;
    int end = n;
    fer(i, 1, n + 1)
    {
        if (s[i] == 'R')
            continue;

        ferd(j, end, i)
        {
            if (s[j] == 'L')
                continue;
            ans += sum[j] - sum[i - 1];
            end = j - 1;
            break;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}