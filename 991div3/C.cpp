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
    string n;
    cin >> n;
    ll s = 0;
    fer(i, 0, n.size()) s += n[i] - '0';

    int c1 = 0, c2 = 0;
    for(auto c:n){
    	if(c == '2') c1++;
    	else if(c == '3') c2++;
    }//cout << c1 << ' ' << c2 << ' ' << s % 9 << '\n';
    if(s % 9 == 0){cout << "YES" << '\n';return;}
    fer(i, 0, c1 + 1){
    	s += (i != 0 ? 2 : 0);
    	fer(j, 0, c2 + 1){
    		if((s + 6 * j) % 9 == 0){cout << "YES" << '\n';return;}
    	}
    }

    cout << "NO" << '\n';
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