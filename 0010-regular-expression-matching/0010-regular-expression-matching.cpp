class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            // We have two choices:
            // 1. Ignore the '*' and the preceding character (zero occurrences) -> p.substr(2)
            // 2. If the first character matched, consume one character from s and keep the '*' -> s.substr(1)
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        }
        return first_match && isMatch(s.substr(1), p.substr(1));
    }
};