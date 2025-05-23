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
    string s;
    cin >> s;
    bool f = false;

    int ans = 0;
    fer(i, 0, s.size() - 1){
    	if(s[i] == '1' && s[i + 1] == '0') ans++;
    	if(s[i] == '0' && s[i + 1] == '1'){
    		if(!f) f = true;
    		else ans++;
    	}
    }
    cout << ans + 1 << '\n';
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