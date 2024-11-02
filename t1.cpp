#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    long long total_sum = (long long)n * (n + 1) / 2; // 计算1到n的总和
    long long sum_given = 0;

    for (int i = 0; i < n - 1; ++i) {
        int num;
        scanf("%d", &num);
        sum_given += num;
    }

    int missing_number = total_sum - sum_given;
    printf("%d\n", missing_number);

    return 0;
}
