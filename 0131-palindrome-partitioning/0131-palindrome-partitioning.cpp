class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) const {
        while(left<right) {
            if(s[left]!=s[right])
                return false;
            ++left; --right;
        }
        return true;
    }
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start + 1; end <= s.length(); ++end) {
            // If the current substring is a palindrome, add it to the current path
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                // Recur to find other partitions
                backtrack(s, end, path, result);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> ans;
        backtrack(s, 0, cur, ans);
        return ans;
    }
};