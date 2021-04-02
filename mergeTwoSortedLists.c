/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/*
	recursive c solution for merge two sorted lists problem from leetcode.com
	question URL => https://leetcode.com/problems/merge-two-sorted-lists/
	example Input: l1 : 1->2->4  l2 : 1->3->4 output: 1->1->2->3->4->4
*/ 

struct ListNode* mergeHelper(struct ListNode*, struct ListNode*);
    
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;
    else
        return mergeHelper(l1,l2);
}

struct ListNode* mergeHelper(struct ListNode* node1, struct ListNode* node2){
    if(node1 == NULL)
        return node2;
    else if(node2 == NULL)
        return node1;
        
    if(node1->val >= node2->val){
        node2->next = mergeHelper(node1,node2->next);
        return node2;
    }
    else{
        node1->next = mergeHelper(node1->next,node2);
        return node1;
    }
}
