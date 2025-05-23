#include <algorithm>
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
    string s;
    cin >> n >> s;

    //string ans;
    // ferd(i, n - 1, 0){
    // 	if(s[i] != 'a' && s[i] != 'e') ans += s[i];
    // 	else{
    // 		ans = ans + s[i] + s[i - 1];
    // 		if(i != 1) ans += '.';
    // 		i --;
    // 	}
    // }
    // reverse(all(ans));

    vector<string>ans;
    ferd(i, n - 1, 0){
        if(s[i] == 'a' || s[i] == 'e')
            ans.push_back(s.substr(i - 1, 2)), i -= 1;
        else ans.push_back(s.substr(i - 2, 3)), i -= 2;
    }
    reverse(all(ans));
    fer(i, 0, ans.size() - 1)
        cout << ans[i] << '.';
    cout << ans.back() << '\n';
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