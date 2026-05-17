#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int tc;
    cin >> tc;

    while(tc-- > 0) {
        int n, x; cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];

        ll ans = 0;

        for(int i=29; i>=0; i--) {
            vector<int> onesbitset;
            for(int num: arr) {
                if(num & (1LL << i)) {
                    onesbitset.push_back(num);
                }
            }

            if(onesbitset.size() >= x) {
                ans += (1LL << i);
                arr = onesbitset;
            }
        }

        cout << ans << endl;
    }
}