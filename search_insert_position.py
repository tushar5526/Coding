#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        length = len(nums)
        
        if target <= nums[0]:
            return 0
        elif target > nums[- 1]:
            return length
        elif target == nums[-1]:
            return length - 1
        else:
            low = 0
            high = length - 2
            mid = 0
  
            while low <= high: 
                
                mid = (high + low) // 2
                    
                if nums[mid] == target:
                    return mid
                    
                if nums[mid] < target and nums[mid + 1] > target:
                    return mid + 1
                    
                elif nums[mid] < target: 
                    low = mid + 1

                elif nums[mid] > target: 
                    high = mid - 1
                        
            return -1