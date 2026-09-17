class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> left(heights.size());
        auto right=left;
        for(int i=0;i<heights.size();++i) {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=heights.size()-1;i>=0;--i) {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) right[i]=heights.size();
            else right[i]=st.top();
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<heights.size();++i) {
            ans=max(ans, heights[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};