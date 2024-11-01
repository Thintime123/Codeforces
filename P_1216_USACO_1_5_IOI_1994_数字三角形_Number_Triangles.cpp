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
const int N = 1010;

int dp[N][N];
int arr[N][N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start_time = clock();

    int n;
    cin >> n;
    fer(i, 1, n + 1)
        fer(j, 1, i + 1)
            cin >> arr[i][j];
    fer(i, 1, n + 1) dp[i][1] = arr[i][1], dp[i][i] = arr[i][i];

    fer(i, 3, n + 1){
        fer(j, 2, i){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }
    int ans = 0;
    fer(i, 1, n + 1){
        fer(j, 1, i + 1)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    fer(i, 1, n + 1)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;

#ifdef LOCAL
    cout << "\nTime : ";
    cout << (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms\n";
#endif
    return 0;
}