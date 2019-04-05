/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> output = new ArrayList<List<Integer>>();
        List<Integer> row = new ArrayList<Integer>();
        List<Integer> temp = new ArrayList<Integer>();
        for(int i=1; i<=numRows; i++){
            for(int j=1; j<=i; j++){
                if(j==1 || j==i)
                    row.add(1);
                else
                    row.add(temp.get(j-1-1)+temp.get(j-1));
            }
            System.out.println(row.toString());
            output.add(row);
            temp = new ArrayList<Integer>(row);
            row = new ArrayList<Integer>();
        }
        return output;
    }
    
    public static void main(String args[]){
    	Solution obj = new Solution();
    	obj.generate(5);
    }
}