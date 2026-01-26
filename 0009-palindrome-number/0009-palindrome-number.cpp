class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        vector<char>c;
        while(x) {
            c.push_back((char)(x%10));
            x/=10;
        }
        vector<char>c1(c);
        reverse(c.begin(), c.end());
        for(int i=0;i<c.size();i++)
            if(c[i]!=c1[i])
                return false;
        return true;
    }
};