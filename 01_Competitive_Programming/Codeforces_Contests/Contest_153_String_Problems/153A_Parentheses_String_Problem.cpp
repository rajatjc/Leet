#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;

        if (t.find("((") != string::npos) {
            {
                cout << "YES" << endl;
            for (int j = 0; j < t.length() ; ++j) {
                cout << "()";
            }
            cout << endl;
            }
        } else if (t.find("))") != string::npos) {
            {
                cout << "YES" << endl;
            for (int j = 0; j < t.length() ; ++j) {
                cout << "()";
            }
            cout << endl;
            }
        } else if (t.find(")(") != string::npos) {
            {
                cout << "YES" << endl;
            for (int j = 0; j < t.length() ; ++j) {
                cout << "(";
            }
            for (int j = 0; j < t.length() ; ++j) {
                cout << ")";
            }
            cout << endl;
            }
        } else if (t.find("()") != string::npos) {
            if (t.length() == 2) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            for (int j = 0; j < t.length() ; ++j) {
                cout << "(";
            }
            for (int j = 0; j < t.length() ; ++j) {
                cout << ")";
            }
            cout << endl;
            }
        }
    }

    return 0;
}
