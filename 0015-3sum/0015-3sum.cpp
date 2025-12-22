class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans1;
        unordered_map<int, vector<int>> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]={i};
            }
            else{
                m[nums[i]].push_back(i);
            }
        }
        if(m.size()==1 && m[0].size() > 3)
            return {{0,0,0}};
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int get=-nums[i]-nums[j];
                if(m.find(get)==m.end())
                    continue;
                if(m[get][m[get].size()-1]>j){
                    vector<int> temp={nums[i], nums[j], nums[m[get][m[get].size()-1]]};
                    sort(temp.begin(), temp.end());
                    ans1.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(ans1.begin(), ans1.end());
        return ans;
    }
};