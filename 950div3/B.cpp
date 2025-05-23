#include<bits/stdc++.h>
#include <functional>
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
    int n, f, k;
    cin >> n >> f >> k;

   	std::vector<int> arr(n + 1);
   	fer(i, 1, n + 1) cin >> arr[i];
   	int ans = arr[f];

   	sort(arr.begin() + 1, arr.end(), greater<int>());

   	if(k == n) cout << "YES" << '\n';
   	else{
   		if(arr[k + 1] < ans) cout << "YES" << '\n';
   		else if(arr[k + 1] >= ans && arr[k] != ans) cout << "NO" << '\n';
   		else cout << "MAYBE" << '\n';
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