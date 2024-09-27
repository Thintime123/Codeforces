#include <bits/stdc++.h>
using namespace std;

int canFormDecks(int x, vector<int>& cards, int k) {
    long long additional_cards_needed = 0;
    for (int card : cards) {
        if (card % x) {  // If not divisible, need to buy more cards
            additional_cards_needed += x - card % x;
        }
    }
    return additional_cards_needed <= k;
}

int binarySearch(vector<int>& cards, int k) {
    int left = 0;
    int right = *min_element(cards.begin(), cards.end());
    int result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFormDecks(mid, cards, k)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }
        cout << binarySearch(cards, k) << '\n';
    }
    return 0;
}