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

    string ans;

    fer(i, 0, s.size()){
    	int mx = 0, ind = -1;
    	fer(j, 0, 9){
    		if(i + j >= s.size()) break;
    		if(s[i + j] - '0' >= j)
    			if(mx < s[i + j] - '0' - j){
    				mx = s[i + j] - '0' - j, ind = i + j;
    			}
    	}
    	ferd(k, ind, i + 1) swap(s[k], s[k - 1]);
    	ans += '0' + mx;
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