func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    var result [][]int
    n := len(nums)

    for a := 0; a < n-3; a++ {
        if a > 0 && nums[a] == nums[a-1] {
            continue
        }
        for b := a + 1; b < n-2; b++ {
            if b > a+1 && nums[b] == nums[b-1] {
                continue
            }
            c, d := b+1, n-1
            for c < d {
                sum := int64(nums[a]) + int64(nums[b]) + int64(nums[c]) + int64(nums[d])
                if sum == int64(target) {
                    result = append(result, []int{nums[a], nums[b], nums[c], nums[d]})
                    for c < d && nums[c] == nums[c+1] {
                        c++
                    }
                    for c < d && nums[d] == nums[d-1] {
                        d--
                    }
                    c++
                    d--
                } else if sum < int64(target) {
                    c++
                } else {
                    d--
                }
            }
        }
    }

    return result
}
