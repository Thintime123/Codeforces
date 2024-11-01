#include <iostream>
#include <chrono>

// 假设要测试的函数
int someFunction() {
    int sum = 0;
    for (int i = 0; i < 10000; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    int result = someFunction();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Function took " << elapsed.count() << " milliseconds." << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}