class Solution {
private:
    unordered_map<char, vector<char>> m;
    vector<string> ans;
    void getOrder(string digits, int idx, string cur) {
        for(char c:m[digits[idx]-'0']) {
            cur.push_back(c);
            if(idx==digits.size()-1)
                ans.push_back(cur);
            else
                getOrder(digits, idx+1, cur);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        m[2]={'a','b','c'};
        m[3]={'d','e','f'};
        m[4]={'g','h','i'};
        m[5]={'j','k','l'};
        m[6]={'m','n','o'};
        m[7]={'p','q','r','s'};
        m[8]={'t','u','v'};
        m[9]={'w','x','y','z'};
        string cur="";
        getOrder(digits, 0, cur);
        return ans;
    }
};