class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string evenS1, oddS1, evenS2, oddS2;
        
        // Create even and odd strings for s1 and s2
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                evenS1 += s1[i];
                evenS2 += s2[i];
            } else {
                oddS1 += s1[i];
                oddS2 += s2[i];
            }
        }
        
        // Sort the even and odd strings
        sort(evenS1.begin(), evenS1.end());
        sort(oddS1.begin(), oddS1.end());
        sort(evenS2.begin(), evenS2.end());
        sort(oddS2.begin(), oddS2.end());
        
        // Check if the sorted even and odd strings are equal
        return (evenS1 == evenS2) && (oddS1 == oddS2);
    }
};
