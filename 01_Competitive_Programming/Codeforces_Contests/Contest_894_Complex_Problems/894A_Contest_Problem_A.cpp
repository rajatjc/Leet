#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isVikaHappy(const vector<string>& carpet, int n, int m) {
    for (int j = 0; j < m - 3; ++j) {
        for (int k = j + 1; k < m - 2; ++k) {
            for (int l = k + 1; l < m - 1; ++l) {
                for (int a = l + 1; a < m; ++a) {
                    bool found_v = false, found_i = false, found_k = false, found_a = false;
                    for (int i = 0; i < n; ++i) {
                        if (carpet[i][j] == 'v') found_v = true;
                        if (carpet[i][k] == 'i') found_i = true;
                        if (carpet[i][l] == 'k') found_k = true;
                        if (carpet[i][a] == 'a') found_a = true;
                    }
                    if (found_v && found_i && found_k && found_a) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }

        if (isVikaHappy(carpet, n, m)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
