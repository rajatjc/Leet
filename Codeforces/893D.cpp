#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> prefix_zeros(n + 1, 0);
        vector<int> prefix_ones(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            prefix_zeros[i] = prefix_zeros[i - 1] + (s[i - 1] == '0');
            prefix_ones[i] = prefix_ones[i - 1] + (s[i - 1] == '1');
        }

        for (int a = 1; a <= n; ++a) {
            int max_beauty = 0;
            for (int i = 0; i <= k && i <= a; ++i) {
                int beauty = prefix_ones[i] + prefix_zeros[n] - prefix_zeros[n - (a - i)];
                max_beauty = max(max_beauty, beauty);
            }
            cout << max_beauty << " ";
        }

        cout << endl;
    }

    return 0;
}
