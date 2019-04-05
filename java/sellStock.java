/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

Input: [1,1,0]
Output: 0

Input: [7,2,5,1]
Output: 3

Input: [4,7,1,2]
Output: 1

*/

import java.util.NavigableMap;
import java.util.TreeMap;

class Solution {
    
    private static int gain = 0;
    
    public int helper(NavigableMap<Integer,Integer> map){
        
        if(map.size()<=0)
            return gain;
        
        int ret;
        if(map.size()>0 && map.get(map.firstKey()) < map.get(map.lastKey())){
            ret = map.lastKey() - map.firstKey();
        }
        else {
            int tail = helper(map.tailMap(map.firstKey(),false));
            int head = helper(map.headMap(map.lastKey(),false));
            ret = (tail >= head)?tail: head;
        }
        
        if (ret > gain)
                gain = ret;
        
        return gain;
    }

    public int maxProfit(int[] prices) {
        
        if(prices.length<2)
            return gain;
        
        NavigableMap<Integer,Integer> map = new TreeMap<Integer,Integer>();
        for(int i=0;i<prices.length;i++)
            map.put(prices[i],i);
        
        gain = helper(map);    
        return gain;
    }
}