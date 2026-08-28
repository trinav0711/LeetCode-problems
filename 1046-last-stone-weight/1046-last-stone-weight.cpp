class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x:stones) pq.push(x);
        while(pq.size()>1) {
            int stone=pq.top();
            pq.pop();
            stone-=pq.top();
            pq.pop();
            if(stone) pq.push(stone);
        }
        if(!pq.empty()) return pq.top();
        return 0;
    }
};