# From: https://leetcode.com/problems/string-to-integer-atoi/discuss/178641/Simple-python-solution
# Note: No need to consider the range of int type since Python automatically transfer int to long long int.

INT_MAX = (2 ** 31) - 1
INT_MIN = -(2 ** 31)

class Solution(object):
    def myAtoi(self, s):
        """
        :type str: str
        :rtype: int
        """
        s = s.strip()
        
        i = s[:1] in "+-"
        while i < len(s) and s[i] in "0123456789": i += 1
        substr = s[:i]
        
        result = 0 if not substr or substr in "+-" else int(substr)
        return max(min(result, INT_MAX), INT_MIN)