/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/*
 	c solution for swap nodes in pair question from leetcode.com
 	question's url ==> https://leetcode.com/problems/swap-nodes-in-pairs/
 	
*/
/* 
input : A->B->C->D->NULL

output: B->A->D->C->NULL
*/
#include <stdlib.h>
#include <malloc.h>
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* p, * q;
    struct ListNode* temp;
    struct ListNode* newHead;
    if(head == NULL || head->next == NULL) // if it's null or has 1 node
        return head;
    newHead = head->next; // newHead = B
    p = head; 			// p = A
    while(1){
        q = p->next;  	
        temp = q->next;  
        q->next = p;		
        if(temp == NULL || temp->next == NULL){  // break condition for while loop
            p->next = temp;						// if the list's node number is even, temp will be null, if it's odd it'll point a node
            break;
        }
        p->next = temp->next;	
        p = temp;				
        
    }
    return newHead; //
}

    /* while loop first iteration line by line explanation
    	
    	q = p->next = B ==>	 	 A{p} -> B {q} -> C -> D
    	temp = q->next = C ==>   A{p} -> B {q} -> C{tmp} -> D
    	q->next = p  ===>        A{p} -> <- B{q}  C{tmp} -> D
    	
    	p->next = temp->next ==> A{p} <- B{q}     C{tmp} -> D
                                 |                           |
                                  --------------------------->
    							   
    	p = temp ==>              A   <-  B         C{p} ->   D
    							  |                           |
                                   --------------------------->						   
    */
