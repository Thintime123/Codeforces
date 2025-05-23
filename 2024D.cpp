#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // 测试用例数
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // 问题得分
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i]; // 参数 b_i
        }

        // dp[i]表示从问题i开始能获得的最大分数
        vector<long long> dp(n + 1, 0);

        // 逆序遍历
        for (int i = 0; i < n + 1; ++i) {
            // 跳过当前问题，跳到 b[i] 限制范围内继续比赛
            if (i + b[i] < n) {
                dp[i] = a[i] + dp[i + b[i] + 1];
            } else {
                dp[i] = a[i]; // 如果跳出问题范围，则只能获取当前分数
            }
        }

        // 输出从第一个问题出发的最大得分
        cout << dp[0] << "\n";
    }

    return 0;
}
