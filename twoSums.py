""" python3 solution of twoSum question from leetcode.com 
	Question's URL => https://leetcode.com/problems/two-sum
	
"""
class Solution:
	def twoSum(self, nums: List[int], target: int) -> List[int]:
		data = dict()
		result = []
		i = 0
		while i < len(nums):
			complement = target - nums[i]
			if complement not in data:
				data[nums[i]] = i
				i += 1
			else:
				result = [data[complement],i]
				return result

