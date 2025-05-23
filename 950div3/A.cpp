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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<char, int> mp;

    for(auto c:s) mp[c]++;
    int ans = 0;
	
	fer(i, 0, 7){
		char c = char('A' + i);
		if(mp[c] < m) ans += (m - mp[c]);
	}
	cout << ans << '\n';

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