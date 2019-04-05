/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example1: TRUE
    1
   / \
  2   2
 / \ / \
3  4 4  3

Example2: FALSE
    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 
class Solution {

    public boolean isSymmetric(TreeNode root) {
        if(null==root) 
            return true;
        else
            return compare(root.left,root.right);
    }
    
    public boolean compare(TreeNode A, TreeNode B){
            
        //both are null
        if((null==A) && (null==B)){
            System.out.println("Both are NUll - true");
            return true;
        }
        //One of them is null
        else if ( ((null==A)?true:false) ^ ((null==B)?true:false) ){
            System.out.println("One of them is Null - false");
            return false;
        }
        else if(A.val != B.val){
            System.out.println("Node values dont match - false");
            return false;
        }
        else{
            System.out.println("Matched "+ A.val + ":" + B.val);
            return compare(A.left,B.right) && compare(A.right,B.left);
        }
    }
}