"""
	python3 solution for median of two sorted arrays questions from  leetcode
	question's link: https://leetcode.com/problems/median-of-two-sorted-arrays/
"""
class Solution:
	def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
		i = 0
		#appending nums2 to nums1
		while i<len(nums2[i])
			nums1.append(nums2[i])
			i += 1
		#sorting it again
		nums1.sort()
		n = len(nums1)
		
		#finding median
		if n%2 == 0:
			result =(nums1[n//2] + nums1[(n//2) - 1]) / 2
		else:
			result = nums1[n//2]
		
		return result
