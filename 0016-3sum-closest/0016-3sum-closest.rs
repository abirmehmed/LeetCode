impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        let n = nums.len();
        nums.sort();
        let mut closest_sum = nums[0] + nums[1] + nums[n - 1];

        for i in 0..n - 2 {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let mut j = i + 1;
            let mut k = n - 1;
            while j < k {
                let sum = nums[i] + nums[j] + nums[k];
                if sum == target {
                    return target;
                }
                if (sum - target).abs() < (closest_sum - target).abs() {
                    closest_sum = sum;
                }
                if sum < target {
                    j += 1;
                } else if sum > target {
                    k -= 1;
                } else {
                    j += 1;
                    k -= 1;
                }
            }
        }

        closest_sum
    }
}
