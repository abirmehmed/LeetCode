class Solution(object):
    def nextPermutation(self, nums):
        n = len(nums)
        i = n - 2  # Start from the second-to-last element

        # Find the first decreasing element from right to left
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        if i >= 0:
            # Find the smallest element greater than nums[i] to its right
            j = n - 1
            while j > i and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        # Reverse the subarray from i+1 to the end
        nums[i + 1:] = reversed(nums[i + 1:])
