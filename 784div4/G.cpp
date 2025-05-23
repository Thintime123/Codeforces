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
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    fer(i, 0, n) cin >> arr[i];

    fer(col, 0, m){
    	int row = n - 1, cnt = 0;
    	while(row >= 0){
	    	while(row >= 0 && arr[row][col] == '.') cnt++, row--;
	    	if(row >= 0 && arr[row][col] == '*') swap(arr[row][col], arr[row + cnt][col]), row--;
	    	else cnt = 0, row--;
		}
    }
    for(auto c : arr) cout << c << '\n';
    cout << '\n';
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