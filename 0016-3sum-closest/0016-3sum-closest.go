func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    n := len(nums)
    closestSum := nums[0] + nums[1] + nums[n-1]

    for i := 0; i < n-2; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        j, k := i+1, n-1
        for j < k {
            sum := nums[i] + nums[j] + nums[k]
            if sum == target {
                return target
            }
            if abs(sum-target) < abs(closestSum-target) {
                closestSum = sum
            }
            if sum < target {
                j++
            } else if sum > target {
                k--
            } else {
                j++
                k--
            }
        }
    }

    return closestSum
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
