class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int pointer1 = 0; // Pointer for str1
        int pointer2 = 0; // Pointer for str2
        
        while (pointer1 < str1.length() && pointer2 < str2.length()) {
            char char1 = str1.charAt(pointer1);
            char char2 = str2.charAt(pointer2);
            
            if (char1 == char2 || (char1 == 'z' && char2 == 'a') || (char1 + 1 == char2)) {
                // Matching character found or cyclic equivalence found
                pointer1++;
                pointer2++;
            } else {
                // Move only the pointer for str1
                pointer1++;
            }
        }
        
        // If all characters of str2 were matched, it's a subsequence
        return pointer2 == str2.length();
    }
}
