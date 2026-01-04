class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int x:nums)
            m[x]=1;
        for(int x:nums){
            if(m.find(x)==m.end() || m[x]>1)
                continue;
            int ctr=1;
            for(int i=x+1;m.find(i)!=m.end();i++, ctr++){
                if(m[i]>1){
                    ctr=ctr+m[i];
                    m.erase(i);
                    break;
                }
                m.erase(i);
            }
            m[x]=ctr;
        }
        int ans=0;
        for(auto it=m.begin(); it!=m.end(); it++)
            ans=max(ans, it->second);
        return ans;
    }
};