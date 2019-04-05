class Solution {
public:
    int myAtoi(string strn) {
        long intStr=0;
        int eachChar;
        bool startFlag = false;
        bool negativeFlag = false;
        
        const char *str = strn.c_str();
        
        //cout<<"srlen:"<<strlen(str)<<"\n";
        for(int i=0;i<strlen(str);i++){
            eachChar=str[i];
            //cout<<"eachChar:"<<eachChar<<"\n";
            
            if(eachChar==32 && startFlag==false){
                continue;
            } else if (eachChar==43 && startFlag==false){
                startFlag=true;
            } else if (eachChar==45 && startFlag==false){
                startFlag=true;
                negativeFlag=true;
                //cout<<"negativeFlag:"<<negativeFlag<<"\n";
            } else if (eachChar>=48 && eachChar<=57){
                if(startFlag)
                    intStr=intStr*10+(eachChar-48);
                else{
                    intStr=(eachChar-48);
                    startFlag=true;
                }
            } else if (startFlag){
                break;
            } else if(intStr==0 && !startFlag){
                break;
            }
            //cout<<"intStr:"<<intStr<<"\n";
            
            if(intStr>INT_MAX){
                if(negativeFlag)
                    intStr=INT_MIN;
                else
                    intStr=INT_MAX;
                break;
            }
            if(intStr<INT_MIN){
                intStr=INT_MIN+1;
                break;
            }
        }
        if(negativeFlag && intStr>0)
            intStr*=-1;
        
        return intStr;
    }


    /* simpler code */
    int myAtoi(string str) {

            unsigned int length = str.size();
            if(length==0)
                return 0;

            const char *charArray = str.c_str();
            unsigned short intValueOfChar=0;
            unsigned int index = 0;
            bool negativeFlag = 0;
            bool exceedFlag = 0;
            int returnValue = 0;

            //left trim
            while (charArray[index] == ' ')
                index++;

            if(charArray[index]=='-'){
                negativeFlag=1;
                index++;
            } else if(charArray[index]=='+'){
                index++;
            }

            while(index<length){
                intValueOfChar = charArray[index]-'0';
                //cout<<intValueOfChar<<endl;
                if(intValueOfChar<0 || intValueOfChar>9)
                    break;
                else{
                    if((returnValue>INT_MAX/10) || (returnValue==INT_MAX/10 && intValueOfChar>7) ){
                        exceedFlag=1;
                        returnValue=INT_MAX;
                        break;
                    } else {
                        returnValue*=10;
                        returnValue+=intValueOfChar;
                    }
                }
                index++;
            }

            if(negativeFlag){
                if(exceedFlag)
                    returnValue=INT_MIN;
                else
                    returnValue*=-1;
            }

            return returnValue;
        }
};


int main() {
	Solution obj;
	
	cout<<obj.myAtoi("-91283472332")<<endl;
	cout<<obj.myAtoi("2147483647")<<endl; //INT_MAX
	cout<<obj.myAtoi("-2147483648")<<endl; //INT_MIN
	cout<<obj.myAtoi("   -42")<<endl;
	cout<<obj.myAtoi("4193 with words")<<endl;
	cout<<obj.myAtoi("-1")<<endl;
	cout<<obj.myAtoi("+123123")<<endl;
	cout<<obj.myAtoi("+-2")<<endl;
}
