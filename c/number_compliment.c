//number complement - 1

int factor(int n) {
    int i;
    unsigned long sum=0;
    if(n<=1) return 1;
    for(i=1;i<=n;i*=2) sum+=i;
    return sum;
}

int findComplement(int num) {
    unsigned long xor_factor=factor(num);
    printf("factor: %l",xor_factor);
    return(num^xor_factor);
}

//number complement - method 2 - faster
#include<math.h>
int findComplement(int num) {
    int log2num=log2(num)+1;
    int xor_factor=pow(2,(log2num))-1;
    printf("factor: %d",xor_factor);
    return(num^xor_factor);
}