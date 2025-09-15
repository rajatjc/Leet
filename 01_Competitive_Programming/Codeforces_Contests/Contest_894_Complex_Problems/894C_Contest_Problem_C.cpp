#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heights(n);
        map<int, int> heightCounts;

        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
            heightCounts[heights[i]]++;
        }

        vector<pair<int, int>> sortedCounts(heightCounts.begin(), heightCounts.end());
        sort(sortedCounts.begin(), sortedCounts.end());

        vector<int> b;
        int x = n;
        int j=0;
        for (int i = 0; i < heights.size(); ++i) {
            if (sortedCounts[j].first == i) {
                x -= sortedCounts[j].second;
                j++;
            }
            b.push_back(x);
        }

        bool isSymmetrical = true;
        for (int i = 0; i < n; ++i) {
            if (b[i] != heights[i]) {
                isSymmetrical = false;
                break;
            }
        }

        if (isSymmetrical) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
