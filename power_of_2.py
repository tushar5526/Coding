#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        while True:
            if n == 1:
                return True
            elif n == 0:
                return False
            elif n % 2 != 0:
                return False
            else:
                n = int(n / 2)