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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    int cnt = 0, ans = 0;
    fer(i, 0, n){
    	if(s[i] == '0') cnt++;
    	else{
    		cnt = 0;
    		continue;
    	}
    	if(cnt == m){
    		ans++;
    		fer(j, i, i + k){
    			s[j] = '1';
    			if(j >= n) break;
    		}
    		cnt = 0;
    	}
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