#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/discuss/681526/Python-O(n)-3-pointers-in-place-approach-explained

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        _0,_1,_2 = 0,0,0
        
        for i in nums:
            if i == 0:
                _0 += 1
            elif i == 1:
                _1 += 1
            else:
                _2 += 1
        nums.clear()        
        nums += [0] * _0 + [1] * _1 + [2] * _2 

#better approcah in O(N) time and O(1) space
 
 def sortColors(self, nums):
        beg, mid, end = 0, 0, len(nums) - 1
        
        while mid <= end:
            if nums[mid] == 0:
                nums[beg], nums[mid] = nums[mid], nums[beg]
                mid += 1
                beg += 1
            elif nums[mid] == 2:
                nums[mid], nums[end] = nums[end], nums[mid]
                end -= 1
            else:  #nums[mid] == 1:
                mid += 1