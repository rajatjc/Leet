#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> integers(N);
    for (int i = 0; i < N; ++i) {
        cin >> integers[i];
    }
    sort(integers.begin(),integers.end());

    for (int i = 1; i < N; ++i) {
        if (integers[i] - integers[i - 1] == 2) {
            cout << integers[i] - 1 << endl;
            break;
        }
    }

    return 0;
}
