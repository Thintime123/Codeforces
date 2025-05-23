#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define inf INT_MAX

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size(), m = b.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1000)); 
        
        dp[0][0] = 0; 
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i + j == 0) continue; 
                
                int current_char = i + j - 1;
                
                if (i > 0) 
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + (a[i-1] != c[current_char]));
                
                
                if (j > 0) 
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + (b[j-1] != c[current_char]));
                
            }
        }
        
        cout << dp[n][m] << endl;
    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}