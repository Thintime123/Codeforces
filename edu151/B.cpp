#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define inf INT_MAX

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x2 -= x1, x3 -= x1;
    y2 -= y1, y3 -= y1;

    int ans = 0;
    // 都在轴上
    if((x2 == 0 || y2 == 0) && (x3 == 0 || y3 ==0)){
    	if(x2 * x3 > 0) // 同向轴
    		ans = min(abs(x2), abs(x3));
    	else if(y2 * y3 > 0)	// 同向轴
    		ans = min(abs(y2), abs(y3));
    	else ans = 0;
    }
    else if(x2 != 0 && x3 != 0 && y2 != 0 && y3 != 0){
    	// 都在象限上
    	if(x2 * x3 < 0 && y2 * y3 < 0) // 对角
    		ans = 0;
    	else if(x2 * x3 > 0 && y2 * y3 > 0) // 同象限
    		ans = min(abs(x2), abs(x3)) + min(abs(y2), abs(y3));
    	else if(x2 * x3 > 0)
    		ans = min(abs(x2), abs(x3));
    	else ans = min(abs(y2), abs(y3));
    }
    else{
    	// 象限 + 轴
    	if(x2 * x3 > 0) ans = min(abs(x2), abs(x3));
    	else if(y2 * y3 > 0) ans = min(abs(y2), abs(y3));
    	else ans = 0;
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