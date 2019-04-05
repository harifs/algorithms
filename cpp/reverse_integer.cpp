class Solution {
public:
    long result=0;
    bool negativeFlag=false;

    int reverse(int x) {
        if(x<0 && !negativeFlag){
            negativeFlag=true;
            x*=-1;
        } else{
            result = result*10 + x%10;
            x=x/10;
        }

        if(x<1){
            if(result>INT_MAX){
                result = 0;
            }            
            if(negativeFlag && result>0)
                result*=-1;
        } else {
            reverse(x);
        }
        return(result);
    }
};