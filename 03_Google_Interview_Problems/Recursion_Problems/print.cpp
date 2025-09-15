#include <bits/stdc++.h>
using namespace std;

void print() {
    cout << 1 << endl;
    print();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    print();
    return 0;
}
