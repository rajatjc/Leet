class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Check even indices (0 and 2)
        bool evenCheck = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);
        
        // Check odd indices (1 and 3)
        bool oddCheck = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);
        
        // Return true if either even or odd check succeeds
        return evenCheck && oddCheck;
    }
};
