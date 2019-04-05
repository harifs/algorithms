/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Input: "A man, a plan, a canal: Panama"
Output: true

Input: ""
Output: true

Input: "ab@a"
Output: true
*/

class Solution {
    public boolean isPalindrome(String s) {
        if(s.isEmpty())
            return true;

        s = s.replaceAll("[^a-zA-Z0-9]","").toLowerCase();
        
        int i,j;
        for(i=0,j=s.length()-1; i<=j; i++,j--)
            if(s.charAt(i)!=s.charAt(j))
                return false;
        return true;
    }
}