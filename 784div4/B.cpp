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
    map<int, int>mp;

    int n;
    cin >> n;
    fer(i, 0, n){
    	int a;
    	cin >> a;
    	mp[a]++;
    }
    for(auto it : mp){
    	if(it.second >= 3){
    		cout << it.first << '\n';
    		return;
    	}
    }
    cout << -1 << '\n';
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