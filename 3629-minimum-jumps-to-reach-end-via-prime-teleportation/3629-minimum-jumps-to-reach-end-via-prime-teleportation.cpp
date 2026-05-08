class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = *max_element(nums.begin(), nums.end());
        
        // 1. Sieve of Eratosthenes to find primes up to max_val
        vector<bool> is_prime(max_val + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= max_val; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= max_val; i += p)
                    is_prime[i] = false;
            }
        }

        // 2. Map primes to indices that are multiples of that prime
        // prime_to_indices[p] = {idx1, idx2, ...} where nums[idx] % p == 0
        unordered_map<int, vector<int>> prime_to_indices;
        
        // To make this efficient, find all prime factors for every number in nums
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            for (int p = 2; p * p <= val; p++) {
                if (val % p == 0) {
                    prime_to_indices[p].push_back(i);
                    while (val % p == 0) val /= p;
                }
            }
            if (val > 1) prime_to_indices[val].push_back(i);
        }

        // 3. BFS for shortest path
        queue<pair<int, int>> q; // {index, distance}
        q.push({0, 0});
        
        vector<bool> visited_idx(n, false);
        unordered_map<int, bool> used_prime_teleport; 
        visited_idx[0] = true;

        while (!q.empty()) {
            auto [curr_idx, dist] = q.front();
            q.pop();

            if (curr_idx == n - 1) return dist;

            // Adjacent Steps: i + 1
            if (curr_idx + 1 < n && !visited_idx[curr_idx + 1]) {
                visited_idx[curr_idx + 1] = true;
                q.push({curr_idx + 1, dist + 1});
            }
            // Adjacent Steps: i - 1
            if (curr_idx - 1 >= 0 && !visited_idx[curr_idx - 1]) {
                visited_idx[curr_idx - 1] = true;
                q.push({curr_idx - 1, dist + 1});
            }

            // Prime Teleportation: Only if nums[curr_idx] is prime
            int p = nums[curr_idx];
            if (is_prime[p] && !used_prime_teleport[p]) {
                used_prime_teleport[p] = true; 
                for (int next_idx : prime_to_indices[p]) {
                    if (!visited_idx[next_idx]) {
                        visited_idx[next_idx] = true;
                        q.push({next_idx, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};