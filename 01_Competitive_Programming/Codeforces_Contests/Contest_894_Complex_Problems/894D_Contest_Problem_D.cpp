#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        n++;
        long long k = ceil((-1 + sqrt(1 + 8 * n)) / 2);
        long long ans=k+ (n-1-k*(k-1)/2);
        cout << ans << endl;
    }

    return 0;
}
