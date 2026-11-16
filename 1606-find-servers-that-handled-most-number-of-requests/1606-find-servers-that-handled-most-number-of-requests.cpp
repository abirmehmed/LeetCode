class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // 1. All servers start as available
        std::set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // 2. Min-heap to track busy servers: stores {finish_time, server_id}
        // We use greater<pair<int, int>> to make it a Min-Heap (pops smallest finish_time first)
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        
        // 3. Keep track of how many requests each server handles
        std::vector<int> counts(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            int arr = arrival[i];
            int ld = load[i];
            int target = i % k;
            
            // Free up any servers that have finished their tasks by the current arrival time
            while (!busy.empty() && busy.top().first <= arr) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If no servers are free, the request is dropped
            if (available.empty()) {
                continue;
            }
            
            // Find the next available server >= target
            // lower_bound is the C++ equivalent of Rust's range(target..).next()
            auto it = available.lower_bound(target);
            int server;
            
            if (it != available.end()) {
                server = *it;
                available.erase(it);
            } else {
                // Wrap around to the first available server
                it = available.begin();
                server = *it;
                available.erase(it);
            }
            
            // Assign the request to this server
            counts[server]++;
            busy.push({arr + ld, server});
        }
        
        // Find the maximum number of requests handled by any server
        int max_req = *std::max_element(counts.begin(), counts.end());
        
        // Collect all servers that hit this maximum
        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_req) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};