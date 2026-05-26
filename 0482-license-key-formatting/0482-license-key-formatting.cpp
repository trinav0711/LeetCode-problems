class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<char> v;
        for(char c:s) {
            if(c!='-') {
                if(c>='a' && c<='z')
                    v.push_back(char('A'+int(c-'a')));
                else
                    v.push_back(c);
            }
        }
        string ans="";
        while(!v.empty()) {
            string block="";
            while(!v.empty() && block.length()<k) {
                block+=v.back(); v.pop_back();
            }
            ans+=(block+"-");
        }
        if(ans=="") return ans;
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};