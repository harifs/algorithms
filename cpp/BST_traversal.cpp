/** Given a binary tree, return the inorder traversal of its nodes' values.
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
**/


 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> vectorObj;
    
    //inorderTraversalRecursive
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        if (root!=NULL){
            if(root->left != NULL)
                inorderTraversal(root->left);
            cout<<root->val;
            vectorObj.push_back(root->val);
            if(root->right != NULL)
                inorderTraversal(root->right);
        }
        return vectorObj;
    }
    
    //inorderTraversalIterative
    vector<int> inorderTraversalIterative(TreeNode* root) {
        if (root!=NULL){
            stackObj.push(root);
            cout<<"stackObj: "<<stackObj.top()->val;
            while(stackObj.top()->left != NULL){
                stackObj.push(stackObj.top()->left);
            }
            cout<<"size: "<<stackObj.size();
            
            while(!stackObj.empty()){
                //poping starts
                vectorObj.push_back(stackObj.top()->val);
                cout<<"Poped: "<<stackObj.top()->val;

                //stack TOP is shifted to the right of previous TOP
                if(stackObj.top()->right != NULL){
                    TreeNode* right = stackObj.top()->right;
                    stackObj.pop();
                    stackObj.push(right);
                    while(stackObj.top()->left != NULL){
                        stackObj.push(stackObj.top()->left);
                    }
                } else{
                    stackObj.pop();
                }
            }
        }
        return vectorObj;
    }
};