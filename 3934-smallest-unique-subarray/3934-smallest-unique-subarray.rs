use std::collections::HashMap;

impl Solution {
    pub fn smallest_unique_subarray(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        const M1: u64 = 1_000_000_007;
        const M2: u64 = 998_244_353;
        const B1: u64 = 100_003;
        const B2: u64 = 131_071;

        // prefix hashes and powers
        let mut h1 = vec![0u64; n + 1];
        let mut h2 = vec![0u64; n + 1];
        let mut p1 = vec![1u64; n + 1];
        let mut p2 = vec![1u64; n + 1];
        for i in 0..n {
            let v = nums[i] as u64;
            h1[i + 1] = (h1[i] * B1 + v) % M1;
            h2[i + 1] = (h2[i] * B2 + v) % M2;
            p1[i + 1] = p1[i] * B1 % M1;
            p2[i + 1] = p2[i] * B2 % M2;
        }

        // does a unique subarray of length len exist?
        let has_unique = |len: usize| -> bool {
            let mut cnt: HashMap<(u64, u64), u32> = HashMap::with_capacity(n - len + 1);
            for i in 0..=(n - len) {
                let a = (h1[i + len] + M1 * M1 - h1[i] * p1[len] % M1) % M1;
                let b = (h2[i + len] + M2 * M2 - h2[i] * p2[len] % M2) % M2;
                *cnt.entry((a, b)).or_insert(0) += 1;
            }
            cnt.values().any(|&c| c == 1)
        };

        let (mut lo, mut hi) = (1usize, n);
        while lo < hi {
            let mid = (lo + hi) / 2;
            if has_unique(mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        lo as i32
    }
}