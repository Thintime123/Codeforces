#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &c : arr)
        cin >> c;
    vector<int> ap;
    ap.push_back(0);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
            ap.push_back(arr[i] - arr[i + 1]);
    }
    sort(all(ap));
    int ans = 0;
    int t=ap.size();
    for (int i = 1; i < ap.size(); i++)
    {
        ans += (t--) * (ap[i] - ap[i - 1]);
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