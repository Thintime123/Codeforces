#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 函数：计算两个数的GCD
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 构建稀疏表
void buildSparseTable(const vector<int>& arr, vector<vector<int>>& sparse) {
    int n = arr.size();
    int maxLog = log2(n) + 1;

    for (int i = 0; i < n; ++i) {
        sparse[i][0] = arr[i];
    }
    
    for (int j = 1; j < maxLog; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            sparse[i][j] = gcd(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
        }
    }
}

// 查询稀疏表
int queryGCD(const vector<vector<int>>& sparse, int l, int r) {
    int len = r - l + 1;
    int log = log2(len);
    return gcd(sparse[l][log], sparse[r - (1 << log) + 1][log]);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (n > 1) {
            vector<int> d(n-1);
            for (int i = 0; i < n-1; ++i) {
                d[i] = abs(a[i] - a[i+1]);
            }
            
            // 构建稀疏表
            int maxLog = log2(n-1) + 1;
            vector<vector<int>> sparse(n-1, vector<int>(maxLog));
            buildSparseTable(d, sparse);
            
            // 处理查询
            while (q--) {
                int l, r;
                cin >> l >> r;
                if (l == r) {
                    cout << 0 << " ";
                } else {
                    // 查询 d[l-1..r-2] 的GCD
                    cout << queryGCD(sparse, l-1, r-2) << " ";
                }
            }
        } else {
            // 特殊情况：数组长度为1，所有查询结果为0
            while (q--) {
                int l, r;
                cin >> l >> r;
                cout << 0 << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
