#include<bits/stdc++.h>
using namespace std;

string get_bits_representation(int num) {
    string bits = "";
    while(num) {
        bits += num % 2 == 0 ? "0" : "1";
        num /= 2;
    }

    if(bits == "") bits = "0";
    reverse(bits.begin(), bits.end());
    return bits;
}

int get_one_bit_index(int num, int x) {
    string bits = get_bits_representation(num);

    for(int i=0; i<bits.length(); i++) {
        if(bits[i] == '1') x--;
        if(x == 0) return i;
    }

    return 0;
}

int main() {
    cout << get_one_bit_index(5, 2);
}