class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<2) {
            chars={chars[0]};
            return chars.size();
        }
        int count=0;
        vector<char> ans;
        for(int i=1, start=0;i<=chars.size();++i) {
            if(i==chars.size() || chars[i]!=chars[start]) {
                ans.push_back(chars[start]);
                if(i-start>1) {
                    vector<char> temp;
                    int total=i-start;
                    while(total) {
                        temp.push_back('0'+(total%10));
                        total/=10;
                        ++count;
                    }
                    reverse(temp.begin(), temp.end());
                    for(char c:temp)
                        ans.push_back(c);
                }
                ++count;
                start=i;
            }
        }
        chars.clear();
        for(auto c:ans)
            chars.push_back(c);
        return count;
    }
};