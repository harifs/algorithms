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
};