class Solution {
public:

    /* with all boundary conditions (like INT_MINVALUE checks) */
    double myPow(double x, int n) {
            double result = 1;
            double onceMore = 0;
            bool negativeFlag = 0;
            if (n<0){
                negativeFlag = 1;
                //-2,147,483,648
                if(n==-2147483648){
                    n+=1;
                    onceMore=x;
                }
                n*=-1;
            }

            while(n>0){
                if(n&1) //if(n%2==1)
                    result*=x;
                n>>=1; //n=n/2;
                x*=x;
            }

            if(onceMore!=0)
                result*=onceMore;
            if(negativeFlag)
                return 1/result;
            else
                return result;
        }
};

int main() {
	Solution obj;
	printf("%d\n",obj.power(2,5));
}
