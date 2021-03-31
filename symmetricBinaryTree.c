/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
	c solution for symmetric tree problem from leetcode.com
	question's URL = https://leetcode.com/problems/symmetric-tree/
	recursive and simple solution for checking if its left and right sides are mirror itself
	
*/
bool checkMirror(struct TreeNode*,struct TreeNode*);

bool isSymmetric(struct TreeNode* root){
    if(root == NULL)
        return true;
    return checkMirror(root->left,root->right);
}

bool checkMirror(struct TreeNode* leftNode, struct TreeNode* rightNode){
    if(leftNode == NULL && rightNode == NULL)
        return true;
    if(leftNode == NULL || rightNode == NULL)
        return false;
    else if(leftNode->val == rightNode->val)
        return true && checkMirror(leftNode->left,rightNode->right) && 
                       checkMirror(leftNode->right,rightNode->left);
    else
        return false;
    
}  
