class Solution {
public:
	/* if binary form of a number has odd number of 1st, its parity is 1 else 0 */
    int parity(unsigned int x){
    	short result = 0;
    	while (x){
    		result ^= 1; //flip the parity
    		x&=(x-1); //chomp the rightmost (least significant) bit
    	}
    	return result;
    }

    //add without using arithmetic sign
    int add(int x, int y){
    	if(y==0)
    		return x;
    	else
    		return add(x^y,(x&y)<<1);
    }

    //swap without using arithmetic sign
    void swap(int x, int y){
    	x ^= y;
    	y ^= x;
    	x ^= y;
    	cout<<"x="<<x<<endl;
    	cout<<"y="<<y<<endl;
    }

	//swap case - XOR by space
	// a ^ ' ' = A
	// A ^ ' ' = a

	//to_lower - OR by space
    // A | ' ' = a
    
    //to_higher - ANY by _
    // A & '_' = a
    
    //isODD?
	//(n & 1) == 1;
    
};


int main() {
	Solution obj;
	
	cout<<obj.parity(3)<<endl;
	cout<<obj.add(3,4)<<endl;
	cout<<obj.swap(2,5)<<endl;
}
