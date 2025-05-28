#include <iostream>
#include <utility>
using namespace std;

pair<int, int> d_to_xy(int n, int d) {
    int x = 0, y = 0;
    for (int i = n-1; i >= 0; --i) {
        int quadrant = (d - 1) >> (2 * i);
        int size = 1 << i;
        
        if (quadrant == 0) { // 左上
            // 不需要调整
        } else if (quadrant == 1) { // 右下
            x += size;
            y += size;
        } else if (quadrant == 2) { // 左下
            x += size;
        } else { // 右上
            y += size;
        }
        
        d -= quadrant * (1 << (2 * i));
    }
    
    // 处理最后的2x2块
    if (d == 1) {
        // 左上
    } else if (d == 2) {
        y += 1;
    } else if (d == 3) {
        x += 1;
    } else {
        x += 1;
        y += 1;
    }
    
    return {x + 1, y + 1}; // 转换为1-based索引
}

int xy_to_d(int n, int x, int y) {
    x--; y--; // 转换为0-based
    int d = 0;
    for (int i = n-1; i >= 0; --i) {
        int size = 1 << i;
        if (x < size && y < size) { // 左上
            // 不加
        } else if (x >= size && y >= size) { // 右下
            d += 1 * (1 << (2 * i));
            x -= size;
            y -= size;
        } else if (x >= size) { // 左下
            d += 2 * (1 << (2 * i));
            x -= size;
        } else { // 右上
            d += 3 * (1 << (2 * i));
            y -= size;
        }
    }
    
    // 处理最后的2x2块
    if (x == 0 && y == 0) return d + 1;
    if (x == 0 && y == 1) return d + 2;
    if (x == 1 && y == 0) return d + 3;
    return d + 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        while (q--) {
            string type;
            cin >> type;
            if (type == "->") {
                int x, y;
                cin >> x >> y;
                cout << xy_to_d(n, x, y) << "\n";
            } else {
                int d;
                cin >> d;
                auto [x, y] = d_to_xy(n, d);
                cout << x << " " << y << "\n";
            }
        }
    }
    
    return 0;
}