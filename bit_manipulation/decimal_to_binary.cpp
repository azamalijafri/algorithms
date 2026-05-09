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

int main() {
    cout << get_bits_representation(5);
}