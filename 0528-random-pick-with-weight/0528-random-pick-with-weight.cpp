class Solution {
private:
    vector<int> dp;
    int total;
public:
    Solution(vector<int>& w): total{0} {
        for(int x:w) {
            total+=x;
            dp.push_back(total);
        }
        srand(time(0));
    }
    
    int pickIndex() {
        int num=rand()%total;
        auto it=upper_bound(dp.begin(), dp.end(), num);
        return distance(dp.begin(), it);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */