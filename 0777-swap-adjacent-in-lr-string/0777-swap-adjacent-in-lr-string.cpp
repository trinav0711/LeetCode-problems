class Solution {
public:
    bool canTransform(string start, string result) {
        int i=0, j=0;
        while(i<start.length() && j<result.length()) {
            while(i<start.length() && start[i]=='X') ++i;
            while(j<result.length() && result[j]=='X') ++j;
            if(i>=start.length() || j>=result.length())
                break;
            if(start[i]!=result[j])
                return false;
            if(start[i]=='L' && i<j)
                return false;
            if(start[i]=='R' && i>j)
                return false;
            ++i; ++j;
        }
        while(i<start.length() && start[i]=='X') ++i;
        while(j<result.length() && result[j]=='X') ++j;
        return i>=start.length() && j>=result.length();
    }
};