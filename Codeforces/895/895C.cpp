#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        if (l <= 3 && r <= 3) {
            cout << "-1\n"; // Both l and r are less than 4, so no valid pair exists.
        } else if (l != r) {
            if (r % 2 == 0) {
                cout << r/2 << " " << r/2 << endl; // Choose an even number between l and r.
            } else {
                cout << (r-1)/2 << " " << (r-1)/2 << endl; // Choose l and l+1 (both are even).
            }
        } else {
            if (l % 2 == 0) {
                cout << l/2 << " " << l/2 << endl; // Choose an even number between l and r.
            } else {
                if (isPrime(l)) {
                    cout << "-1\n";
                } else {
                    int a = l/2;
                    int b = 1 + l/2;
                    while (gcd(a, b) == 1) {
                        a--;
                        b++;
                    }
                    cout << a << " " << b << endl;
                }
            }
        }
    }

    return 0;
}
