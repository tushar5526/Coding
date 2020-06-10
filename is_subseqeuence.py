#https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        m = 0
        
        for i in s:
            flag = 0
            for j in range(m,len(t)):                
                if i == t[j]:
                    m = j + 1
                    flag = 1
                    break
            if flag == 0:
                return False
        
        return True