#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << char(61) << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
const int inf = 1e9;

vector<vector<int>> fac(N);

void init() {
    fer(i, 1, N) {
        for(int j = i; j < N; j += i) {
            fac[j].push_back(i);
        }
    }
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if(k == 1) {
        cout << (x == y ? 0 : -1) << '\n';
        return;
    }
    int d = gcd(x, y);
    x /= d, y /= d;
    
    auto bfs = [&](int n) -> int {
        int dist[n + 1];
        fill(dist, dist + n, inf);
        dist[n] = 0;

        queue<pii> q;
        q.push({n, 0}); // n转化为x时需要y步

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(dist[x] < y) continue;

            for(auto it = next(fac[x].rbegin()); it != fac[x].rend(); ++it) {
                if(x / *it > k) break;
                if(dist[*it] > y + 1) {
                    dist[*it] = y + 1;
                    q.push({*it, y + 1});
                }
            }
        }
        return dist[1];
    };
    int res = bfs(x) + bfs(y);
    cout << (res >= inf ? -1 : res) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    init();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}