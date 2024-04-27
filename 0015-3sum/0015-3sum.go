func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var result [][]int
    n := len(nums)

    for i := 0; i < n-2; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        j, k := i+1, n-1
        for j < k {
            sum := nums[i] + nums[j] + nums[k]
            if sum == 0 {
                result = append(result, []int{nums[i], nums[j], nums[k]})
                for j < k && nums[j] == nums[j+1] {
                    j++
                }
                for j < k && nums[k] == nums[k-1] {
                    k--
                }
                j++
                k--
            } else if sum < 0 {
                j++
            } else {
                k--
            }
        }
    }

    return result
}
