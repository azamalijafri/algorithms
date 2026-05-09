#include<bits/stdc++.h>
using namespace std;

int count_total_bits(int x) {
    int num = 1, len = 1, count = 0;

    while(num <= x) {
        int next_num = num * 2;
        
        if(next_num-1 <= x) {
            count += len*(next_num-num);
            num = next_num;
            len++;
        } else {
            count += len * (x-num);
            break;
        }
    }

    return count + 1;
}

int main() {
    cout << count_total_bits(5)
}