#include<stdio.h>
#define SIZE 10
void main(){
	int n;
	char strofn[SIZE];
	printf("\nEnter the number:");
	scanf("%d",&n);

	if(!int2str(n,strofn))
		printf("\nString is: %s",strofn);
	else
		printf("\nFailed conversion");

}

int int2str(int n,char str[])
{
	int i=0,j=0,isneg=0;
	char temp[SIZE];
	memset(temp,"\0",sizeof(temp));

	if(n<0)
	{
		isneg=1;
		n*=-1;
	}

	do
	{
		temp[i++]=(n%10)+'0';
		n/=10;
		//printf("\ntemp[%d]:%c : n=%d",i,temp[i],n);
	}
	while(n);

	if(isneg) str[j++]='-';

	while(i>0)
	{
		str[j++]=temp[--i];
		//printf("\nstr[%d]:%c",j,str[j]);
	}
	str[j]='\0';
	//printf("\nString is: %s",str);
	return 0;
}