#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solve(string s, int k, int swaps) {
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        if (swaps == 0) {
            break;
        }
        
        int j = i + 1;
        while (j < n && j - i <= 2) {
            if (s[i] > s[j]) {
                swap(s[i], s[j]);
                swaps--;
            }
            j++;
        }
    }
    
    for (int i = 0; i < n; i += k) {
        int end = min(i + k, n);
        reverse(s.begin() + i, s.begin() + end);
    }
    
    return s;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, swaps;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        string result = solve(s, k, 10000);
        cout << result << endl;
    }
    
    return 0;
}
