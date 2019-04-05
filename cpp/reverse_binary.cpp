/*
Input: 43261596
Output: 964176192
Explanation: 
input  43261596 represented in binary as 00000010100101000001111010011100 
return 964176192 represented in binary as 00111001011110000010100101000000
*/

#include<bitset>

class Solution {
public:
    
    std::string reversedBinaryStr(uint32_t n){
        std::string reversedBinary;
        while (n>=0){
            reversedBinary = r+((n%2 == 0)?"0":"1");
            n=n/2;
        }
        return reversedBinary;
    }
    
    std::string reverseStr(std:string str){
        const char *array = str.c_str();
        char tmp;
        for(int i=0,int j=strlen(array)-1; i<j; i++){
        	tmp = array[i];
        	array[i]=array[j];
        	array[j]=tmp;
        }
        return str(array);
    }
    
    /* reverseBits to reverse the bits - it doesn't use the above defined functions though */
    uint32_t reverseBits(uint32_t n) {
        std::string binaryStr = std::bitset<32>(n).to_string();
        reverse(binaryStr.begin(),binaryStr.end());
        unsigned long reversedDecimal = std::bitset<32>(binaryStr).to_ulong();
        return reversedDecimal;
    }
};