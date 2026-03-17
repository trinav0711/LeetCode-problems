class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        unordered_map<int, stack<int>> m;
        stack<int> tmp;
        auto& t=temperatures;
        vector<int> ans (t.size(), 0);
        for(int i=0;i<t.size();i++) {
            while(!tmp.empty()) {
                auto f=tmp.top();
                if(t[i]<=f)
                    break;
                while(!m[f].empty()) {
                    auto idx=m[f].top();
                    ans[idx]=i-idx;
                    m[f].pop();
                }
                tmp.pop();
            }
            tmp.push(t[i]);
            m[t[i]].push(i);
        }
        return ans;
    }
};