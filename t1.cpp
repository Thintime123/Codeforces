#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << '=' << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    function<void(int, int)> dfs = [&](int u, int p) {
        fa[0][u] = p;
        depth[u] = p ? depth[p] + 1 : 0;
    
        for(int v : adjlist[u]) {
            if(v != p) {
                dfs(v, u);
            }
        }
    };
    
    auto init_lca = [&]() -> void {
        dfs(1, 0);
    
        fer(k, 1, max_k) {
            fer(i, 1, n + 1) {
                int mid = fa[k - 1][i];
                fa[k][i] = mid ? fa[k - 1][mid] : 0;
            }
        }
    };
    
    auto lca = [&](int u, int v) -> int {
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
    
        fer(k, 0, max_k) {
            if(diff & (1 << k)) {
                u = fa[k][u];
            }
        }
        if(u == v) return u;
    
        ferd(k, max_k, 0) {
            if(fa[k][u] && fa[k][u] != fa[k][v]) {
                u = fa[k][u];
                v = fa[k][v];
            }
        }
        return fa[0][u];
    };

    return 0;
}