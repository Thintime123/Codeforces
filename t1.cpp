#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

signed main()
{
    int n;
    scanf("%d", &n);
    bool *vis = new bool[n];
    fer(i, 1, n){
        int a;
        scanf("%d", &a);
        vis[a - 1] = true;
    }
    fer(i, 1, n + 1){
        if(vis[i - 1] == false){
            printf("%d", i);
            break;
        }
    }
    return 0;
}