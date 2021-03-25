# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
	accepted solution for addTwoNumbers question from leetcode.com
	question's link: https://leetcode.com/problems/add-two-numbers/
"""
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        resultList = ListNode(None)
        tmp = resultList  #holding result's head
        carry = 0
        
        while True:   
        	#checking if either tl1 or l2 is or isn't none
            if l1 and l2:
                sum = l1.val + l2.val + carry
            elif l1:
                sum = l1.val + carry
            elif l2: 
                sum = l2.val +carry
            #checking if the sum exceeds 10, then take the carry
            if sum >= 10:
                carry = 1
                sum -= 10
            else:
                carry = 0
            #assing for the current node's value    
            tmp.val = sum
            #again checking if either tl1 or l2 is or isn't none
            if l1 and l2:
                l1 = l1.next
                l2 = l2.next
            elif l1:
                l1 = l1.next
            elif l2:
                l2 = l2.next
                
            if l1 == None and l2 == None:
                break
            else:
                tmp.next = ListNode(None)
                tmp = tmp.next
        #if carry is still one, we should add a node and assign to its value
        if carry == 1:
            tmp.next = ListNode(None)
            tmp = tmp.next
            tmp.val = carry
        return resultList
