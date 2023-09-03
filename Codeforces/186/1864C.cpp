#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> reduce_to_one(int x) {
    vector<int> operations;

    while (x > 1) {
        bool divisor_found = false;

        for (int d = 2; d * d <= x; ++d) {
            if (x % d == 0 && count(operations.begin(), operations.end(), d) < 2) {
                operations.push_back(d);
                x -= d;
                divisor_found = true;
                break;
            }
        }

        if (!divisor_found) {
            if (count(operations.begin(), operations.end(), 1) < 2) {
                operations.push_back(1);
                x -= 1;
            } else {
                int smallest_divisor = x;
                for (int d = 2; d <= x; ++d) {
                    if (count(operations.begin(), operations.end(), d) < 2) {
                        smallest_divisor = d;
                        break;
                    }
                }
                operations.push_back(smallest_divisor);
                x -= smallest_divisor;
            }
        }
    }

    operations.push_back(1);
    return operations;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        vector<int> operations = reduce_to_one(x);

        // Output the number of operations
        cout << operations.size() << "\n";

        // Output the changes in x
        for (int j = 0; j < operations.size(); ++j) {
            if (j == 0) {
                cout << x << " ";
            } else {
                x -= operations[j];
                cout << x << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
