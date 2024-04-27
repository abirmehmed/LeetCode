impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        nums.sort();
        let n = nums.len();

        for i in 0..n - 2 {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let mut j = i + 1;
            let mut k = n - 1;
            while j < k {
                let sum = nums[i] + nums[j] + nums[k];
                if sum == 0 {
                    result.push(vec![nums[i], nums[j], nums[k]]);
                    while j < k && nums[j] == nums[j + 1] {
                        j += 1;
                    }
                    while j < k && nums[k] == nums[k - 1] {
                        k -= 1;
                    }
                    j += 1;
                    k -= 1;
                } else if sum < 0 {
                    j += 1;
                } else {
                    k -= 1;
                }
            }
        }

        result
    }
}
