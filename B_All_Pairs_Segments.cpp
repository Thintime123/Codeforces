#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

int arr[N];
int p[N];
// int cnt[N];
vector<pair<int, int>> v;

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int c = n;
    // 每一个端点
    for (int i = 0; i < n; ++i)
    {
        p[i] = c * i + (c - 1);
        c--;
    }
    // 每一段内的
    c = n - 1;
    for (int i = 1; i < n; i++)
    {
        int cc = (n - i) * i;   // 段数
        // cnt[cc]=arr[i]-arr[i-1]-1;
        v.push_back(make_pair(cc, arr[i] - arr[i - 1] - 1));
    }
    while (q--)
    {
        int k;
        cin >> k;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == k)
                ans++;
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first == k)
                ans += v[i].second;
        }
        cout << ans << ' ';
    }
    cout << endl;
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