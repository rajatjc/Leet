#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> first;
        vector<int> second; // Fixed typo here
        
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            
            vector<int> a(m);
            for (int j = 0; j < m; j++) {
                cin >> a[j];
            }
            
            // Find the minimum and second minimum value in the array
            sort(a.begin(), a.end()); // Fixed typo here
            first.push_back(a[0]); // Fixed typo here
            second.push_back(a[1]); // Fixed typo here
        }
        
        sort(first.begin(), first.end()); // Fixed typo here
        sort(second.begin(), second.end()); // Fixed typo here

        long long beauty = 0;
        for (int i = 0; i < n; i++) {
            beauty += second[i]; // Calculate beauty
        }
        beauty+=first[0];
        beauty-=second[0];
        
        cout << beauty << endl;
    }
    
    return 0;
}
