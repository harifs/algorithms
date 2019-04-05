/*
 * Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 * Input: 11
 * Output: 3
 * Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
*/


/* runtime 8ms -> not very efficient */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::string binaryStr = std::bitset<32>(n).to_string();
        const char *array = str.c_str();
        uint32_t count=0;
        for(int i=0; i<strlen(array); i++)
            if(array[i]=='1')
                count++;
        return count;
    }
};

/* //JAVA VERSION -> 1ms runtime
public int hammingWeight(int n) {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        mask <<= 1;
    }
    return bits;
}
*/