#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0, countR = 0, countUnderscore = 0;
        
        for (char move : moves) {
            if (move == 'L') {
                countL++;
            } else if (move == 'R') {
                countR++;
            } else if (move == '_') {
                countUnderscore++;
            }
        }
        
        return max(countL, countR) + countUnderscore - min(countL,countR);
    }
};