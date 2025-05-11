impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        // Ensure nums1 is the shorter array to optimize search
        if nums1.len() > nums2.len() {
            return Self::find_median_sorted_arrays(nums2, nums1);
        }
        
        let x = nums1.len();
        let y = nums2.len();
        let total_length = x + y;
        
        // Binary search boundaries
        let mut low = 0;
        let mut high = x;
        
        while low <= high {
            // Partition positions for both arrays
            let partition_x = (low + high) / 2;
            let partition_y = (total_length + 1) / 2 - partition_x;
            
            // Get the four elements around the partition
            let max_x_left = if partition_x == 0 { 
                std::i32::MIN 
            } else { 
                nums1[partition_x - 1] 
            };
            
            let min_x_right = if partition_x == x { 
                std::i32::MAX 
            } else { 
                nums1[partition_x] 
            };
            
            let max_y_left = if partition_y == 0 { 
                std::i32::MIN 
            } else { 
                nums2[partition_y - 1] 
            };
            
            let min_y_right = if partition_y == y { 
                std::i32::MAX 
            } else { 
                nums2[partition_y] 
            };
            
            // Found the correct partition
            if max_x_left <= min_y_right && max_y_left <= min_x_right {
                // Even total length
                if total_length % 2 == 0 {
                    return (max_x_left.max(max_y_left) as f64 + min_x_right.min(min_y_right) as f64) / 2.0;
                } 
                // Odd total length
                else {
                    return max_x_left.max(max_y_left) as f64;
                }
            } 
            // Adjust the binary search
            else if max_x_left > min_y_right {
                high = partition_x - 1;
            } else {
                low = partition_x + 1;
            }
        }
        
        // If we get here, the input arrays are not sorted or contain invalid elements
        0.0 // Default error case (shouldn't reach here with valid inputs)
    }
}