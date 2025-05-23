#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void top_sort(vector<vector<int>>adjlist, vector<int>rd){
    int n = adjlist.size();
    
    vector<int>ans;
    queue<int>q;
    int cnt = 0;

    fer(i, 0, n)
        if(!rd[i]) q.push(i);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(auto c:adjlist[cur]){
            rd[c]--;
            if(!rd[c]) q.push(c);
        }
    }
}

void prim(vector<vector<pii>>&adjlist){
    int n = adjlist.size();
    vector<bool>vis(n);
    priority_queue<pii, vector<pii>, greater<pii>>pq;

    pq.push({0, 0});
    int sumw = 0, cnt = 0;

    while(!pq.empty() && cnt < n){
        auto [w, u] = pq.top();
        pq.pop();
        if(!vis[u]){
            vis[u] = true;
            sumw += w;
            cnt ++;

            for(auto &[v, w]:adjlist[u])
                if(!vis[v]) pq.push({w, v});
        }
    }
    cout << sumw << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start_time = clock();

    cout << 2;

#ifdef LOCAL
    cout << "\nTime : ";
    cout << (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms\n";
#endif
    return 0;
}