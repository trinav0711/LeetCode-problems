class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0; // Minimum possible open left parentheses
        int leftMax = 0; // Maximum possible open left parentheses

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else { // c == '*'
                leftMin--; // Treat as ')'
                leftMax++; // Treat as '('
            }

            // If max open parentheses is negative, we have too many ')'
            if (leftMax < 0) {
                return false;
            }
            
            // We can never have negative open parentheses. 
            // If leftMin goes negative, it just means we chose too many '*' to be ')'
            if (leftMin < 0) {
                leftMin = 0; 
            }
        }

        // It is only valid if we can end up with exactly zero open parentheses
        return leftMin == 0;
    }
};