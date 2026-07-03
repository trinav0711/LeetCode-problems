class Solution {
private:
    void recur(vector<string>& ans, string& str, int n, int open) {
        cout<<str<<endl;
        if(str.length()==2*n) {
            if(!open)
                ans.push_back(str);
            return;
        }
        if(str.empty()) {
            str.push_back('(');
            recur(ans, str, n, open+1);
            str.pop_back();
        }
        else if(str.length()==2*n-1) {
            str.push_back(')');
            recur(ans, str, n, open-1);
            str.pop_back();
        }
        else {
            str.push_back('(');
            recur(ans, str, n, open+1);
            str.pop_back();
            if(open>0) {
                str.push_back(')');
                recur(ans, str, n, open-1);
                str.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; string s;
        recur(ans, s, n, 0);
        return ans;
    }
};