class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int x:nums) {
            if(st.find(x)!=st.end())
                return x;
            st.insert(x);
        }
        return -1;
    }
};