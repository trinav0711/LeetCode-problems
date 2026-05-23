class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int> sz, gr;
        int ans=0;
        for(int x:g) gr.push(x);
        for(int x:s) sz.push(x);
        while(!sz.empty() && !gr.empty()) {
            if(gr.top()<=sz.top()) {
                ++ans;
                sz.pop();
            }
            gr.pop();
        }
        return ans;
    }
};