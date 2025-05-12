class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays($nums1, $nums2) {
        // Ensure nums1 is the smaller array to perform binary search on it
        if (count($nums1) > count($nums2)) {
            return $this->findMedianSortedArrays($nums2, $nums1);
        }
        
        $m = count($nums1);
        $n = count($nums2);
        $left = 0;
        $right = $m;
        $totalLeft = ($m + $n + 1) / 2;  // Total elements in left partition
        
        while ($left <= $right) {
            $i = intval(($left + $right) / 2);  // Partition position in nums1
            $j = intval($totalLeft - $i);       // Partition position in nums2
            
            // Handle edge cases where i or j is out of bounds
            $nums1LeftMax = ($i == 0) ? PHP_INT_MIN : $nums1[$i - 1];
            $nums1RightMin = ($i == $m) ? PHP_INT_MAX : $nums1[$i];
            $nums2LeftMax = ($j == 0) ? PHP_INT_MIN : $nums2[$j - 1];
            $nums2RightMin = ($j == $n) ? PHP_INT_MAX : $nums2[$j];
            
            if ($nums1LeftMax <= $nums2RightMin && $nums2LeftMax <= $nums1RightMin) {
                // Found the correct partition
                if (($m + $n) % 2 == 1) {
                    return max($nums1LeftMax, $nums2LeftMax);
                } else {
                    return (max($nums1LeftMax, $nums2LeftMax) + min($nums1RightMin, $nums2RightMin)) / 2;
                }
            } elseif ($nums1LeftMax > $nums2RightMin) {
                $right = $i - 1;
            } else {
                $left = $i + 1;
            }
        }
        
        return 0.0;  // Shouldn't reach here for valid inputs
    }
}