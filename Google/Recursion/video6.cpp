#include <iostream>
#include <vector>

void generateSubsequences(const std::vector<int>& array, int index, std::vector<int>& currentSubsequence) {
    // Base case: if index is at the end of the array
    if (index == array.size()) {
        // Print the current subsequence
        for (int num : currentSubsequence) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }

    // Include the current element
    currentSubsequence.push_back(array[index]);
    generateSubsequences(array, index + 1, currentSubsequence);

    // Exclude the current element
    currentSubsequence.pop_back();
    generateSubsequences(array, index + 1, currentSubsequence);
}

int main() {
    std::vector<int> array = {3, 1, 2};
    std::vector<int> currentSubsequence;
    
    generateSubsequences(array, 0, currentSubsequence);
    
    return 0;
}
