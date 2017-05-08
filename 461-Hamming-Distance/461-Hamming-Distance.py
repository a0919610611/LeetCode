class Solution(object):
    def hammingDistance(self, x, y):
	"""
	:type x: int
	:type y: int
	:rtype: int
	"""
        z=x^y
        ans=0
        for i in range(0,32):
            if z&(1<<i):
                ans+=1
        return ans
