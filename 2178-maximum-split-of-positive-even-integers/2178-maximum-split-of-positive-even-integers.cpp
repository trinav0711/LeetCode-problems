class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        long long cur=2, sum=0;
        vector<long long> ans;
        while(sum+cur<=finalSum) {
            ans.push_back(cur);
            sum+=cur;
            cur+=2;
        }
        ans[ans.size()-1]+=(finalSum-sum);
        return ans;
    }
};