#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 122;

// 预处理数组，存储组合数
vector<int> C(MAX_N + 1, 0);  // 使用一维数组存储组合数

void preprocess()
{
    // 初始化组合数数组
    C[0] = 1;  // C[0][0] = 1
    for (int n = 1; n <= MAX_N; ++n) {
        // 从后往前更新组合数
        for (int k = n; k > 0; --k) {
            C[k] = (C[k] + C[k - 1]) % MOD;  // 错误公式
        }
        C[0] = 1;  // C[n][0] = 1
    }
}

int main()
{
    int t;
    cin >> t; // 输入查询对的数量
    vector<int> n_values(t), k_values(t);

    // 输入 n 和 k 的值
    for (int i = 0; i < t; ++i)
    {
        cin >> n_values[i];
    }
    for (int i = 0; i < t; ++i)
    {
        cin >> k_values[i];
    }

    // 预处理所有的 C[n][k]
    preprocess();

    // 对每个查询，输出对应的 C[n][k]
    for (int i = 0; i < t; ++i)
    {
        int n = n_values[i];
        int k = k_values[i];
        cout << C[k] << endl; // C[n][k] 是 C[k] 的值
    }

    return 0;
}
