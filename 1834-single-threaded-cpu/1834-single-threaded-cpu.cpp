class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> v;
        v.reserve(tasks.size());
        for (int i = 0; i < (int)tasks.size(); ++i) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }

        // Sort descending so v.back() is the earliest enqueueTime
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                if (a[1] == b[1]) return a[2] > b[2];
                return a[1] > b[1];
            }
            return a[0] > b[0];
        });

        // Min-heap by shortest processingTime, then smallest index
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[2] > b[2];
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        long long cur = 0;
        vector<int> ans;
        ans.reserve(tasks.size());

        while (!v.empty() || !pq.empty()) {
            // If no tasks are currently available, jump time to the next task's enqueueTime
            if (pq.empty() && cur < v.back()[0]) {
                cur = v.back()[0];
            }

            // Push all tasks that have arrived by time `cur`
            while (!v.empty() && v.back()[0] <= cur) {
                pq.push(v.back());
                v.pop_back();
            }

            // Process the highest-priority (shortest, smallest index) available task
            auto p = pq.top();
            pq.pop();
            cur += p[1];
            ans.push_back(p[2]);
        }

        return ans;
    }
};