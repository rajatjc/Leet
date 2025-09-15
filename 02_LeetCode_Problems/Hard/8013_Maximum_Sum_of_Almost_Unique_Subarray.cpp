#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
 int numberOfBeautifulIntegers(int low, int high, int k) {
        auto countBeautiful = [&](long long num) { // Change to long long here
            int evenCount = 0, oddCount = 0;
            while (num > 0) {
                int digit = num % 10;
                if (digit % 2 == 0) {
                    evenCount++;
                } else {
                    oddCount++;
                }
                num /= 10;
            }
            return evenCount == oddCount;
        };

        long long dp[21][21] = {}; // Change to long long here

        dp[0][0] = 1; // Base case

        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int x = 0; x < k; ++x) {
                    if (dp[i][j] == 0) // Skip if the value is 0
                        continue;
                    dp[i + 1][j + 1] += dp[i][j];
                    dp[i][(j + k - i) % k] += dp[i][j];
                }
            }
        }

        int beautifulCount = 0;
        for (long long num = low; num <= high; ++num) { // Change to long long here
            if (num % k == 0 && countBeautiful(num)) {
                beautifulCount++;
            }
        }

        return beautifulCount;
    }
};

int main() {
    int low, high, k;
    cin >> low >> high >> k;
    
    Solution sol;
    int beautifulCount = sol.numberOfBeautifulIntegers(low, high, k);
    
    cout << "Number of beautiful integers in the range: " << beautifulCount << endl;
    
    return 0;
}
