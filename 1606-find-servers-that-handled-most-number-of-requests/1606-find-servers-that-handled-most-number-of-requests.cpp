#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // 1. All servers start as available
        set<int> available;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        // 2. Min-heap to track busy servers: stores (finish_time, server_id)
        // std::greater makes it a Min-Heap (smallest finish_time on top)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        
        // 3. Count how many requests each server handles
        vector<int> counts(k, 0);
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            int arr = arrival[i];
            int ld = load[i];
            int target = i % k;
            
            // Free up any servers that have finished by the current arrival time
            while (!busy.empty() && busy.top().first <= arr) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            // If no servers are free, the request is dropped
            if (available.empty()) {
                continue;
            }
            
            // Find the next available server >= target
            auto it = available.lower_bound(target);
            if (it == available.end()) {
                // Wrap around to the first available server
                it = available.begin();
            }
            
            int server = *it;
            available.erase(it);
            counts[server] += 1;
            busy.push({arr + ld, server});
        }
        
        // Find the maximum number of requests handled
        int max_req = 0;
        for (int c : counts) {
            max_req = max(max_req, c);
        }
        
        // Collect all servers that hit this maximum
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_req) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};