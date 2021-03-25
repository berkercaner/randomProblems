/*
	"DUMMY" c solution of addTwoNumbers question from leetcode.com
	Question's URL = https://leetcode.com/problems/add-two-numbers/
	
	solution is dummy because it'll fail if the input is very large +20 digit number
	like : 10000000100023000100005
	but it'll work with "unsigned long range"
*/

/* ---------------------------------------------------------------------------------------------- */
/*
	question's definition of the linked list:
	struct ListNode{
		int val;
		struct ListNode* next;
	};
*/
#include <stdlib.h>
#include <malloc.h>

struct ListNode* addNode(struct ListNode* newnode, int value){
	if(newnode == NULL){
		struct ListNode* root = (struct ListNode*) malloc(sizeof(struct ListNode));
		root->val = value;
		root->next = NULL;
		return root;
	}
	newnode->next = addNode(newnode->next,value);
	return newnode;
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	unsigned long long value1 = 0, value2 = 0, result = 0, tmp = 0, factor = 1;
	int digits = 0;
	struct ListNode* resultList = NULL;
	// creating the values as integers
	while(l1 != NULL){
		value1 += (l1->val)*factor;
		l1 = l1->next;
		factor *= 10;
	}
	factor = 1;
	while(l2 != NULL){
		value2 += (l2->val)*factor;
		l2 = l2->next;
		factor *= 10;
	}
	
	result = value1 + value2; 
	tmp = result;
	//counting digits
	while(tmp){
		digits++;
		tmp /= 10;
	}
	//if digits == 0 l1->val = 0 and l2->val = 0=> so should return 0
	if(digits == 0){
		resultList = addNode(resultList,0);
		return resultList;
	}
	//creating an array for not wasting brain cells while reversing the linked list  ===> most important part of the code 
	int array[digits];
	tmp = result;
	for(int i=0; i<digits; i++){
		array[i] = result%10;
		result /= 10;
	}
	//creating the result linked list
	for(int i=0; i<digits; i++){
		resultList = addNode(resultList, array[i]);
	}
	
	return resultList;
}





