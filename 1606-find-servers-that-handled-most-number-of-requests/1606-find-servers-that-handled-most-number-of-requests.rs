use std::collections::{BTreeSet, BinaryHeap};

impl Solution {
    pub fn busiest_servers(k: i32, arrival: Vec<i32>, load: Vec<i32>) -> Vec<i32> {
        let k = k as usize;
        
        // 1. All servers start as available
        let mut available: BTreeSet<usize> = (0..k).collect();
        
        // 2. Min-heap to track busy servers: stores (finish_time, server_id)
        // We use Reverse to make it a Min-Heap (pops the smallest finish_time first)
        let mut busy: BinaryHeap<std::cmp::Reverse<(i32, usize)>> = BinaryHeap::new();
        
        // 3. Keep track of how many requests each server handles
        let mut counts = vec![0; k];
        
        for i in 0..arrival.len() {
            let arr = arrival[i];
            let ld = load[i];
            let target = i % k;
            
            // Free up any servers that have finished their tasks by the current arrival time
            while let Some(&std::cmp::Reverse((finish_time, server_id))) = busy.peek() {
                if finish_time <= arr {
                    busy.pop();
                    available.insert(server_id);
                } else {
                    break; // The rest are still busy
                }
            }
            
            // If no servers are free, the request is dropped
            if available.is_empty() {
                continue;
            }
            
            // Find the next available server >= target
            let server = if let Some(&s) = available.range(target..).next() {
                s
            } else {
                // Wrap around to the first available server
                *available.iter().next().unwrap()
            };
            
            // Assign the request to this server
            available.remove(&server);
            counts[server] += 1;
            busy.push(std::cmp::Reverse((arr + ld, server)));
        }
        
        // Find the maximum number of requests handled by any server
        let max_req = *counts.iter().max().unwrap_or(&0);
        
        // Collect all servers that hit this maximum
        let mut result = Vec::new();
        for (i, &count) in counts.iter().enumerate() {
            if count == max_req {
                result.push(i as i32);
            }
        }
        
        result
    }
}