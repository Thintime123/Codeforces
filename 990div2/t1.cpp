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

void dfs(int u, vector<vector<pii>>adjlist, vector<bool>&vis){
	if(vis[u]) return;
	vis[u] = true;
	for(auto [v, w] : adjlist[u]){
		if(!vis[v])
			dfs(v, adjlist, vis);
	}
}

int prim(vector<vector<pii>>adjlist, int start, int n){
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	vector<bool>vis(n + 1);

	pq.push({0, 1}); // w, v
	int mstw = 0, cnt = 0;

	while(!pq.empty() && cnt < n){
		auto [w, u] = pq.top();
		pq.pop();

		if(vis[u]) continue;
		vis[u] = true;
		mstw += w, cnt++;

		for(auto [v, w] : adjlist[u]){
			if(!vis[v])
				pq.push({w, v});
		}
	}
	return mstw;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>>adjlist(n + 1);

    fer(i, 0, m){
    	int u, v, w;
    	cin >> u >> v >> w;
    	adjlist[u].push_back({v, w});
    	adjlist[v].push_back({u, w});
    }

    vector<bool>vis(n + 1);
    dfs(1, adjlist, vis);
    fer(i, 1, n + 1)
    	if(!vis[i]){
    		cout << "orz" << '\n';
    		return 0;
    	}
    int mstw = prim(adjlist, 1, n);
    cout << mstw << '\n';
    return 0;
}