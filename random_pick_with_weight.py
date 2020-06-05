#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/

from random import random
class Solution:
    

    def __init__(self, w: List[int]):
        self.w_sum = []
        self.w = w
        sum = 0
        for i in w:
            sum += i
            self.w_sum.append(sum)
        
        
    def pickIndex(self) -> int:
        target = self.w_sum[len(self.w_sum) - 1] * random()
        for i in self.w_sum:
            if target <= i:
                return self.w_sum.index(i)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
