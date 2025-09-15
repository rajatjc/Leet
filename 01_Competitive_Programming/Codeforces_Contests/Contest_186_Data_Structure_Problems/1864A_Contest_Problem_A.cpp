#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;

        vector<int> a(n);

        // Calculate the initial difference between consecutive elements
        a[n - 1] = y;
        int g=1;
        for (int i = n - 2; i >= 1; i--) {
            a[i] = a[i + 1] - g;
            g++;
        }
        a[0] = x;

        // Check if the array is strictly increasing
        bool isIncreasing = true;
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1]) {
                isIncreasing = false;
                break;
            }
        }

        // Check if the array b is strictly decreasing
        bool isDecreasing = true;
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; i++) {
            b[i] = a[i + 1] - a[i];
        }
        for (int i = 1; i < n - 1; i++) {
            if (b[i] >= b[i - 1]) {
                isDecreasing = false;
                break;
            }
        }

        // Output the array if both conditions are met, otherwise output -1
        if (isIncreasing && isDecreasing) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
        } else {
            cout << -1;
        }
        cout << endl;
    }

    return 0;
}
