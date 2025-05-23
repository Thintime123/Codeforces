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
    fer(i, 0, 3){
    	string s;
    	cin >> s;

    	bool vis[3] = {0, 0 ,0};
    	fer(i, 0, 3){
    		if(s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
    			vis[int(s[i] - 'A')] = true;
    	}
    	fer(i, 0, 3){
    		if(!vis[i]) cout << char('A' + i) << '\n';
    	}
    }
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