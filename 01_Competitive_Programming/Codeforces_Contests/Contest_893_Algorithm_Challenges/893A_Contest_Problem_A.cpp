#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Determine the winner based on the optimal strategy
        // If a > b, Anna will always have buttons left to press
        // If b >= a, Katie will press the common buttons first, and then press her exclusive buttons
        if (c % 2 == 0) {
            if (a > b) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        } else {
            if (b > a) {
               
                cout << "Second" << endl;
            } else {
                 cout << "First" << endl;
            }
        }
    }

    return 0;
}
