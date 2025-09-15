    #include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumSum(int totalNumbers, int maxIterations) {
      int counter = 0;

        int adjustedMaxIterations = ceil(static_cast<double>(maxIterations) / 2 + 1);

        if (maxIterations % 2 == 1) {
            adjustedMaxIterations--;
        }

        if (totalNumbers < adjustedMaxIterations || maxIterations == 1 || maxIterations == 2) {
            return totalNumbers * (totalNumbers + 1) / 2;
        }

        for (int i = adjustedMaxIterations; i < maxIterations; i++) {
            counter += i;
        }

        int difference = maxIterations - adjustedMaxIterations;
        int adjustedTotalNumbers = difference + totalNumbers;

        int result = adjustedTotalNumbers * (adjustedTotalNumbers + 1) / 2 - counter;

        return result;
    }
};

int main() {
    Solution solution;
    int n = 2;
    int k = 3;
    cout << solution.minimumSum(n, k) << endl;  // Example usage
    return 0;
}
