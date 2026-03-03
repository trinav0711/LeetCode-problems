class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=0;
        for(int c: candies)
            m=max(m, c);
        vector<bool> ans;
        ans.reserve(candies.size());
        for(int c:candies)
            ans.push_back(c+extraCandies>=m);
        return ans;
    }
};