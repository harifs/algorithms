/*
Write a function to find the longest common prefix string amongst an array of strings.

Input: ["flower","flow","flight"]
Output: "fl"

Input: ["aaa","a"]
Output: "a"

Input: ["a"]
Output: "a"

Input: [""]
Output: ""

Input: ["abc","bcd","cde"]
Output: ""
*/


class Solution {
    public String longestCommonPrefix(String[] strs) {
        String returnStr="";
        if(strs!=null && strs.length>0){
            String first=strs[0];
            for(int i=0;i<first.length();i++){
                for(int j=1;j<strs.length; j++){
                    if (strs[j].length()<=i || strs[j].charAt(i) != first.charAt(i) ){
                        return returnStr;
                    }
                }
                returnStr+=first.charAt(i);
            }
        }
        return returnStr;
    }
}