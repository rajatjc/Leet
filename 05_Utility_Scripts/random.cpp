#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int max_sum = arr[0];
  int current_sum = arr[0];

  for (size_t i = 1; i < arr.size(); ++i)
  {
    current_sum = std::max(arr[i], current_sum + arr[i]);
    max_sum = std::max(max_sum, current_sum);
  }

  std::cout << "Maximum subarray sum is: " << max_sum << std::endl;
  return 0;
}
