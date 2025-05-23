#include<bits/stdc++.h>
#include <vector>

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
    int n;
    cin >> n;
    vector<int>arr(n);

    bool ok = true;
    fer(i, 0, n) cin >> arr[i];

    for(int i = 0; i + 2 < n; i += 2){
    	if((arr[i] & 1) != (arr[i + 2] & 1)){
    		ok = false;
    		break;
    	}
    }
    if(!ok){cout << "NO" << '\n';return;}

    for(int i = 1; i + 2 < n; i += 2){
    	if((arr[i] & 1) != (arr[i + 2] & 1)){
    		ok = false;
    		break;
    	}
    }
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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