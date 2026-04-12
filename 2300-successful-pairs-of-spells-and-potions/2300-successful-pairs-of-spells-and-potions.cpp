class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int s:spells) {
            long long cutoff=ceil(static_cast<double>(success)/static_cast<double>(s));
            ans.push_back(potions.end()-lower_bound(potions.begin(), potions.end(), cutoff));
        }
        return ans;
    }
};