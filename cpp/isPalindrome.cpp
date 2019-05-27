#include<iostream>
#include<deque>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool retVal = true;
        deque <int> myqueue;
        unsigned short digit;
        
        if(x<0)
            return false;
        
        while(x){
            digit = x%10;
            myqueue.push_back(digit);
            x = x/10;
        }
        
        while(!myqueue.empty()){
            if(myqueue.front() != myqueue.back()){
                retVal = false;
                break;
            } else{
                myqueue.pop_back();
                if(!myqueue.empty())
                    myqueue.pop_front();
            }
        }
        return retVal;
    }
};


/*
Runtime: 28 ms, faster than 84.20% of C++ online submissions for Palindrome Number.
Memory Usage: 17.8 MB, less than 54.29% of C++ online submissions for Palindrome Number.
*/