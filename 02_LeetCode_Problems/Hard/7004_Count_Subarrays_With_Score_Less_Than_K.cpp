class Solution {
public:
    bool isAcronym(std::vector<std::string>& words, std::string s) {
        int wordIndex = 0;  // Index to keep track of the current word
        for (char c : s) {
            if (wordIndex >= words.size()) {
                // If we've exhausted all words, but there are still characters in s
                return false;
            }
            if (c == words[wordIndex][0]) {
                // If the current character matches the first character of the current word
                wordIndex++;
            }
        }
        // If we've used up all the characters in s and also visited all words
        return wordIndex == words.size();
    }
};