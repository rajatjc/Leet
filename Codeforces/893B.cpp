#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> sellers(m + 1); // Adding one extra element for convenience
        sellers[0] = 1; // Start point
        for (int i = 1; i <= m; i++) {
            cin >> sellers[i];
        }

        int min_diff = d;
        int a1 = 1, b1 = 1;
        
        for (int i = 1; i < m; i++) {
            int diff = sellers[i + 1] - sellers[i];
            if (diff < min_diff) {
                min_diff = diff;
                a1 = i;
                b1 = i + 1;
            }
        }

        bool removed = false;
        if (!(sellers[a1] - sellers[a1 - 1] < d && sellers[a1 + 1] - sellers[a1] < d)) {
            sellers.erase(sellers.begin() + a1);
            removed = true;
        } else if (!(sellers[b1] - sellers[b1 - 1] < d && sellers[b1 + 1] - sellers[b1] < d) && !removed) {
            sellers.erase(sellers.begin() + b1);
        }

        cout << "Sellers array after removal: ";
        for (int i = 0; i < sellers.size(); i++) {
            cout << sellers[i] << " ";
        }
        cout << endl;

        // Calculate minimum candies eaten using the modified sellers array
        int min_candies = sellers.size();
        for (int i = 0; i < sellers.size() - 1; i++) {
            int diff = sellers[i + 1] - sellers[i];
            if (diff >= d) {
                min_candies++;
            }
        }

        cout << min_candies << " " << sellers.size() - 1 << endl;
    }

    return 0;
}
