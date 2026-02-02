class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back()<9) {
            digits[digits.size()-1]++;
            return digits;
        }
        bool car=true;
        digits[digits.size()-1]=0;
        for(int i=digits.size()-2;i>=0;i--) {
            if(digits[i]==9) 
                digits[i]=0;
            else {
                digits[i]++;
                car=false;
                break;
            }
        }
        if(!car)
            return digits;
        vector<int> ans;
        ans.reserve(digits.size()+1);
        ans.push_back(1);
        for(int i=1;i<=digits.size();i++) 
            ans.push_back(digits[i-1]);
        return ans;
    }
};