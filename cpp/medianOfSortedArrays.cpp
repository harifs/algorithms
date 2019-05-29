/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

nums1 = [1, 3]
nums2 = [2]
The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/ 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
        int i=0,j=0;
        double median = 0.0;
        vector<int> merged;
        while (i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                merged.push_back(nums1[i++]);
            } else{
                merged.push_back(nums2[j++]);
            }
        }
        
        while (i<nums1.size())
        	merged.push_back(nums1[i++]);
                
        while(j<nums2.size())
            merged.push_back(nums2[j++]);
                
        //for(const int& element: merged){
        //    cout<<element<<endl;
        //}
        
        if(merged.size()&1)
            median=merged[merged.size()/2]; //size index starts from 0, no need increment index
        else
            median=(merged[merged.size()/2-1] + merged[merged.size()/2]) * 0.5;
        
        return median;
    }
};

/*
Runtime: 24 ms, faster than 88.16% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 10.5 MB, less than 57.62% of C++ online submissions for Median of Two Sorted Arrays.
*/