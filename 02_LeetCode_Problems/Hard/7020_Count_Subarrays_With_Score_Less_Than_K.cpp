class Solution {
public:
    bool isSymmetric(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        int sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < n / 2; i++) {
            sum1 += numStr[i] - '0';
            sum2 += numStr[n - i - 1] - '0';
        }
        
        return sum1 == sum2&&n%2==0;
    }
    
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        
        for (int i = low; i <= high; i++) {
            if ( isSymmetric(i)) {
                count++;
            }
        }
        
        return count;
    }
};
