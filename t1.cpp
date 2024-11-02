#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    int xor_total = 0;
    for (int i = 1; i <= n; ++i) {
        xor_total ^= i;  // 从1到n进行异或
    }

    int xor_given = 0;
    for (int i = 0; i < n - 1; ++i) {
        int num;
        scanf("%d", &num);
        xor_given ^= num;  // 将输入的数字异或
    }

    int missing_number = xor_total ^ xor_given;
    printf("%d\n", missing_number);

    return 0;
}
