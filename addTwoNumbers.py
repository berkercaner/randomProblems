# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
"""
	accepted solution for addTwoNumbers question from leetcode.com
	Question's link : https://leetcode.com/problems/add-two-numbers/
	
"""

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        resultList = ListNode(None)
        tmp = resultList #holding resultList's head
        carry = 0
        
        while True:   
        	#checking either l1 or l2 is or isn't none
            if l1 and l2:
                sum = l1.val + l2.val + carry
            elif l1:
                sum = l1.val + carry
            elif l2: 
                sum = l2.val +carry
            #checking if the sum exceeds 10, then take the carry, will be 1 all the time.    
            if sum >= 10:
                carry = 1
                sum -= 10
            else:
                carry = 0
            #assign for the current node's value
            tmp.val = sum
            #again; checking either l1 or l2 is or isn't none, if they're both none, break the loop 'cause there isn't any number to add.
            if l1 and l2:
                l1 = l1.next
                l2 = l2.next
            elif l1:
                l1 = l1.next
            elif l2:
                l2 = l2.next
            else:
            	break
            tmp.next = ListNode(None)
            tmp = tmp.next
        #if carry is still 1, we should add a node and assign to its value    
        if carry == 1:
            tmp.next = ListNode(None)
            tmp = tmp.next
            tmp.val = carry
        return resultList
