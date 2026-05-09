#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll pow_of_2(int exp) {
    return (1LL << exp);
}

ll count_one_bits(int x) {
    ll sum = 0;

    for (int i = 0; i < 32; i++) {
        ll total = x + 1;

        ll full_window_count = (total / pow_of_2(i + 1)) * pow_of_2(i);

        ll rem = total % pow_of_2(i + 1);

        ll left_over_count = max(0LL, rem - pow_of_2(i));

        sum += full_window_count + left_over_count;
    }

    return sum;
}

int main() {
    int num = 5;
    cout << count_one_bits(num);
}