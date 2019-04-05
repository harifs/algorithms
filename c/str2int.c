#include<stdio.h>
#define SIZE 10
#define NULL '\0'
int main()
{
	int m=0;
	/*if(!malloc(n,sizeof(int)))
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
	free(n);*/
	char strofn[SIZE];
	memset(strofn,NULL,sizeof(strofn));
	printf("\nEnter the String:");
	scanf("%s",strofn);

	if(!str2int(&m,strofn))
		printf("\nInteger is: %d",m);
	else
		printf("\nFailed conversion");
	return 0;
}

int str2int(int *numbr,char str[])
{
	int i=0, isneg=0, num=0;
	if (str[0]=='-')
	{
		isneg=1;
		i=1;
	}
	while(str[i])
	{
		num*=10;
		num+=(str[i++]-'0');
	}
	if(isneg) num*=-1;
	printf("\nNum: %d",num);
	*numbr=num;
	return 0;
}