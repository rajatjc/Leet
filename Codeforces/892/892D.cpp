#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Portal {
    int l, r, a, b;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Portal> portals(n);
        for (int i = 0; i < n; ++i) {
            cin >> portals[i].l >> portals[i].r >> portals[i].a >> portals[i].b;
        }

        sort(portals.begin(), portals.end(), [](const Portal &p1, const Portal &p2) {
            return p1.l < p2.l;
        });

        vector<int> max_positions(n);
        max_positions[0] = portals[0].a;
        for (int i = 1; i < n; ++i) {
            max_positions[i] = max(max_positions[i - 1], portals[i].a);
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; ++i) {
            int x;
            cin >> x;

            int left = 0, right = n - 1;
            int result = -1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (portals[mid].l <= x && max_positions[mid] >= x) {
                    result = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (result != -1) {
                cout << max(x, portals[result].b) << " ";
            } else {
                cout << x << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
