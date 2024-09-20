#include <vector>
#include <bits/stdc++.h>

int rec(int index, const std::vector<int>& arr) {
    if (index >= arr.size()) {
        return 0;
    }

    // Include the current element and move to the index+2
    int includeCurrent = arr[index] + rec(index + 2, arr);

    // Exclude the current element and move to the index+1
    int excludeCurrent = rec(index + 1, arr);

    // Return the maximum of including or excluding the current element
    return std::max(includeCurrent, excludeCurrent);
}

int main() {
    std::vector<int> arr = {2,1,4,9}; // Example array
    int maxSum = rec(0, arr);
    std::cout << "Maximum sum: " << maxSum << std::endl;
    return 0;
}
