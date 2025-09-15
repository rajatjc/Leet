#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        int water_needed = ceil(max(a, b) - (a + b) / 2.0);
        int moves = ceil(water_needed / static_cast<double>(c));
        
        cout << moves << endl;
    }
    
    return 0;
}
