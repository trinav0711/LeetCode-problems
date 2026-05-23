class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> visit(nums.size()+1, false);
        for(int x:nums) visit[x]=true;
        vector<int> ans;
        for(int i=1;i<visit.size();++i) {
            if(!visit[i]) ans.push_back(i);
        }
        return ans;
    }
};