#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1e5 + 10;

// vector<vector<int>> C(MAX_N + 1, vector<int>(MAX_N + 1));

int preprocess(int n, int k)
{
    // for (int n = 0; n <= MAX_N; ++n)
    // {
    //     C[n][0] = 1;
    //     C[n][n] = 1;
    //     for (int k = 1; k < n; ++k)
    //     {
    //         C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;
    //     }
    // }
    vector<int> C(k+2);

    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(k, i); j > 0; j--)
        {
            C[j] = (C[j] + C[j - 1]) % MOD;
        }
    }
    return C[k];
}

int main()
{
    int t;
    cin >> t;
    vector<int> n_values(t), k_values(t);

    for (int i = 0; i < t; ++i)
    {
        cin >> n_values[i];
    }
    for (int i = 0; i < t; ++i)
    {
        cin >> k_values[i];
    }

    for (int i = 0; i < t; ++i)
    {
        int n = n_values[i];
        int k = k_values[i];
        cout<<preprocess(n,k)<<endl;
    }

    return 0;
}
