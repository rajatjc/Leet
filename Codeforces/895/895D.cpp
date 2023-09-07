#include <bits/stdc++.h>

using namespace std;

long long sum_of_first_n(long long n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        long long a = n / x;
        long long b = n / y;
        long long lcm_xy = (x * y) / __gcd(x, y);
        long long c = n / lcm_xy;

        long long sum_max = a - c;
        long long sum_min = b - c;

        long long answer = sum_of_first_n(n) - sum_of_first_n(n - sum_max) - sum_of_first_n(sum_min);

        cout << answer << endl;
    }

    return 0;
}
