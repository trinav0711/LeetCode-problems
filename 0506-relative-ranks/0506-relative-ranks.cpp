class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans (score.size());
        unordered_map<int, int> m;
        priority_queue<int> pq;
        for(int i=0;i<score.size();++i) {
            m[score[i]]=i;
            pq.push(score[i]);
        }
        int ctr=1;
        while(!pq.empty()) {
            if(ctr<=3) {
                string tmp;
                if(ctr==1) tmp="Gold Medal";
                else if(ctr==2) tmp="Silver Medal";
                else tmp="Bronze Medal";
                ans[m[pq.top()]]=tmp;
            }
            else
                ans[m[pq.top()]]=to_string(ctr);
            ++ctr;
            pq.pop();
        }
        return ans;
    }
};