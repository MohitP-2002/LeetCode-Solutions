class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0: return n
        if n == 1: return 1
        if n == 2: return 2
        a = 0
        b = 1
        c = 0
        for i in range(n):
            c = a + b
            a = b
            b = c
        return c
        
        