#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll sum_of_xor_pair(vector<int> arr) {
    ll res = 0;

    for(int bit = 0; bit < 31; bit++) {
        ll cnt[2] = {0, 0};

        for(int num : arr)
            cnt[(num >> bit) & 1]++;

        ll pair_count = (cnt[0] * cnt[1]) % MOD;
        ll contrib = (pair_count * (1LL << bit)) % MOD;

        res = (res + contrib) % MOD;
    }

    return res;
}

ll sum_of_xor_subset(vector<int> arr) {
    ll res = 0;
    int n = arr.size();

    ll subset_count = modpow(2, n - 1);

    for(int bit = 0; bit < 31; bit++) {
        bool ok = false;

        for(int x : arr)
            if(x & (1LL << bit)) {
                ok = true;
                break;
            }

        if(ok) {
            res = (res + subset_count * (1LL << bit)) % MOD;
        }
    }

    return res;
}

ll sum_of_and_pair(vector<int> arr) {
    ll res = 0;

    for(int bit = 0; bit < 31; bit++) {
        ll cnt1 = 0;

        for(int x : arr)
            cnt1 += ((x >> bit) & 1);

        ll pairs = (cnt1 * (cnt1 - 1) / 2) % MOD;

        res = (res + pairs * (1LL << bit)) % MOD;
    }

    return res;
}

ll sum_of_and_subset(vector<int> arr) {
    ll res = 0;

    for(int bit = 0; bit < 31; bit++) {
        ll cnt1 = 0;

        for(int x : arr)
            cnt1 += ((x >> bit) & 1);

        if(cnt1 > 0) {
            ll subsets = (modpow(2, cnt1) - 1 + MOD) % MOD;
            res = (res + subsets * (1LL << bit)) % MOD;
        }
    }

    return res;
}

int main() {
    int tc;
    cin >> tc;

    while(tc--) {
        int n; cin >> n;
        vector<int> arr(n);

        for(int i = 0; i < n; i++)
            cin >> arr[i];

        cout << sum_of_xor_pair(arr) << " "
             << sum_of_xor_subset(arr) << " "
             << sum_of_and_pair(arr) << " "
             << sum_of_and_subset(arr) << "\n";
    }
}