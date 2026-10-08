class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long d1 = d[0], d2 = d[1];
        long long r1 = r[0], r2 = r[1];
        long long lcm_val = std::lcm(r1, r2);
        long long right = 2 * (d1 + d2), left=1LL;
        auto isValid = [&](long long T) -> bool {
            long long avail1 = T - T / r1;
            long long avail2 = T - T / r2;
            long long avail_total = T - T / lcm_val;

            return (avail1 >= d1) && (avail2 >= d2) && (avail_total >= d1 + d2);
        };
        while(left<right) {
            long long mid = left + (right - left) / 2;
            if (isValid(mid)) {
                right = mid;      // Mid is feasible; try to find a smaller valid time
            } else {
                left = mid + 1;  // Mid is infeasible; move to larger time
            }
        }
        return left;
    }
};