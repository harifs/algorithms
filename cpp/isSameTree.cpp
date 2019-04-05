/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
Output: true

[0]
[]
FALSE

[1,2,3]
[1,2,null,3]
FALSE

 */
 
/* 
1.) if p XOR q FALSE
2.) if p->val != q->val  FALSE
3.) if only one of the p->left and q->left exists  FALSE
4.) if only one of the p->right and q->right exists  FALSE
5.) continue till end of the tree as long as they are same
If nothing contradicted, end reached, then return TRUE
*/ 

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //[][0] return false
        if((p?1:0)^(q?1:0))
            return false;

		//Proceed only if both are not null
        if(p!=NULL && q!=NULL){
            
            if (p->val != q->val)
                return false;
            
            if(!(p->left?1:0)^(q->left?1:0)){
                if(isSameTree(p->left, q->left) == false)
                    return false;
            }
            else
                return false;
            
            if(!(p->right?1:0)^(q->right?1:0)){
                if(isSameTree(p->right, q->right) == false)
                    return false;
            }
            else
                return false;
        }

        return true;
    }
};