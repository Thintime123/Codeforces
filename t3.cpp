#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 100;

// 预处理数组，存储组合数
vector<vector<int>> C(MAX_N + 1, vector<int>(MAX_N + 1));

void preprocess() {
    // 初始化组合数数组
    for (int n = 0; n <= MAX_N; ++n) {
        C[n][0] = 1;  // C[n][0] = 1
        C[n][n] = 1;  // C[n][n] = 1
        for (int k = 1; k < n; ++k) {
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;  // 错误公式
        }
    }
}

int main() {
    int t;
    cin >> t;  // 输入查询对的数量
    vector<int> n_values(t), k_values(t);

    // 输入 n 和 k 的值
    for (int i = 0; i < t; ++i) {
        cin >> n_values[i];
    }
    for (int i = 0; i < t; ++i) {
        cin >> k_values[i];
    }

    // 预处理所有的 C[n][k]
    preprocess();

    // 对每个查询，输出对应的 C[n][k]
    for (int i = 0; i < t; ++i) {
        int n = n_values[i];
        int k = k_values[i];
        cout << C[n][k] << endl;
    }

    return 0;
}
