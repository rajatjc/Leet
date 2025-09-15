#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    ifstream input("input.txt");
    ofstream output("output.txt");

    int t;
    input >> t;

    while (t--) {
        int n;
        input >> n;
        vector<int> a(n);
        string s;

        for (int i = 0; i < n; i++) {
            input >> a[i];
        }

        input >> s;
        int q;
        input >> q;

        int xor0 = 0;
        int xor1 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                xor0 ^= a[i];
            } else {
                xor1 ^= a[i];
            }
        }

        while (q--) {
            int tp;
            input >> tp;

            if (tp == 1) {
                int l, r;
                input >> l >> r;

                for (int i = l - 1; i < r; i++) {
                    if (s[i] == '0') {
                        xor0 ^= a[i];
                        xor1 ^= a[i];
                        s[i] = '1';
                    } else {
                        xor0 ^= a[i];
                        xor1 ^= a[i];
                        s[i] = '0';
                    }
                }
            } else {
                int g;
                input >> g;
                if (g == 0) {
                    output << xor0 << " ";
                } else {
                    output << xor1 << " ";
                }
            }
        }

        output << endl;
    }

    input.close();
    output.close();

    return 0;
}
