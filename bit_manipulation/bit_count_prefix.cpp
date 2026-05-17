#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

void compute_prefix(const vector<int>& arr) {
    int n = arr.size();

    dp.assign(n, vector<int>(31, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            dp[i][j] =
                ((arr[i] & (1LL << j)) ? 1 : 0) +
                (i > 0 ? dp[i - 1][j] : 0);
        }
    }
}