
impl Solution {
    pub fn count_servers(
        n: i32,
        logs: Vec<Vec<i32>>,
        x: i32,
        queries: Vec<i32>
    ) -> Vec<i32> {

        let mut logs = logs;
        logs.sort_unstable_by_key(|log| log[1]);

        let mut sorted_queries: Vec<(i32, usize)> =
            queries.iter()
                .enumerate()
                .map(|(i, &q)| (q, i))
                .collect();

        sorted_queries.sort_unstable_by_key(|&(q, _)| q);

        let mut answer = vec![0; queries.len()];
        let mut counts = vec![0; n as usize + 1];

        let mut left = 0;
        let mut right = 0;

        let mut active_servers = 0;

        for (q, index) in sorted_queries {

            let start = q - x;

            // Add logs that fall before or at query time
            while right < logs.len() && logs[right][1] <= q {

                let server = logs[right][0] as usize;

                if counts[server] == 0 {
                    active_servers += 1;
                }

                counts[server] += 1;
                right += 1;
            }

            // Remove logs outside the current window
            while left < right && logs[left][1] < start {

                let server = logs[left][0] as usize;

                counts[server] -= 1;

                if counts[server] == 0 {
                    active_servers -= 1;
                }

                left += 1;
            }

            // Servers with no requests
            answer[index] = n - active_servers;
        }

        answer
    }
}
