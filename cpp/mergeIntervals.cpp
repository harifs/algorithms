/** Given a binary tree, return the inorder traversal of its nodes' values.

Input:
[[2,3],[4,5],[6,7]]
Output:
[[2,3],[4,5],[6,7]]


Input:
[[1,4],[0,0]]
Output:
[[0,0],[1,4]]

Input:
[[1,4],[0,2]]
Output:
[[0,4]]

Input:
[[1,4],[2,3]]
Output:
[[1,4]]

--- Fixed with sorting the vector before starting
Input: 
[[2,3],[4,5],[6,7],[8,9],[1,10]]
Output:
[[4,5],[6,7],[8,9],[1,10]]
Expected:
[[1,10]]
**/

 class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> output;
        vector<int> pair;
        
        if(intervals.size()>0){
            pair = intervals[0];
            for(int i=1;i<intervals.size();++i){
                
                cout<<intervals[i][0]<<":"<<intervals[i][1]<<" vs "<<pair[0]<<":"<<pair[1]<<endl;
                
                
                //interval is out of range (right)
                //if(intervals[i][1]<pair[0] && intervals[i][0]<=pair[0] )
                //    output.push_back(intervals[i]);
                
                //interval is out of range (left)
                //else if(intervals[i][0]>pair[1])
                //    output.push_back(intervals[i]);

				/*** After sorting the array, explicit processing of out-of-range is not necessary ***/
                /*** Now we are processing only in-range pairs***/
                
                //retain the smallest of the endtime
                if(intervals[i][0]<pair[0]) 
                       pair[0] = intervals[i][0];
                
                //starting time is before the ending time of pair
                if(intervals[i][0]<=pair[1]){
                    if(intervals[i][1]>pair[1]) //retain the largest of the endtime
                        pair[1] = intervals[i][1];
                } else{
                    output.push_back(pair);
                    pair=intervals[i];
                }
                
                cout<<"After: "<<pair[0]<<":"<<pair[1]<<endl;
                
                if(i==(intervals.size()-1) )
                        output.push_back(pair);
            }
            
            if(output.empty())
                output.push_back(pair);
        }
        return output;
    }
};

/*  NOT THE BEST - because of using the sort
Runtime: 40 ms, faster than 18.69% of C++ online submissions for Merge Intervals.
Memory Usage: 12.6 MB, less than 12.20% of C++ online submissions for Merge Intervals.
*/