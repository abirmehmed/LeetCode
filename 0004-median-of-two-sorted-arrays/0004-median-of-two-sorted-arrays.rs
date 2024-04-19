impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let m = nums1.len();
        let n = nums2.len();
        let total_length = m + n;

        if m > n {
            return Self::find_median_sorted_arrays(nums2, nums1);
        }

        let mut left = 0;
        let mut right = m;

        while left <= right {
            let partition_x = (left + right) / 2;
            let partition_y = (total_length + 1) / 2 - partition_x;

            let max_left_x = if partition_x == 0 { i32::MIN } else { nums1[partition_x - 1] };
            let min_right_x = if partition_x == m { i32::MAX } else { nums1[partition_x] };

            let max_left_y = if partition_y == 0 { i32::MIN } else { nums2[partition_y - 1] };
            let min_right_y = if partition_y == n { i32::MAX } else { nums2[partition_y] };

            if max_left_x <= min_right_y && max_left_y <= min_right_x {
                if total_length % 2 == 0 {
                    return (f64::max(max_left_x as f64, max_left_y as f64) + f64::min(min_right_x as f64, min_right_y as f64)) / 2.0;
                } else {
                    return f64::max(max_left_x as f64, max_left_y as f64);
                }
            } else if max_left_x > min_right_y {
                right = partition_x - 1;
            } else {
                left = partition_x + 1;
            }
        }

        panic!("No median found");
    }
}
