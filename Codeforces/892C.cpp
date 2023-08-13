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

       
        int max_cost = 0;
        int localmax = 0;
        for (int i = 1; i <= n; ++i) {

         vector<int> permutation(n);
        for (int i = 0; i < n; ++i) {
            permutation[i] = i + 1;
        }

            reverse(permutation.end()-i, permutation.end()); 
            int cost = 0;
            localmax = 0; // Reset localmax for each i
            for (int j = 0; j < n; ++j) {
                cost += permutation[j] * (j + 1);
                localmax = max(localmax, permutation[j] * (j+1));
            }
            max_cost = max(max_cost, cost - localmax);



            
        }

        cout << max_cost << endl;
    }

    return 0;
}
