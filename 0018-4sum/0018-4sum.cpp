class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<long, vector<int>> m;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();++i)
            m[nums[i]].push_back(i);
        set<vector<int>> ans;
        for(int a=0;a<nums.size();++a) {
            for(int b=a+1;b<nums.size();++b) {
                for(int c=b+1;c<nums.size();++c) {
                    long diff=static_cast<long>(target);
                    diff=diff-nums[a]-nums[b]-nums[c];
                    if(m.find(diff)!=m.end() && m[diff].back()>c)
                        ans.insert({nums[a],nums[b],nums[c],nums[m[diff].back()]});
                }
            }
        }
        vector<vector<int>> v;
        for(auto& vec:ans)
            v.push_back(vec);
        return v;
    }
};