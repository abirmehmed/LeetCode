class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low = 0            # Pointer for the next position of 0
        mid = 0            # Pointer for the current element
        high = len(nums) - 1  # Pointer for the next position of 2

        while mid <= high:
            if nums[mid] == 0:
                # Swap nums[low] and nums[mid], then increment both
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                # If it's 1, just move to the next element
                mid += 1
            else:  # nums[mid] == 2
                # Swap nums[mid] and nums[high], then decrement high
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1

